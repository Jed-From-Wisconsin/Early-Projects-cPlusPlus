//Write a function called "Get Number", which lets you enter an int
//It will ask you to write another number
//Write another function called GetOp
//If they choose 1, multiply. If they choose 2, divide
//Give the result

#include <iostream>
#include <conio.h>
using namespace std;

int GetFirstNumber();
int GetSecondNumber();
int MultOrDiv();
int Calculation();
void DisplayTotal();

int main()
{
	int FirstNo = GetFirstNumber();
	int SecondNo = GetSecondNumber();

	(void)_getch;
		return 0;
}

int GetFirstNumber()
{
	int FirstNo;
	cout << "Please enter your first number: ";
	cin >> FirstNo;
	return FirstNo;
}

int GetSecondNumber(int FirstNo)
{
	int SecondNo;
	cout << "\n You entered" + FirstNo;
	cout << "\n Please enter a second number";
	cin >> SecondNo;
	return SecondNo;
}

int MultOrDiv()
{

}