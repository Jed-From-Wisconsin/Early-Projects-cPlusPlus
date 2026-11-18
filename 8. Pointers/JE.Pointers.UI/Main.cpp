
// Pointers Demo
// Ryan Appel

#include <iostream>
#include <conio.h>

using namespace std;

struct Student
{
	string Name;
	float GPA;
};

void ClearStudentData(Student* pStudent)
{
	pStudent->Name = "";
	pStudent->GPA = 0;
}

void PrintStudent(Student* pStudent)
{
	cout << pStudent->Name << " has a gpa of: " << pStudent->GPA << "\n";
}

int main()
{

	cout << "How many numbers? ";
	int count = 0;
	cin >> count;

	//It's ok to not use a p tag on arrays
	int* numbers = new int[count];
	for (int i = 0; i < count; i++)
	{
		cout << "Enter number " << (i + 1) << ": ";
		cin >> numbers[i];
	}

	for (int i = 0; i < count; i++)
	{
		cout << numbers[i];
		if (i < count - 1) cout << ", ";
		else cout << "\n";
	}


	//On the stack (memory ALWAYS gets allocated, even if his Jack doesn't get used)
	Student jack;
	jack.Name = "Jack";
	jack.GPA = 3.5f;
	//PrintStudent(Jack) doesn't work, because the datatypes don't match

	PrintStudent(&jack); //Dereferencing must be used instead to reference his address

	char input = 'n';
	cout << "Create another student? ";
	cin >> input;


	Student* pJed = nullptr; // pointer (ONLY) to Jed, assigned to null pointer, or 0 in memory
	if (input == 'y') //If input is y, allocate some space on the data heap to put Jed on
	{
		pJed = new Student; //Create Jed on the heap. pJed is the pointer, but not the object being created
		//(*pJed).Name = "Jed"; //this works, but is innefficient
		pJed->Name = "Jed"; //The "Arrow Operator" is the shorthand for dereferencing
		pJed->GPA = 3.7f;

		PrintStudent(pJed); //Because Jed is already a pointer, we can point to him
		
	}

	//clear jed

	if (pJed) ClearStudentData(pJed); //if there is a 0 value, trigger ClearStudentData. If pJed is null data, this will be false



	(void)_getch();
	return 0;
}

void notes()
{
		int age = 27;

	cout << "The value of age is " << age << "\n";
	cout << "The address of age is " << &age << "\n"; //& means the "address of" operator. "And" sounds like "Address" so remember is like that

	//creating a pointer to an integer called pAge, assinging address of age
	int* pAge = &age; //p for pointer, capitalize name after that

	cout << "The value of pAge is " << pAge << "\n";
	cout << "The value that pAge points to is " << *pAge << "\n";

}