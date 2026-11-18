#include <iostream>
#include <conio.h>

using namespace std;
//when an #include is used, will assume std prefix

// function prototypes which tell the compiler that these functions exist and they are before they're actually defined
void Greet(int count); //Tells compiler there is a function named Greet, it is a void (returns nothing), and has one int parameter called "count"
int PickRange(int low = 1, int high = 10); //Tells compuler there is a function called PcikRange, which returns an int, and takes two int parameters "low" and "high"


int main() //will return a integer to the OS, usually 0 for success
{
	int picked = PickRange(1, 5); 
	//Calls the function PickRange, and the parameters to set for low and high. 
	//Will prompt the user to enter a number, and will keep asking until number is valid. It will set the chosen number as picked.

	cout << "You picked: " << picked << endl; 
	//prints chosen number to console, endl inserts a new line

	Greet(picked); 
	//Calls the Greet function, passes value of picked as count, then prints Hi the "picked" number of times

	(void)_getch(); //waits for a key press, ignores return value, which prevents the console window from closing instantly
	return 0; //ends to program, returning to 0 for successsful execution
}

int PickRange(int low, int high) 
//Default Parameters for the lowest and highest number
//This will be called if PickRange is called without argumetnts, defaulting to 1 and 10
{
	while (true)
	{
		cout << "Enter a number between "
			<< low << " and " << high << ": ";
		//Displays which numbers are allowed to be used

		int n = 0; //establishes variable to store user input
		cin >> n; //stores the user's input

		if (n >= low && n <= high)
			return n;
		//Checks if the entered input is within the range.
		//If it is, return n exits the function
		//If it isn't, the loop will continue, and the user will be prompted again
	}
}

void Greet(int count) //Void, will not return a value. Count, a local function, tells how many times this will be triggered.
{
	for (int i = 0; i < count; i++) //local i variable set to 0, continuing as long as i is less than count. i increases by 1 after every loop.
		cout << "Hi\n"; //For every loop, print Hi
}
