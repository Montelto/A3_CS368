//
// Created by Joseph McFarland on 25-Feb-20.
//

#include "SummarizeGrades.h"

int main() {

    static int numberOfStudents;
    static int numberOfAssignments;
    map<int, Name> studentNames;
    map<int, vector<int>> studentScores;
    map<int, int> total;
    map<int, float> percent;

    const string inputFilepath = "grades.txt";
    readGradeFile(inputFilepath, &numberOfStudents, &numberOfAssignments,
                  studentNames, studentScores);

    formatCaseOfNames(studentNames);

    computeTotalAndPercent(studentScores, total, percent);

    const string outputFilepath = "formatted.txt";
    writeFormattedGrades(outputFilepath, studentNames, total, percent);
}