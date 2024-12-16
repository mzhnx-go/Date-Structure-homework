#include "optioncourse.h"

/*    QString CourseId;
    int lastCourseNumber;*/
OptionCourse::OptionCourse(QString courseId, int lastCourseNumber)
{
    this->courseId = courseId;
    this->lastCourseNumber = lastCourseNumber;
}
 QString OptionCourse::getCourseId() const
{
    return courseId;
}
 int OptionCourse::getlastCourseNumber() const
{
    return lastCourseNumber;
}
