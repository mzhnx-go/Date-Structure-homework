#ifndef SCORE_H
#define SCORE_H

#include <QString>
#include <QList>
#include <QHash>

class Score
{
public:
    Score();
    Score(const QString &id, const QString &courseId, double &finalScore, const QList<double> &unitTests);

    QString getStudentId() const { return studentId; }
    double getFinalExamScore() const { return finalExamScore; }
    QList<double> getUnitTestList() const { return unitTestList; }
    QString getCourseId() const {return courseId;}
private:
    QString studentId;
    QString courseId;
    double finalExamScore;
    QList<double> unitTestList;
};

#endif // SCORE_H
