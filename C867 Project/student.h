#pragma once

#include "degree.h"
#include <string>
using namespace std;
/*
Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:
•  student ID
•  first name
•  last name
•  email address
•  age
•  array of number of days to complete each course
•  degree program



Create each of the following functions in the Student class:
a.  an accessor (i.e., getter) for each instance variable from part D1
b.  a mutator (i.e., setter) for each instance variable from part D1
c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
d.  constructor using all of the input parameters provided in the table
e.  print() to print specific student data
*/
const int NUMCOURSES = 3;

class Student
{
public:
	//constructors
	Student();

	Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], DegreeProgram degreeProgram);

	//getters dont have parameters!!
	string GetStudentID() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmail() const;
	int GetAge() const;
	int* GetdaysToComplete(); 
	DegreeProgram GetDegreeProgram() const;

	//setters
	void SetStudentID(string studentID);
	void SetFirstName (string firstName);
	void SetLastName(string lastName);
	void SetEmail(string email);
	void SetAge(int age);
	void SetDaysToComplete(int daysToComplete[]);
	void SetDegreeProgram(DegreeProgram degreeProgram);

	//FIX ME: add print function
	void Print();

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int numOfDaysToComplete[NUMCOURSES];
	DegreeProgram degreeProgram;

};

