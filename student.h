#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <list>

using namespace std;

class Student
{
public:
	Student();
	~Student();

	// Set attributes
	void setStudentName(string studentName_);
	void setStudentID(int studentID_);
	// If a class exist it must have a grade and semester associated with it
	void setClassData(string className_, float classGrade_, int classSemester_);

	// Get attributes
	string getStudentName();
	int getStudentID();
	string* getClassNames();
	float* getClassGrades();
	int* getClassSemesters();
	float getGPA();
	int getCurClassAmount();


	// Misc
	string* findClassByGrade(float Grade);

private:
	// Create attribuutes
	string studentName;
	int studentID;
	string classNames[100] = {};
	float classGrades[100] = {};
	int classSemesters[100] = {};
	string matchingClasses[100] = {};
	int curClass;
};

#endif
