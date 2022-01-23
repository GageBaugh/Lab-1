#include <iostream>
#include <string>
#include "student.h"

using namespace std;

int main()
{
	Student s;

	// Set class attributes
	s.setStudentName("Obama N/A");
	s.setStudentID(12009);
	s.setClassData("Math", 79.6, 2);
	s.setClassData("English", 90.9, 1);
	s.setClassData("Social Studies", 17.8, 2);
	s.setClassData("Science", 90.9, 1);
	s.setClassData("Python", -100.0, 2);
	s.setClassData("C++", 90.9, 7);

	// Store attributes in variables
	string name = s.getStudentName();
	int id = s.getStudentID();
	string* classNames = s.getClassNames();
	float* classGrades = s.getClassGrades();
	int* classSemester = s.getClassSemesters();
	int curClass = s.getCurClassAmount();
	float GPA = s.getGPA();
	string classGrade1[100] = {};
	string classGrade2[100] = {};
	string classGrade3[100] = {};
	string classGrade4[100] = {};
	for (int i = 0; i < curClass; i++)
	{
		classGrade1[i] = s.findClassByGrade(17.8)[i];
		classGrade2[i] = s.findClassByGrade(90.9)[i];
		classGrade3[i] = s.findClassByGrade(80.3)[i];
		classGrade4[i] = s.findClassByGrade(-100.0)[i];
	}	

	// Display attributes to screen
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl << endl;

	for (int i = 0; i < curClass; i++)
	{
		cout << "Class " << i + 1 << endl;
		cout << "Class Name: " << classNames[i] << endl;
		cout << "Grade: " << classGrades[i] << "%" << endl;
		cout << "Semester: " << classSemester[i] << endl << endl;
	}
	cout << "GPA: " << GPA << endl << endl;
	
	cout << "Get class by grade" << endl;
	cout << "17.8 " << classGrade1[0] << endl;
	cout << "90.9 " << classGrade2[0] << " " << classGrade2[1] << endl;
	cout << "80.3 " << classGrade3[0] << endl;
	cout << "-100.0 " << classGrade4[0] << endl;
	cout << "End";

	return 0;
}