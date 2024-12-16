#include "show_optional_course.h"
#include "ui_show_optional_course.h"
show_optional_course::show_optional_course(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::show_optional_course)
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
    Utils::matchCourseAndOptionCourse(courses,optionCourses, mapCourses);
    return true;
}


void show_optional_course::onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected) {
    Q_UNUSED(deselected);

    // 获取当前选中的索引
    QModelIndexList selectedIndexes = ui->list_course->selectionModel()->selectedIndexes();
    int count = selectedIndexes.size();

    // 如果选择超过了4个，则移除最早的多余选择
    while (count > 4) {
        QModelIndex firstSelected = selectedIndexes.first();
        ui->list_course->selectionModel()->select(firstSelected, QItemSelectionModel::Deselect);
        selectedIndexes.removeFirst();
        --count;
    }

    // 更新保存的选中索引
    this->selectedIndexes.clear();
    for (const QModelIndex &index : selectedIndexes) {
        this->selectedIndexes.append(index.row());
    }
}
