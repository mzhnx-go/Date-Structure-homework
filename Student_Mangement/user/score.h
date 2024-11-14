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

    // 提供 operator== 函数
    bool operator==(const Score &other) const;

private:
    QString courseId;
    double finalExamScore;
    QList<double> unitTestList;
};

// 声明 qHash 函数
uint qHash(const Score &score, uint seed = 0);

#endif // SCORE_H
