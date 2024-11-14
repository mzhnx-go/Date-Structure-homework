#ifndef SCORE_H
#define SCORE_H

#include <QString>
#include <QList>
#include <QHash>

class Score
{
public:
    Score();
    Score(const QString &id, double finalScore, const QList<double> &unitTests);

    QString getCourseId() const { return courseId; }
    double getFinalExamScore() const { return finalExamScore; }
    QList<double> getUnitTestList() const { return unitTestList; }

private:
    QString courseId;
    double finalExamScore;
    QList<double> unitTestList;
};

#endif // SCORE_H
