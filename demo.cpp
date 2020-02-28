//
// Joseph McFarland
// 9072511679
// mcfarland3@wis.edu
// https://canvas.wisc.edu/courses/188843/files for slides
// Made in CLion with commits to GitHub
//

#include "SummarizeGrades.h"

/*
 * This function executes a test for SummarizeGrades.cpp by calling all
 * functions in order to create a properly formatted output file. Prints to
 * console after initial readGradeFile to ensure file was read correctly and
 * values were placed in correct locations.
 */
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


    cout << "Number of Students: " << numberOfStudents << endl;
    cout << "Number of Assignments: " << numberOfAssignments << endl;
    cout << "ID + Names + Scores: " << endl;
    for (auto nameItr : studentNames) {
        int studentID = nameItr.first;
        string name = nameItr.second.lastName + ", " + nameItr.second
                .firstName;
        cout << setw(0) << studentID << " " << name;

        for (auto idItr : studentScores) {
            if (idItr.first == studentID) {
                for (auto scoreItr : idItr.second) {
                    cout << " " << scoreItr;
                }
                cout << endl;
            }
        }
    }


    formatCaseOfNames(studentNames);

    computeTotalAndPercent(studentScores, total, percent);

    const string outputFilepath = "formatted.txt";
    writeFormattedGrades(outputFilepath, studentNames, total, percent);
}