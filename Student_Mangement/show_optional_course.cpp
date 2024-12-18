#include "show_optional_course.h"
#include "ui_show_optional_course.h"
#include "studentwindow.h"
show_optional_course::show_optional_course(QWidget *parent,Student &student)
    : QDialog(parent)
    , ui(new Ui::show_optional_course)
    , currentStudent(student)
{
    ui->setupUi(this);
    model = new QStandardItemModel(this); // 确保在这里初始化 model
    ui->list_course->setModel(model);     // 设置模型到视图
    ui->list_course->setSelectionMode(QAbstractItemView::MultiSelection);

    // 显式连接 selectionChanged 信号到 onSelectionChanged 槽函数
    connect(ui->list_course->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &show_optional_course::onSelectionChanged);

    qDebug() << "Selection mode:" << ui->list_course->selectionMode(); // 调试信息
    loadCourses();
}

show_optional_course::~show_optional_course()
{
    delete ui;
}

//取消选择按钮
void show_optional_course::on_pushButton_2_clicked()
{
    this->close();
}

void show_optional_course::loadCourses() {

    //每次加载课程前重新加载数据
    if (!initDatas()) {
        qWarning() << "ERROR IN show_optional_course::loadCourses(): 初始化数据失败";
        return;
    }

    model->clear();  // 清除现有内容

    for (auto it = mapCourses.begin(); it != mapCourses.end(); ++it) {
        const QPair<Course, OptionCourse> &pair = it.value();
        const Course &course = pair.first;
        const OptionCourse &optionCourse = pair.second;

        // 处理 course 和 optionCourse
        QStandardItem *item = new QStandardItem(QString("课程号:%1 课程名:%2 剩余数量:%3")
                                                    .arg(course.getCourseId())
                                                    .arg(course.getCourseName())
                                                    .arg(optionCourse.getlastCourseNumber()));
        model->appendRow(item);
    }
}

void show_optional_course::updateStudents()
{
    if (studentHash.contains(currentStudent.getId())) {
        studentHash[currentStudent.getId()] = currentStudent;
    } else {
        qWarning() << "ERROR: Student ID not found in the list";
    }

    // 将 studentHash 转换回 students 向量
    students.clear();
    for (auto it = studentHash.begin(); it != studentHash.end(); ++it) {
        students.append(it.value());
    }
}

bool show_optional_course::initDatas()
{
    if (!FileHandler::loadCourses(coursesFilePath, courses)) {
        qWarning() << "ERROR IN show_optional_course::initDatas,loadCourses";
        return false;
    }
    if (!FileHandler::loadOptionalCourse(optionCourseFilePath, optionCourses)) {
        qWarning() << "ERROR IN show_optional_course::initDatas,loadOptionalCourse";
        return false;
    }

    if (!FileHandler::loadScores(scoresFilePath,scores)) {
        qWarning() << "ERROR IN show_optional_course::initDatas,loadScores";
    }

    if (!FileHandler::loadStudent(stuFilePath, students)) {
         qWarning() << "ERROR IN show_optional_course::initDatas,loadStudent";
    }

    //构建哈希表
    for (const auto &student : students) {
        studentHash[student.getId()] = student;
    }

    Utils::matchCourseAndOptionCourse(courses,optionCourses, mapCourses);
    return true;
}



/*TODO::测试课程满了的条件，能否成功写入文件
 * 修改 Utils::matchCourseAndOptionCourse(courses,optionCourses, mapCourses)
 * 如果课程数已经为零就不需要加入到map中
 * 1.将确定后的数据保存在currentStudent中
 * 2.修改Student表，修改score表,修改OptionCourse表
 */
void show_optional_course::on_sure_choice_clicked()
{
    // 获取当前选中的索引
    QModelIndexList selectedIndexes = ui->list_course->selectionModel()->selectedIndexes();

    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选择要确认的课程！");
        return;
    }

    for (const QModelIndex &index : selectedIndexes) {
        QString courseId = mapCourses.keys().at(index.row());
        QPair<Course, OptionCourse> coursePair = mapCourses.value(courseId);
        Course &course = coursePair.first;
        OptionCourse &optionCourse = coursePair.second;

        // 检查学生是否已经选择了该课程
        if (currentStudent.hasSelectedCourse(course)) { // 假设 currentStudent 有此方法
            QMessageBox::warning(this, "警告", QString("您已经选择了课程: %1").arg(course.getCourseName()));
            continue;
        }

        // 更新可选课程的数量
        if (optionCourse.getlastCourseNumber() <= 0) {
            QMessageBox::information(this,"提示","当前课程人数已满，请选择其他课程");
            continue;
        }

        // 将课程添加到当前学生的选择列表中
        currentStudent.addCourse(course.getCourseId());

        int newLastCourseNumber = optionCourse.getlastCourseNumber() - 1;
        optionCourse.setLastCourseNumber(newLastCourseNumber);

        //加入新数据
        //TODO::完成学生数据修改
        Score newscore = Score(currentStudent.getId(), course.getCourseId());
        scores.append(newscore);
        updateStudents();


        // 如果剩余数量为0，从 map 中移除该课程
        if (newLastCourseNumber == 0) {
            mapCourses.remove(courseId);
        }

        // 更新模型以反映剩余数量的变化
        model->item(index.row())->setText(
            QString("课程号:%1 课程名:%2 剩余数量:%3")
                .arg(course.getCourseId())
                .arg(course.getCourseName())
                .arg(newLastCourseNumber)
            );
    }

    //TODO::完成文件保存函数
    // // 保存更改到文件

    if (!FileHandler::saveOptionalCourse(optionCourseFilePath, optionCourses)) {
        qWarning() << "ERROR IN show_optional_course::on_sure_choice_clicked, saveOptionalCourse";
    }

    if (!FileHandler::saveScoreFiles(scores, scoresFilePath)) {
        qWarning() << "ERROR IN show_optional_course::on_sure_choice_clicked, saveScoreFiles";
    }

    if (!FileHandler::saveStudentFile(students, stuFilePath)) {
        qWarning() << "ERROR IN show_optional_course::on_sure_choice_clicked, saveStudentFile";
    }


    //TODO::调试完后删除下列语句
    //Debug打印数据部分
    for (const auto &score: scores) {
        qDebug() << score.getStudentId() << " " << score.getCourseId() << " " << score.getUnitTestList();
    }

    // 关闭对话框
    this->close();

}

void show_optional_course::onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected) {
    Q_UNUSED(deselected);

    // 获取当前选中的索引
    QModelIndexList selectedIndexes = ui->list_course->selectionModel()->selectedIndexes();

    // 计算当前学生已经选择的课程数量加上本次新增的选择数量
    int currentSelectedCoursesCount = currentStudent.getSelectedCoursesCount(); // 假设 Student 类有此方法
    int newSelectionCount = selectedIndexes.size();
    static bool limitReached = false; // 引入标志变量

    // 如果总选择数量将超过4，则移除多余的选中项
    while (currentSelectedCoursesCount + newSelectionCount > 4) {
        if (!selectedIndexes.isEmpty()) {
            QModelIndex firstSelected = selectedIndexes.first();
            ui->list_course->selectionModel()->select(firstSelected, QItemSelectionModel::Deselect);
            selectedIndexes.removeFirst();
            --newSelectionCount;
        }
    }

    // 更新保存的选中索引
    this->selectedIndexes.clear();
    for (const QModelIndex &index : selectedIndexes) {
        this->selectedIndexes.append(index.row());
    }

    // 检查是否达到了选择课程的数量限制，并且只提示一次
    if (currentSelectedCoursesCount + newSelectionCount > 4 && !limitReached) {
        QMessageBox::information(this, "提示", "您已经选择了4门课程，不能再选择了！");
        limitReached = true;
    } else if (currentSelectedCoursesCount + newSelectionCount < 4) {
        limitReached = false; // 如果用户取消了一些选择，允许再次选择
    }
}
