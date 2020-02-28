//
// Joseph McFarland
// 9072511679
// mcfarland3@wis.edu
// https://canvas.wisc.edu/courses/188843/files for slides
// Made in CLion with commits to GitHub
//

#ifndef SUMMARIZEGRADES_H
#define SUMMARIZEGRADES_H

#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include <iostream>

using namespace std;

/*
 * Struct used as data type to store students first name and last name together.
 */
struct Name {
    string firstName;
    string lastName;
};

/*
 * This function takes the path of the input file and references to some data
 * structures  that will hold the student names and scores for other
 * functions to process. It also contains pointers to variables that will
 * keep track of the number of students and assignments.
 */
void readGradeFile(const string,int* ,int* , map<int, Name>&, map<int,
        vector<int>>&);

/*
 * This function takes the student names map and changes the first and last
 * name strings in the struct(values in map) so that the first letter of each
 * string is a capital letter and all other letters are lower case.
 */
void formatCaseOfNames(map<int, Name>&);

/*
 * This function takes the scores map and computes the total score (the sum
 * of all points earned) as well as the final percentage as a float and
 * stores these computed results in total and percent maps respectively where
 * key is the student ID.
 */
void computeTotalAndPercent(map<int, vector<int>>&,map<int, int>&, map<int,
        float>&);

/*
 * This function takes the path of the output file and references to some data
 * structures  that holds the student names, scores, and percents and writes
 * them to output file. It write to the file in a formatted form so that the
 * first letter in every last name, the one digit in score, and decimal point
 * in percentage are aligned respectively for all students.
 */
void writeFormattedGrades(const string, map<int, Name>&, map<int, int>&,
        map<int, float>&);

#endif //SUMMARIZEGRADES_H
