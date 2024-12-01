#ifndef PAGE_MODIFY_H
#define PAGE_MODIFY_H

#include <QDialog>
#include "global.h"
#include "user/tableattribute.h"
#include "filehandler.h"
#include "utils.h"
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>
#include <QHash>
#include <QPair>
#include <QMessageBox>
#include <QCloseEvent>
#include <QValidator>
#include <QTableWidgetItem>
namespace Ui {
class page_modify;
}

class page_modify : public QDialog
{
    Q_OBJECT

public:
    explicit page_modify(QWidget *parent = nullptr);
    ~page_modify();
    void insertRowData(int row, const QString &courseName, const QString &studentName,
                       const QString &className, const QList<double> &unitGrades, double finalGrade,
                       bool editable, const QString &type);
protected:
    void closeEvent(QCloseEvent *event) override; // 声明 closeEvent 方法

private slots:
    void on_pushButton_3_clicked();
    void handleItemChanged(QTableWidgetItem *item);
    void on_show_button_clicked();

private:
    Ui::page_modify *ui;
};

#endif // PAGE_MODIFY_H
