//
// Created by Joseph McFarland on 25-Feb-20.
//

#ifndef SUMMARIZEGRADES_H
#define SUMMARIZEGRADES_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

struct Name {
    string first_name;
    string last_name;
};

void readGradeFile(const  string,int* ,int* , map<int, Name>&, map<int,
        vector<int>>&);

void formatCaseOfNames(map<int, Name>&);

void computeTotalAndPercent(map<int, vector<int>>&,map<int, int>&, map<int,
        float>&);

void writeFormattedGrades(const string, map<int, Name>&, map<int, int>&,
        map<int, float>&);

#endif //SUMMARIZEGRADES_H
