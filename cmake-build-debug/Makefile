# A3_368
# Joseph McFarland
# 9072511679
# mcfarland3@wisc.edu

CXX = g++
CXXFLAGS = -Wall -g

SummarizeGrades.o: SummarizeGrades.cpp SummarizeGrades.h
	$(CXX) $(CXXFLAGS) -c SummarizeGrades.cpp

demo.o: demo.cpp SummarizeGrades.h
	$(CXX) $(CXXFLAGS) -c demo.cpp

clean:
	-rm SummarizeGrades.o
	-rm demo.o
	-rm SummarizeGrades

SummarizeGrades: demo.o SummarizeGrades.o
	$(CXX) $(CXXFLAGS) -o SummarizeGrades demo.o SummarizeGrades.o
