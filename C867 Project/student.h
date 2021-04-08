#pragma once

#include "degree.h"
#include <string>
using namespace std;

const int NUMCOURSES = 3;

class Student
{
public:
	//constructors
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], DegreeProgram degreeProgram);
	
	//deconstructor
	~Student();

	//getters 
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

	//print function
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

