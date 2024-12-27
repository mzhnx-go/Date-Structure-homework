#include "cancel_course.h"
#include "ui_cancel_course.h"

cancel_course::cancel_course(QWidget *parent, Student &student)
    : QDialog(parent)
    , ui(new Ui::cancel_course)
    , currentStudent(student)
    , model(new QStandardItemModel(this))
{
    ui->setupUi(this);
    ui->cancel_view->setModel(model); // 设置模型到视图
    ui->cancel_view->setSelectionMode(QAbstractItemView::SingleSelection);

    // 连接 selectionChanged 信号到槽函数
    connect(ui->cancel_view->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &cancel_course::onSelectionChanged);
    FileHandler::loadCourses(coursesFilePath, courses);
    loadSelectedCourses();
}

cancel_course::~cancel_course()
{
    delete ui;
}


void cancel_course::loadSelectedCourses() {
    qDebug() << "loadSelectedCourses";
    model->clear(); // 清除现有内容
    for (const auto &course : courses) {
        // 假设有一个方法可以获取课程名
        if (currentStudent.getCourses().contains(course.getCourseId())) {
            qDebug() << "contains";
        QStandardItem *item = new QStandardItem(QString("课程号:%1 课程名:%2").arg(course.getCourseId()).arg(course.getCourseName()));
        item->setData(course.getCourseId(), Qt::UserRole); // 存储课程ID作为用户数据
        model->appendRow(item);
        }
    }
    qDebug() << currentStudent.getCourses();
}

void cancel_course::initData()
{
    scores.clear();
    optionCourses.clear();
    students.clear();
    if(FileHandler::loadScores(scoresFilePath, scores)) {
        qWarning() << "cancel_course::initData(): 加载成绩数据失败";
    }
    if (FileHandler:: loadOptionalCourse(optionCourseFilePath, optionCourses)) {
        qWarning() << "cancel_course::initData(): 加载可选课程数据失败";
    }
    if (FileHandler::loadStudent(stuFilePath, students)) {
        qWarning() << "cancel_course::initData(): 加载学生数据失败";
    }
}


void cancel_course::onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{

}


void cancel_course::on_cancel_choice_clicked()
{
    this->close();
}

//确定退选
void cancel_course::on_sure_choice_clicked()
{
    QModelIndex selectedIndex = ui->cancel_view->selectionModel()->currentIndex();

    if (!selectedIndex.isValid()) {
        QMessageBox::information(this, tr("提示"), tr("请选择要退选的课程"));
        return;
    }

    QString courseId = selectedIndex.data(Qt::UserRole).toString();

    initData();
    bool hasValidScore = false;
    // 检查是否有成绩

    for (auto i = 0; i < scores.size(); i++) {
        if (currentStudent.getId() == scores[i].getStudentId() && currentStudent.getCourses().contains(courseId) && scores[i].getCourseId() == courseId) {
            if (scores[i].getFinalExamScore() < 0 || scores[i].getUnitTestList().isEmpty()) {
                //删除全部成绩
                scores.remove(i);
            }
            else {
                //保留成绩
                hasValidScore = true;
            }
        }
    }

    // auto it = scores.begin();
    // while (it != scores.end()) {
    //     if (currentStudent.getId() == it->getStudentId() && it->getCourseId() == courseId) {
    //         // 如果成绩无效（finalExamScore < 0 或者 unitTestList 中有 < 0 的值），则允许退选并更新成绩
    //         if (it->getFinalExamScore() < 0 || std::any_of(it->getUnitTestList().begin(), it->getUnitTestList().end(), [](double score) { return score < 0; })) {
    //             it->setFinalExamScore(-1); // 设置期末成绩为 -1 表示无效
    //             it->setUnitTestList(QList<double>()); // 清空单元测试成绩列表
    //             hasValidScore = true;
    //             ++it; // 继续检查下一个元素
    //         } else {
    //             hasValidScore = false;
    //             break; // 存在有效成绩，不允许退选
    //         }
    //     } else {
    //         ++it; // 只有在不处理当前元素时才前进迭代器
    //     }
    // }
    if (hasValidScore) {
        QMessageBox::warning(this, tr("警告"), tr("您已经为课程 %1 获得了成绩，无法退选").arg(courseId));
        return;
    }
        // 更新
        currentStudent.removeCourse(courseId); // 移除学生课程
        for (auto &optionCourse : optionCourses) {
            if (optionCourse.getCourseId() == courseId) {
                optionCourse.setLastCourseNumber(optionCourse.getlastCourseNumber() + 1);
                break;
            }
        }

        for (auto &student : students) {
            if (student.getId() == currentStudent.getId()) {
                student.setCourse(currentStudent.getCourses()); // 使用 currentStudent 的最新课程列表
                break;
            }
        }


        // 保存更改到文件
        FileHandler::saveStudentFile(students, stuFilePath);
        FileHandler::saveOptionalCourse(optionCourseFilePath, optionCourses);
        FileHandler::saveScoreFiles(scores, scoresFilePath);

        // 刷新显示
        refreshData();


        QMessageBox::information(this, tr("提示"), tr("退选课程成功"));
        return;
}

void cancel_course::refreshData() {
    qDebug() << "Refreshing data...";
    loadSelectedCourses();
}
