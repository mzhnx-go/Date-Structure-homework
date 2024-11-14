#include "score.h"

Score::Score() : finalExamScore(0.0), unitTestList(QList<double>()) {}

Score::Score(const QString &id, double finalScore, const QList<double> &unitTests)
    : courseId(id), finalExamScore(finalScore), unitTestList(unitTests) {}

