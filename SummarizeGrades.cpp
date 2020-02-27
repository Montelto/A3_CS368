#include "SummarizeGrades.h"

void readGradeFile(const string inputFilepath, int *numberOfStudents, int
*numberOfAssignments, map<int, Name> &studentNames, map<int, vector<int>>
&studentScores) {
    ifstream fileReader (inputFilepath);
    string currentWord = "";
    fileReader >> currentWord;
    if (currentWord == "number_of_students") {
        fileReader >> *numberOfStudents;
    }
    fileReader >> currentWord;
    if (currentWord == "number_of_assignments") {
        fileReader >> *numberOfAssignments;
    }
    int studentNumber;
    Name name;
    vector<int> scores;
    int score;
    for (int i = 0; i <= *numberOfStudents; ++i) {
        studentNumber = 00000;
        if (i != 0) {
            fileReader >> studentNumber;
        }
        fileReader >> name.first_name;
        fileReader >> name.last_name;
        for (int j = 0; j < *numberOfAssignments; ++j) {
            fileReader >> score;
            scores.push_back(score);
        }
        studentNames.insert(pair<int, Name>(studentNumber, name));
        studentScores.insert(pair<int, vector<int>>(studentNumber, scores));
    }
}

void formatCaseOfNames(map<int, Name> &names) {
    for (auto itr : names) {
        string name = itr.second.first_name;
        int nameLength = name.length();
        for (int i = 0; i < nameLength; ++i) {
            if (i == 0 and (name[i]>='a' && name[i]<='z'))
                name[i] = name[i] - 32;
            else if(name[i]>='A' && name[i]<='Z')
                name[i] = name[i] + 32;
        }

        name = itr.second.last_name;
        nameLength = name.length();
        for (int i = 0; i < nameLength; ++i) {
            if (i == 0 and (name[i]>='a' && name[i]<='z'))
                name[i] = name[i] - 32;
            else if(name[i]>='A' && name[i]<='Z')
                name[i] = name[i] + 32;
        }
    }
}

void computeTotalAndPercent(map<int, vector<int>> &scores,map<int, int>
        &total,  map<int, float> &percent) {

}

void writeFormattedGrades(const string outputFilepath,map<int, Name> &names,
        map<int, int> &total,map<int, float> &percent) {

}
