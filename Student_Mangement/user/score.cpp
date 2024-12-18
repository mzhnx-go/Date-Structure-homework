#include "score.h"

Score::Score() : finalExamScore(0.0), unitTestList(QList<double>()) {}

Score::Score(const QString &studentId, const QString &courseId, double &finalScore, const QList<double> &unitTests)
    : studentId(studentId), courseId(courseId),  finalExamScore(finalScore), unitTestList(unitTests) {}

Score::Score(const QString &id, const QString &courseId)
{
    this->studentId = id;
    this->courseId = courseId;
    finalExamScore = -1.0;
}

Score::Score(const QString &id, const QString &courseId, double &finalScore)
{
    this->studentId = id;
    this->courseId = courseId;
    finalExamScore = finalScore;
}

Score::Score(const QString &id, const QString &courseId, const QList<double> &unitTests)
{
    this->studentId = id;
    this->courseId = courseId;
    this->unitTestList = unitTests;
    finalExamScore = -1;
}

void Score::setUnitTestList(QList<double> unitTestList)
{
    this->unitTestList = unitTestList;
}

void Score::setFinalExamScore(double finalExamScore)
{
    this->finalExamScore = finalExamScore;
}

