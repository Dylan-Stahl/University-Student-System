#pragma once
#include "degree.h"
#include "student.h"
#include <string>
using namespace std;


class Roster
{
public:
	Roster(const string studentData[], int studentDataSize, int maxDataSize);
	~Roster();

	void parse(const string studentData[]);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
private:
	Student* *classRosterArray;
	int studentDataSize;
	int maxDataSize;
};