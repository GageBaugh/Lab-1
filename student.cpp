#include "student.h"
#include <iostream>

Student::Student()
{
	studentName = "";
	studentID = 0;
	curClass = 0;
}

Student::~Student()
{
}

// Set methods
void Student::setStudentName(string studentName_)
{
	studentName = studentName_;
}

void Student::setStudentID(int studentID_)
{
	studentID = studentID_;
}

void Student::setClassData(string className_, float classGrade_, int classSemester_)
{
	if(classGrade_ < 0.0)
	{
		cout << "ERROR Grade must be greater than 0" << endl << endl;
		return;
	}
	else if(classSemester_ != 1 && classSemester_ != 2)
	{
		cout << "ERROR Semester must be 1 or 2" << endl << endl;
		return;
	}
	else
	{
		classNames[curClass] = className_;
		classGrades[curClass] = classGrade_;
		classSemesters[curClass] = classSemester_;
		curClass += 1;
	}
}

// Get methods
string Student::getStudentName()
{
	return studentName;
}

int Student::getStudentID()
{
	return studentID;
}

string* Student::getClassNames()
{
	return classNames;
}

float* Student::getClassGrades()
{
	return classGrades;
}

int* Student::getClassSemesters()
{
	return classSemesters;
}

int Student::getCurClassAmount()
{
	return curClass;
}

float Student::getGPA()
{
	float GPA = 0;
	int numOfGrades = 0;
	for (int i = 0; i < curClass; i++)
	{
		float curGrade = classGrades[i];
		if (classNames[i] != " ")
		{
			if (curGrade >= 90.0)
			{
				GPA += 4.0;
			}
			else if (curGrade >= 80.0)
			{
				GPA += 3.0;
			}
			else if (curGrade >= 70.0)
			{
				GPA += 2.0;
			}
			else if (curGrade >= 60.0)
			{
				GPA += 1.0;
			}
			else
			{
				GPA += 0.0;
			}
			numOfGrades++;
		}
		else
		{
			break;
		}
	}
	GPA = GPA / numOfGrades;
	return GPA;
}

// Misc
string* Student::findClassByGrade(float grade)
{
	for (int i = 0; i < curClass; i++)
	{
		matchingClasses[i] = "";
	}
	if (grade < 0.0)
	{
		cout << "ERROR Grade must be greater than 0" << endl << endl;
		return matchingClasses;
	}
	int index = 0;
	for (int i = 0; i <= curClass; i++)
	{
		if (grade == classGrades[i])
		{
			matchingClasses[index] = classNames[i];
			index++;
		}
	}
	return matchingClasses;
}