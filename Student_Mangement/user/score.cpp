#include "score.h"

Score::Score() : finalExamScore(0.0), unitTestList(QList<double>()) {}

Score::Score(const QString &studentId, const QString &courseId, double &finalScore, const QList<double> &unitTests)
    : studentId(studentId), courseId(courseId),  finalExamScore(finalScore), unitTestList(unitTests) {}

void Score::setUnitTestList(QList<double> unitTestList)
{
    this->unitTestList = unitTestList;
}

void Score::setFinalExamScore(double finalExamScore)
{
    this->finalExamScore = finalExamScore;
}

