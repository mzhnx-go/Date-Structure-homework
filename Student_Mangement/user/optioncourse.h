#ifndef OPTIONCOURSE_H
#define OPTIONCOURSE_H
#include <QString>
class OptionCourse
{
public:
    OptionCourse(QString courseId, int lastCourseNumber);
    OptionCourse() = default;
    QString getCourseId() const;
    int getlastCourseNumber() const;
    void setLastCourseNumber(const int &newNumber);
private:
    QString courseId;
    int lastCourseNumber; //剩余课程数量
};

#endif // OPTIONCOURSE_H
