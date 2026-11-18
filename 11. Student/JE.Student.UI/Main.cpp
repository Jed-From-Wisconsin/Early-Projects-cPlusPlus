#include <iostream>
#include <conio.h>

#include "Student.h"

using namespace std;

int main()
{
	//First student on the stack
	Student firstStudent;

	//Hold User Input for first student
	string firstStudentName;
	float firstStudentGPA;

	//Get information
	cout << "Enter first student name: ";
	cin >> firstStudentName;
	firstStudent.setName(firstStudentName);

	cout << "Enter first student GPA: ";
	cin >> firstStudentGPA;
	firstStudent.setGPA(firstStudentGPA);

	cout << "\nFirst Student Created: \n";
	firstStudent.display();

	//Ask user if they'd like to put information for new student
	cout << "\nCreate second student? Y for yes, any key to close: ";
	char choice;
	cin >> choice;

	if (choice == 'y') //if y is entered, do this
	{
		//Second student on the heap
		string secondStudentName;
		float secondStudentGPA;

		//Get information for second student
		cout << "\nEnter second student name: ";
		cin >> secondStudentName;

		cout << "Enter second student GPA: ";
		cin >> secondStudentGPA;

		//Create second student on the heap using prior information
		Student* secondStudent = new Student(secondStudentName, secondStudentGPA);

		//Dereference and Display information
		cout << "\nSecond Student Created: \n";
		secondStudent->display();

		//No memory leaks here
		delete secondStudent;
	}

	//Either way, end app
	(void)_getch();
	return 0;

}

