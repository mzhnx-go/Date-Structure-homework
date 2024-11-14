#include "score.h"

Score::Score() : finalExamScore(0.0), unitTestList(QList<double>()) {}

Score::Score(const QString &id, double finalScore, const QList<double> &unitTests)
    : courseId(id), finalExamScore(finalScore), unitTestList(unitTests) {}

// 实现 operator== 函数
bool Score::operator==(const Score &other) const
{
    return courseId == other.courseId;
}

// 实现 qHash 函数
uint qHash(const Score &score, uint seed)
{
    return ::qHash(score.getCourseId(), seed);
}
