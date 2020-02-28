//
// Joseph McFarland
// 9072511679
// mcfarland3@wis.edu
// https://canvas.wisc.edu/courses/188843/files for slides
// https://www.geeksforgeeks.org for understanding (mostly for setprecision)
// Made in CLion with commits to GitHub
//

#include "SummarizeGrades.h"

void readGradeFile(const string inputFilepath, int *numberOfStudents, int
*numberOfAssignments, map<int, Name> &studentNames, map<int, vector<int>>
&studentScores) {
    ifstream fileReader;
    fileReader.open(inputFilepath);
    string currentWord = "";

    fileReader >> currentWord;
    if (currentWord == "number_of_students") {
        fileReader >> *numberOfStudents;
    }

    fileReader >> currentWord;
    if (currentWord == "number_of_assignments") {
        fileReader >> *numberOfAssignments;
    }

    for (int i = 0; i < *numberOfAssignments + 3; ++i) {
        fileReader >> currentWord;
    }

    int studentNumber = 00000;
    Name name;
    vector<int> scores;
    int score = 0;
    for (int i = 0; i <= *numberOfStudents; ++i) {
        fileReader >> studentNumber;
        fileReader >> name.firstName;
        fileReader >> name.lastName;
        for (int j = 0; j < *numberOfAssignments; ++j) {
            fileReader >> score;
            scores.push_back(score);
        }
        studentNames.insert(pair<int, Name>(studentNumber, name));
        studentScores.insert(pair<int, vector<int>>(studentNumber, scores));
        scores.clear();
    }

    fileReader.close();
}

void formatCaseOfNames(map<int, Name> &names) {
    for (auto itr = names.begin(); itr != names.end(); ++itr) {

        string name = itr->second.firstName;
        int nameLength = name.length();
        for (int i = 0; i < nameLength; ++i) {
            if (i == 0 && (name[i]>='a' && name[i]<='z')) {
                name[i] = name[i] - 32;
            } else if(i != 0 && (name[i]>='A' && name[i]<='Z'))
                name[i] = name[i] + 32;
        }
        itr->second.firstName = name;

        name = itr->second.lastName;
        nameLength = name.length();
        for (int i = 0; i < nameLength; ++i) {
            if (i == 0 and (name[i]>='a' && name[i]<='z'))
                name[i] = name[i] - 32;
            else if(i != 0 && (name[i]>='A' && name[i]<='Z'))
                name[i] = name[i] + 32;
        }
        itr->second.lastName = name;
    }
}

void computeTotalAndPercent(map<int, vector<int>> &scores,map<int, int>
        &total,  map<int, float> &percent) {
    for (auto studentItr : scores) {
        int score = 0;
        for (auto scoreItr : studentItr.second) {
            score += scoreItr;
        }

        float totalScore = score;
        float maxScore = studentItr.second.size() * 10;
        float scorePercent = totalScore*100 / maxScore;
        if (scorePercent > 100)
            scorePercent = 100;
        int studentID = studentItr.first;
        total.insert(pair<int, int>(studentID, totalScore));
        percent.insert(pair<int, float>(studentID, scorePercent));
    }
}

void writeFormattedGrades(const string outputFilepath,map<int, Name> &names,
        map<int, int> &total,map<int, float> &percent) {
    ofstream fileWriter (outputFilepath);

    for (auto nameItr : names) {
        int studentID = nameItr.first;
        string name = nameItr.second.lastName + ", " + nameItr.second
                .firstName;
        fileWriter << setw(0) << name;

        for (auto totalItr : total) {
            if (totalItr.first == studentID) {
                int space = 22 - name.length();
                fileWriter << setw(space) << totalItr.second;
            }
        }

        for (auto percentItr : percent) {
            if (percentItr.first == studentID) {
                fileWriter << setw(7) << fixed << setprecision(1)
                << percentItr.second << endl;
            }
        }
    }

    fileWriter.close();
}
