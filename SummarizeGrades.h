//
// Created by Joseph McFarland on 25-Feb-20.
//

#ifndef SUMMARIZEGRADES_H
#define SUMMARIZEGRADES_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

struct Name {
    string first_name;
    string last_name;
};

void readGradeFIle(const  string  inputFilepath,  int  *numberOfStudents, int
*numberOfAssignments, map<int, Name> &studentNames, map<int, vector<int>>
&studentScores);

void formatCaseOfNames(map<int, Name> &names);

void computeTotalAndPercent(map<int,  vector<int>> &scores,map<int,  int>
        &total,  map<int,  float> &percent);

void writeFormattedGrades(const string outputFilepath,map<int, Name> &names,
        map<int, int> &total,map<int, float> &percent);

#endif //SUMMARIZEGRADES_H
