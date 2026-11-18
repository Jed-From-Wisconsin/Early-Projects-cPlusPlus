#include <iostream>
#include <conio.h>

using namespace std;

//Passing byRef (byReference) vs byValue
void TestValueFunction(int n)
{
	n += 100;
}


void TestRefFunction(int& n)
{
	n += 32;

}

//Recursive Function
void CountDownFrom(int number)
{
	cout << number << "\n";

	if (number < 1) return;

	CountDownFrom(number - 1);
}


int main()
{
	//CountDownFrom(10);
	int myNumber = 4;
	cout << "MyNumber: " << myNumber << "\n";
	TestValueFunction(myNumber);
	cout << "myNumber: " << myNumber << "\n";
	TestRefFunction(myNumber);
	cout << "myNumber: " << myNumber << "\n";

	(void)_getch();
	return 0;
}