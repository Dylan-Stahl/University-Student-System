#include <iostream>
#include <string>
using namespace std;

#include "student.h"
#include "degree.h"

//constructors
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < NUMCOURSES; ++i) {
		numOfDaysToComplete[i] = 0;
	}
	this->degreeProgram = INVALID;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < NUMCOURSES; ++i) {
		numOfDaysToComplete[i] = daysToComplete[i];
	}
	this->degreeProgram = degreeProgram;
}

//Deconstructor
Student::~Student()
{
	delete numOfDaysToComplete;
}

//Getter functions following

string Student::GetStudentID() const
{
	return this->studentID;
}

string Student::GetFirstName() const
{
	return this->firstName;
}

string Student::GetLastName() const
{
	return this->lastName;
}

string Student::GetEmail() const
{
	return this->email;
}

int Student::GetAge() const
{
	return this->age;
}

int* Student::GetdaysToComplete() 
{
	return numOfDaysToComplete;
}

DegreeProgram Student::GetDegreeProgram() const
{
	return this->degreeProgram;
}

//End of getter functions

//Setter functions following

void Student::SetStudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::SetFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::SetLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::SetEmail(string email)
{
	this->email = email;
}

void Student::SetAge(int age)
{
	this->age = age;
}

void Student::SetDaysToComplete(int daysToComplete[])
{
	for (int i = 0; i < NUMCOURSES; ++i) {
		numOfDaysToComplete[i] = daysToComplete[i];
	}
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram)
{
	this->degreeProgram = degreeProgram;
}

//Print Function
void Student::Print()
{
	cout << this->studentID << "\t";
	cout << "First Name: " << this->firstName << "\t";
	cout << "Last Name: " << this->lastName << "\t";
	cout << "Age: " << this->age << "\t";
	cout << "daysInCourse: " << numOfDaysToComplete[0] << ", " << numOfDaysToComplete[1] << ", " << numOfDaysToComplete[2] << "\t";
	

	if (this->degreeProgram == SECURITY) {
		cout << "Degree Program: " << "SECURITY" << endl;
	}
	else if (this->degreeProgram == NETWORK) {
		cout << "Degree Program: " << "NETWORK" << endl;
	}
	else if (this->degreeProgram == SOFTWARE) {
		cout << "Degree Program: " << "SOFTWARE" << endl;
	}
	else if (this->degreeProgram == INVALID) {
		cout << "Degree Program Invalid" << endl;
	}
}

