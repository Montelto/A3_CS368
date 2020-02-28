# A3_CS368
# Joseph McFarland
# 9072511679
# mcfarland3@wisc.edu

*Created in CLion and pushed to Github*

SummarizeGrades consists of 3 files:
 SummarizeGrades.h, SummarizeGrades.cpp, and demo.cpp. The first being the
  header file, the second being the implementation of the student grades
   modification functions, and the third being the main() function
    implementation to test these modification functions.
    
SummarizeGrades.h includes fstream for file reading and writing , vector for
 use of datatype, map for use of datatype, iomanip for setw and setpresision
 , and iostream for demo to output to the console after file is initially
  read. Namespace std is used for ease of coder. Struct Name is used to store
   the first and last name of each student together.

SummarizeGrades.cpp is organized, readGradeFile() takes the path of the input
 file and references to some data structures that will hold the student names
  and scores for other functions to process. It also contains pointers to
   variables that will keep track of the number of students and assignments
   . formatCaseOfNames() takes the student names map and changes the first
    and last name strings in the struct(values in map) so that the first
     letter of each string is a capital letter and all other letters are
      lower case. computeTotalAndPercent() takes the scores map and computes
       the total score (the sum of all points earned) as well as the final
        percentage as a float and stores these computed results in total and
         percent maps respectively where key is the student ID
         . writeFormattedGrades() takes the path of the output file and
          references to some data structures  that holds the student names
          , scores, and percents and writes them to output file. It write to
           the file in a formatted form so that the first letter in every
            last name, the one digit in score, and decimal point in
             percentage are aligned respectively for all students.

demo.cpp executes a test for SummarizeGrades.cpp by calling all functions in
 order to create a properly formatted output file. Prints to console after
  initial readGradeFile to ensure file was read correctly and values were
   placed in correct locations.
   
**make SummarizeGrades** 
