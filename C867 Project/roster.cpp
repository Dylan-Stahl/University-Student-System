#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

#include "roster.h"
#include "student.h"


//Constructor 
Roster::Roster(const string studentData[], int studentDataSize, int maxDataSize)
{
	this->classRosterArray = new Student * [maxDataSize];
	this->maxDataSize = maxDataSize;
	this->studentDataSize = studentDataSize;
}

//Deconstructor
Roster::~Roster()
{
	delete[]  classRosterArray;
}

//Functions
void Roster::parse(const string studentData[])
{
	for (int i = 0; i < studentDataSize; i++) {
		string elementStr = studentData[i];
		vector<string> parsedData;
		stringstream sStream(elementStr);

		while (sStream.good())
		{
			string substr;
			getline(sStream, substr, ',');
			parsedData.push_back(substr);
		}

		//Setting values for student objects and converting string to integer values
		int age = stoi(parsedData[4]);
		int daysToComplete[NUMCOURSES] = { stoi(parsedData[5]), stoi(parsedData[6]), stoi(parsedData[7]) };
		

		string studentID = parsedData[0];
		string firstName = parsedData[1];
		string lastName = parsedData[2];
		string email = parsedData[3];
		if (parsedData[8] == "SECURITY") {
			DegreeProgram degreeProgram = SECURITY;
			classRosterArray[i] = new Student(studentID, firstName, lastName, email, age, daysToComplete, degreeProgram);
		}
		else if (parsedData[8] == "NETWORK") {
			DegreeProgram degreeProgram = NETWORK;
			classRosterArray[i] = new Student(studentID, firstName, lastName, email, age, daysToComplete, degreeProgram);

		}
		else if (parsedData[8] == "SOFTWARE") {
			DegreeProgram degreeProgram = SOFTWARE;
			classRosterArray[i] = new Student(studentID, firstName, lastName, email, age, daysToComplete, degreeProgram);

		}
		else {
			DegreeProgram degreeProgram = INVALID;
			classRosterArray[i] = new Student(studentID, firstName, lastName, email, age, daysToComplete, degreeProgram);

		}		
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	string email = emailAddress;
	int daysToComplete[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	DegreeProgram degreeProgram = degreeprogram;

	classRosterArray[studentDataSize] = new Student(studentID, firstName, lastName, email, age, daysToComplete, degreeProgram);
	this->studentDataSize = this->studentDataSize + 1;

}

void Roster::remove(string studentID)
{
	bool foundStudentID = false;
	int i;
	for (i = 0; i < studentDataSize; ++i) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			foundStudentID = true;
			cout << endl;
			cout << "Removing Student with ID: " << studentID << "\n" << endl;
			break;
		}
	}
	if (i < studentDataSize) {
		studentDataSize = studentDataSize - 1;
		for (int j = i; j < studentDataSize; j++) {
			classRosterArray[i] = classRosterArray[j + 1];
		}
	}
	if (foundStudentID == false) {
		cout << "Student ID "<< studentID << " not found.\n" << endl;
	}
}



void Roster::printAll()
{
	cout << "Displaying all Students: " << endl;
	for (int i = 0; i < this->studentDataSize; ++i) {
		classRosterArray[i]->Print();
	}
	cout << endl;
}


void Roster::printAverageDaysInCourse(string studentID)
{
	bool foundStudentID = false;
	for (int i = 0; i < studentDataSize; ++i) {
		if (classRosterArray[i]->GetStudentID() == studentID && foundStudentID == false) {
			int* daysToComplete = classRosterArray[i]->GetdaysToComplete();
			int avgDays = (daysToComplete[0] + daysToComplete[1] + daysToComplete[2]) / 3;
			
			cout << "Student ID: " << studentID << ", averages " << avgDays << " in a course." << endl;
			foundStudentID = true;
		}
		
	}
	if (foundStudentID == false) {
		cout << "Student ID " << studentID << " not Found" << endl;
	}
}
//Note: A valid email should include an at sign('@') and period('.') and should not include a space(' ').
void Roster::printInvalidEmails()
{
	
	cout << "Displaying invalid emails:" << endl;
	for (int i = 0; i < studentDataSize; i++) {
		bool hasAt = false;
		bool hasPeriod = false;
		bool hasSpace = false;
		int atCounter = 0;
		string tempEmail = classRosterArray[i]->GetEmail();
		for (int j = 0; j < tempEmail.length(); ++j) {
			if (tempEmail[j] == ' ') {
				hasSpace = true;
			}
			if (tempEmail[j] == '.') {
				hasPeriod = true;
			}
			if (tempEmail[j] == '@') {
				atCounter = atCounter + 1;
				hasAt = true;
			}
		}
		if (hasAt == false) {
			cout << tempEmail << " - missing @ symbol." << endl;
		}
		if (atCounter > 1) {
			cout << tempEmail << " - too many @ symbols." << endl;
		}
		if (hasPeriod == false) {
			cout << tempEmail << " - missing a period." << endl;
		}
		if (hasSpace == true) {
			cout << tempEmail << " - no spaces allowed." << endl;;
		}		
	}
	cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	switch (degreeProgram) {
	case 0: {
		cout << endl;
		cout << "Showing students in degree program: SECURITY" << endl;
		for (int i = 0; i < studentDataSize; ++i) {
			if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
				classRosterArray[i]->Print();
			}
		}
		break;
	}
	
	case 1: {
		cout << endl;
		cout << "Showing students in degree program: NETWORK" << endl;
		for (int i = 0; i < studentDataSize; ++i) {
			if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
				classRosterArray[i]->Print();
			}
		}
		break;
	}

	case 2: {
		cout << endl;
		cout << "Showing students in degree program: SOFTWARE" << endl;
		for (int i = 0; i < studentDataSize; ++i) {
			if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
				classRosterArray[i]->Print();
			}
		}
		break;
	}
	case 3: {
		cout << endl;
		cout << "Invalid Degree Program";
		break;
	}
	}
}

