#include "page_modify.h"
#include "ui_page_modify.h"

bool isPureDigits(const QString &str) {
    QRegularExpression re("^[0-9]+$");
    return re.match(str).hasMatch();
}

void page_modify::closeEvent(QCloseEvent *event) {
    // 清除表格内容
    ui->modi_tab->clearContents();
    ui->modi_tab->setRowCount(0);

    // 清除其他输入框的内容
    ui->stu_text->clear();
    ui->cou_text->clear();

    // 接受关闭事件
    event->accept();
}

page_modify::page_modify(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::page_modify)
{
    ui->setupUi(this);
    connect(ui->modi_tab, &QTableWidget::itemChanged, this, &page_modify::handleItemChanged);
}

page_modify::~page_modify()
{
    delete ui;
}


void page_modify::insertRowData(int row, const QString &courseName, const QString &studentName,
                                const QString &className, const QList<double> &unitGrades, double finalGrade,
                                bool editable, const QString &type)
{
    // 插入类型标识（不可编辑）
    QTableWidgetItem *typeItem = new QTableWidgetItem(type);
    typeItem->setFlags(typeItem->flags() & ~Qt::ItemIsEditable);
    ui->modi_tab->setItem(row, 0, typeItem);

    // 如果是“请在此处修改成绩”行，设置第一列背景颜色为红色，并设置文本颜色为白色
    if (type == "请在此处修改成绩") {
        typeItem->setBackground(Qt::red);
        typeItem->setData(Qt::ForegroundRole, QVariant(QBrush(Qt::white)));
    }

    // 插入课程名、学生名、班级信息（不可编辑）
    QTableWidgetItem *courseItem = new QTableWidgetItem(courseName);
    courseItem->setFlags(courseItem->flags() & ~Qt::ItemIsEditable);
    ui->modi_tab->setItem(row, 1, courseItem);

    QTableWidgetItem *studentItem = new QTableWidgetItem(studentName);
    studentItem->setFlags(studentItem->flags() & ~Qt::ItemIsEditable);
    ui->modi_tab->setItem(row, 2, studentItem);

    QTableWidgetItem *classItem = new QTableWidgetItem(className);
    classItem->setFlags(classItem->flags() & ~Qt::ItemIsEditable);
    ui->modi_tab->setItem(row, 3, classItem);

    int col = 4;
    for (int i = 0; i < 6; ++i) { // 假设最多有六次单元测验
        QTableWidgetItem *item;
        if (i < unitGrades.size() && unitGrades.at(i) >= 0.0 && unitGrades.at(i) <= 100.0) {
            item = new QTableWidgetItem(QString::number(unitGrades.at(i), 'f', 2));
        } else {
            item = new QTableWidgetItem(editable ? "0.00" : "无");
        }
        item->setFlags(editable ? item->flags() | Qt::ItemIsEditable : item->flags() & ~Qt::ItemIsEditable);
        ui->modi_tab->setItem(row, col++, item);
    }

    // 处理期末成绩
    QTableWidgetItem *finalGradeItem;
    if (finalGrade >= 0.0 && finalGrade <= 100.0) {
        finalGradeItem = new QTableWidgetItem(QString::number(finalGrade, 'f', 2));
    } else {
        finalGradeItem = new QTableWidgetItem(editable ? "0.00" : "无");
    }
    finalGradeItem->setFlags(editable ? finalGradeItem->flags() | Qt::ItemIsEditable : finalGradeItem->flags() & ~Qt::ItemIsEditable);
    ui->modi_tab->setItem(row, col, finalGradeItem);
}

void page_modify::handleItemChanged(QTableWidgetItem *item)
{
    if (m_loading || !item || item->column() < 4 || item->column() >= ui->modi_tab->columnCount()) return;

    // 获取旧值（如果需要的话）
    QString oldText = item->data(Qt::EditRole).toString();

    bool ok;
    double value = item->text().toDouble(&ok);

    // 如果转换失败或者值不在0到100之间
    if (!ok || value < 0.0 || value > (100.0) ) {
        QMessageBox::warning(this, tr("无效输入"), tr("请输入0到100之间的数字"));

        if (oldText.isEmpty()) {
            item->setText("0.00");
        } else {
            item->setText(oldText);
        }
    } else {
        // 设置为两位小数
        item->setText(QString::number(value, 'f', 2));
    }
}
void page_modify::on_pushButton_3_clicked()
{
    this->close();
}


void page_modify::on_show_button_clicked()
{
    m_loading = true;
    QString studentInfo = ui->stu_text->text().trimmed();
    QString courseInfo = ui->cou_text->text().trimmed();
    // 清除表格内容
    ui->modi_tab->clearContents();
    ui->modi_tab->setRowCount(0);
    init(); //重新加载数据

    if (!FileHandler::loadStudent(stuFilePath, students)) {
        qWarning() << "无法打开学生数据";
        QMessageBox::warning(this, "警告", "无法打开学生数据文件");
        return;
    }
    if (!FileHandler::loadCourses(coursesFilePath, courses)) {
        qWarning() << "无法打开课程数据";
        QMessageBox::warning(this, "警告", "无法打开课程数据文件");
        return;
    }
    if (!FileHandler::loadScores(scoresFilePath, scores)) {
        qWarning() << "无法打开成绩数据";
        QMessageBox::warning(this, "警告", "无法打开成绩数据文件");
        return;
    }

    // 查找匹配的学生和课程信息
    Student matchedStudent;
    Course matchedCourse;
    Score matchedScore;

    bool isMatch = false;
    for (const auto &student : students) {
        if (isPureDigits(studentInfo) && student.getId() == studentInfo ||
            student.getName() == studentInfo) {
            matchedStudent = student;
            break;
        }
    }

    for (const auto &course : courses) {
        if (isPureDigits(courseInfo) && course.getCourseId() == courseInfo ||
            !isPureDigits(courseInfo) && course.getCourseName() == courseInfo) {
            matchedCourse = course;
            break;
        }
    }

    for (const auto &score : scores) {
        if (score.getStudentId() == matchedStudent.getId() &&
            score.getCourseId() == matchedCourse.getCourseId()) {
            matchedScore = score;
            isMatch = true;
            break;
        }
    }

    if (!isMatch) {
        QMessageBox::information(this, "提示", "不存在与输入信息匹配的数据");
        return;
    }

    // 设置表头
    QStringList header;
    header << "类型" << "课程名" << "姓名" << "班级";
    const int maxUnitGrades = matchedScore.getUnitTestList().size();
    for (int i = 1; i <= 6; ++i) { // 固定六次单元测验
        header << QString("第%1次成绩").arg(i);
    }
    header << "期末成绩";

    ui->modi_tab->setColumnCount(header.size());
    ui->modi_tab->setHorizontalHeaderLabels(header);

    // 插入原数据行
    int row = ui->modi_tab->rowCount();
    ui->modi_tab->insertRow(row);
    insertRowData(row, matchedCourse.getCourseName(), matchedStudent.getName(),
                  matchedStudent.getClassInfo(), matchedScore.getUnitTestList(),
                  matchedScore.getFinalExamScore(), false, "原成绩");

    // 插入可编辑数据行
    row = ui->modi_tab->rowCount();
    ui->modi_tab->insertRow(row);
    insertRowData(row, matchedCourse.getCourseName(), matchedStudent.getName(),
                  matchedStudent.getClassInfo(), matchedScore.getUnitTestList(),
                  matchedScore.getFinalExamScore(), true, "请在此处修改成绩");

    // 设置单元格为只读或可编辑
    for (int col = 0; col < ui->modi_tab->columnCount(); ++col) {
        QTableWidgetItem *item = ui->modi_tab->item(0, col);
        if (item) { // 确保 item 不为空
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        }
    }
    ui->modi_tab->resizeColumnsToContents();

    m_loading = false;
}


void page_modify::on_sure_button_clicked()
{
    if (ui->modi_tab->rowCount() < 2) {
        QMessageBox::warning(this, tr("警告"), tr("没有足够的数据行"));
        return;
    }

    QTableWidgetItem *studentItem = ui->modi_tab->item(0, 2);
    QTableWidgetItem *courseItem = ui->modi_tab->item(0, 1);

    if (!studentItem || !courseItem) {
        QMessageBox::warning(this, tr("警告"), tr("缺少必要的课程信息或课程信息"));
        return;
    }

    QString studentName = studentItem->text();
    QString courseName = courseItem->text();
    Student matchedStudent;
    Course matchedCourse;
    Score *matchedScore = nullptr;
    bool findStudent = false;
    bool findCourse = false;

    for (const auto &student: students) {
        if (studentName == student.getName()) {
            matchedStudent = student;
            findStudent = true;
            break;
        }
    }

    for (const auto &course: courses) {
        if (courseName == course.getCourseName()) {
            matchedCourse = course;
            findCourse = true;
            break;
        }
    }

    if (!findStudent || !findCourse) {
        qWarning() << "ERROR IN sure_button: 出现不匹配的数据";
        return;
    }

    for (auto &score: scores) {
        if (score.getStudentId() == matchedStudent.getId() && score.getCourseId() == matchedCourse.getCourseId()) {
            matchedScore = &score;
            break;
        }
    }

    if (matchedScore == nullptr) {
        qWarning() << "没有匹配的数据";
        return;
    }

    // 遍历成绩列，收集成绩数据
    QList<double> unitGrades;
    double finalGrade = 0.0;

    for (int col = 4; col < ui->modi_tab->columnCount() - 1; ++col) { // 假设最后一列是期末成绩
        QTableWidgetItem *item = ui->modi_tab->item(1, col); // 取第二行（修改后的数据）
        if (item) {
            QString text = item->text().trimmed();
            if (text == "无") {
                QMessageBox::warning(this, tr("警告"), tr("请输入有效的成绩"));
                return;
            }
            bool ok;
            double value = text.toDouble(&ok);

            if (!ok || value < 0.0 || value > 100.0) {
                QMessageBox::warning(this, tr("警告"), tr("请输入0到100之间的数字"));
                return;
            }

            unitGrades.append(value);
        } else {
            QMessageBox::warning(this, tr("警告"), tr("缺少成绩数据"));
            return;
        }
    }

    // 获取期末成绩
    QTableWidgetItem *finalGradeItem = ui->modi_tab->item(1, ui->modi_tab->columnCount() - 1);
    if (finalGradeItem) {
        QString text = finalGradeItem->text().trimmed();
        if (text == "无") {
            QMessageBox::warning(this, tr("警告"), tr("请输入有效的期末成绩"));
            return;
        }
        bool ok;
        finalGrade = text.toDouble(&ok);

        if (!ok || finalGrade < 0.0 || finalGrade > 100.0) {
            QMessageBox::warning(this, tr("警告"), tr("请输入0到100之间的数字"));
            return;
        }
    } else {
        QMessageBox::warning(this, tr("警告"), tr("缺少期末成绩数据"));
        return;
    }

    // 更新 Score 对象的成绩
    matchedScore->setFinalExamScore(finalGrade);
    matchedScore->setUnitTestList(unitGrades);

    // 保存更改
    if (!FileHandler::saveScoreFiles(scores, scoresFilePath)) {
        QMessageBox::warning(this, tr("警告"), tr("修改文件失败"));
        return;
    }

    QMessageBox::information(this, "提示", "修改成功");
    init();
    this->close();
}

void page_modify::init()
{
    students.clear();
    courses.clear();
    scores.clear();
}

