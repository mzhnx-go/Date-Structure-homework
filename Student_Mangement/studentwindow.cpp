 #include "studentwindow.h"
#include "ui_studentwindow.h"
#include <QTreeWidget>
#include <QApplication>
StudentWindow::StudentWindow(QWidget *parent,QString studentId)
    : QWidget(parent)
    , ui(new Ui::StudentWindow)
    ,_optionCourse(nullptr)
    ,studentId(studentId)
{
    ui->setupUi(this);
    initCurrentStudent();
    FileHandler::loadCourses(coursesFilePath, courses);
}

StudentWindow::~StudentWindow()
{
    delete ui;
}

void StudentWindow::setStudentId(QString studentId)
{
    this->studentId = studentId;
}

Student& StudentWindow::getCurrentStudent() {
    return currentStudent;
}

void StudentWindow::initCurrentStudent()
{
    QVector<Student> students;
    if(!FileHandler::loadStudent(stuFilePath, students)) {
        qWarning() << "ERROR IN void StudentWindow::initCurrentStudent(): 加载学生数据失败";
        return ;
    }
    for (const auto &student: students ) {
        if (studentId == student.getId()) {
            currentStudent = student;
            qDebug() << "currentStudent初始化成功";
            return;
        }
    }
    qDebug() << "currentStudent初始化失败";
}

void StudentWindow::on_exit_clicked()
{
     QApplication::quit();
}


void StudentWindow::on_show_course_clicked()
{
    if (!_optionCourse) {
        _optionCourse = new show_optional_course(this, getCurrentStudent());
    }
    _optionCourse->exec(); // 模态对话框
}

//查询所选课程
void StudentWindow::on_searchStu_clicked()
{
    // 获取当前学生的所有课程ID
    QSet<QString> currentStudentCourses = currentStudent.getCourses();
    QVector<Course> matchedCourses;

    // 根据课程ID找到对应的课程对象
    for (const auto &course : courses) {
        if (currentStudentCourses.contains(course.getCourseId())) {
            matchedCourses.append(course);
        }
    }

    // 设置表头
    QStringList header;
    header << "学号" << "姓名";
    for (int i = 0; i < matchedCourses.size(); ++i) {
        header << QString("所选课程%1").arg(i + 1);
    }
    ui->show_widget->setColumnCount(header.size());
    ui->show_widget->setHorizontalHeaderLabels(header);

    // 清除现有数据并插入新行
    ui->show_widget->clearContents();
    ui->show_widget->setRowCount(1);  // 假设每个学生只有一行

    // 插入学号和名字
    QTableWidgetItem *idItem = new QTableWidgetItem(currentStudent.getId());
    QTableWidgetItem *nameItem = new QTableWidgetItem(currentStudent.getName());

    // 设置单元格为只读
    idItem->setFlags(idItem->flags() & ~Qt::ItemIsEditable);
    nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);

    ui->show_widget->setItem(0, 0, idItem);
    ui->show_widget->setItem(0, 1, nameItem);

    // 插入所选课程，每个课程一个单独的列
    for (int i = 0; i < matchedCourses.size(); ++i) {
        QTableWidgetItem *courseItem = new QTableWidgetItem(matchedCourses[i].getCourseName());
        courseItem->setFlags(courseItem->flags() & ~Qt::ItemIsEditable);
        ui->show_widget->setItem(0, i + 2, courseItem);
    }

    // 确保表格占据整个窗口宽度
    ui->show_widget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 调整行高以适应内容
    ui->show_widget->resizeRowsToContents();

    // 确保表格内容不可编辑
    ui->show_widget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void StudentWindow::on_check_score_clicked()
{
    QString courseName = ui->input_name->text().trimmed();
    QVector<Score> scores;
    QString courseId = "";
    bool courseFound = false;

    // 加载成绩文件
    if (!FileHandler::loadScores(scoresFilePath, scores)) {
        qWarning() << "ERROR IN StudentWindow::on_check_score_clicked(): FileHandler::loadScores failed";
        QMessageBox::warning(this, "警告", "无法加载成绩文件");
        return;
    }

    // 查找课程ID
    for (const auto &course : courses) {
        if (courseName == course.getCourseName()) {
            courseId = course.getCourseId();
            courseFound = true;
            break;
        }
    }

    if (!courseFound) {
        QMessageBox::warning(this, "警告", "不存在此课程");
        return;
    }

    // 检查学生是否选择了该课程
    if (!currentStudent.getCourses().contains(courseId)) {
        QMessageBox::warning(this, "警告", "您未选择该课程");
        return;
    }

    // 查找当前学生的成绩记录
    Score currentScore;
    for (const auto &score : scores) {
        if (currentStudent.getId() == score.getStudentId() && courseId == score.getCourseId()) {
            currentScore = score;
            break;
        }
    }


    // 创建表格最大列数
    int maxUnitGrades = currentScore.getUnitTestList().size();
    QStringList header;
    header << "姓名" << "课程名";
    for (int i = 1; i <= maxUnitGrades; ++i) {
        header << QString("第%1次成绩").arg(i);
    }
    header << "期末成绩";

    // 设置表头
    ui->show_widget->setColumnCount(header.size());
    ui->show_widget->setHorizontalHeaderLabels(header);

    // 清除现有数据并插入新行
    ui->show_widget->clearContents();
    ui->show_widget->setRowCount(1);  // 假设每个查询结果只有一行

    int row = 0;

    // 插入学号和名字
    QTableWidgetItem *nameItem = new QTableWidgetItem(currentStudent.getName());
    QTableWidgetItem *courseNameItem = new QTableWidgetItem(courseName);

    // 设置单元格为只读
    nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
    courseNameItem->setFlags(courseNameItem->flags() & ~Qt::ItemIsEditable);

    ui->show_widget->setItem(row, 0, nameItem);
    ui->show_widget->setItem(row, 1, courseNameItem);

    // 插入单元测验成绩
    for (int i = 0; i < maxUnitGrades; ++i) {
        QString grade = i < currentScore.getUnitTestList().size() ?
                            QString::number(currentScore.getUnitTestList()[i]) :
                            "无";
        QTableWidgetItem *gradeItem = new QTableWidgetItem(grade);
        gradeItem->setFlags(gradeItem->flags() & ~Qt::ItemIsEditable);
        ui->show_widget->setItem(row, i + 2, gradeItem);
    }

    // 插入期末成绩
    QTableWidgetItem *finalGradeItem = new QTableWidgetItem(
        !currentScore.getFinalExamScore() < 0 ?
            QString::number(currentScore.getFinalExamScore()) :
            "无"
        );
    finalGradeItem->setFlags(finalGradeItem->flags() & ~Qt::ItemIsEditable);
    ui->show_widget->setItem(row, 2 + maxUnitGrades, finalGradeItem);

    // 确保表格占据整个窗口宽度
    ui->show_widget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 调整行高以适应内容
    ui->show_widget->resizeRowsToContents();

    // 确保表格内容不可编辑
    ui->show_widget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}




void StudentWindow::on_cancel_course_clicked()
{
    if (!_cancelCourse) {
        _cancelCourse = std::make_unique<cancel_course>(this, getCurrentStudent());
    } else {
        // 如果对话框已经存在，则先刷新数据
            _cancelCourse->refreshData();
    }

    if (_cancelCourse) {
        if (_cancelCourse->exec() == QDialog::Accepted) {
            // 用户确认了对话框，可以在此处处理确认逻辑
            qDebug() << "用户确认了取消课程对话框";
        } else {
            // 用户取消了对话框，可以在此处处理取消逻辑
            qDebug() << "用户取消了取消课程对话框";
        }
    } else {
        qCritical() << "无法创建取消课程对话框";
    }
}

void StudentWindow::loadData() {
    // 在这里放置所有需要重新加载的数据逻辑
    // 例如，从文件、数据库或其他来源加载数据，并更新UI元素
    qDebug() << "正在重新加载数据...";
    initCurrentStudent(); // 如果需要重新加载学生信息
}



