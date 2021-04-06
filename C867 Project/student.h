#include <string>
#include "degree.h"

#ifndef student.h
#define student.h

/*
Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:
•  student ID
•  first name
•  last name
•  email address
•  age
•  array of number of days to complete each course
•  degree program
*/

/*
Create each of the following functions in the Student class:
a.  an accessor (i.e., getter) for each instance variable from part D1
b.  a mutator (i.e., setter) for each instance variable from part D1
c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
d.  constructor using all of the input parameters provided in the table
e.  print() to print specific student data
*/

class student
{
public:




private:
	int studentID;
	std::string firstName;
	std::string lastName;
	std::string email;
	int age;
	/*
	int numOfDaysToComplete[];
	*/
	DegreeProgram degree;
};

#endif