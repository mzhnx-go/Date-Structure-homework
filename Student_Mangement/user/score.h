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
    Score (const QString &id, const QString &courseId); //无成绩
    Score (const QString &id, const QString &courseId, double &finalScore); //只有期末成绩
    Score (const QString &id, const QString &courseId, const QList<double> &unitTests);

    QString getStudentId() const;
    double getFinalExamScore() const;
    QList<double> getUnitTestList() const;
    QString getCourseId() const;
    void setUnitTestList(QList<double> unitTestList);
    void setFinalExamScore(double finalExamScore);

private:
    QString studentId;
    QString courseId;
    double finalExamScore;
    QList<double> unitTestList;
};

inline QString Score::getStudentId() const { return studentId; }

inline double Score::getFinalExamScore() const { return finalExamScore; }

inline QList<double> Score::getUnitTestList() const { return unitTestList; }

inline QString Score::getCourseId() const {return courseId;}

#endif // SCORE_H
