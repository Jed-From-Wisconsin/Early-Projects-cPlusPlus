//determines what code libraries can be used
#include <iostream>
#include <conio.h>
using namespace std; //Assumes that anytime code from an #include is used, it will use std::

//Prototype Functions that let the program knows that they exist, letting them be used anywhere in the program
int GetWidthFromUser();
int GetLengthFromUser();
int CalculateArea(int length, int width); //Parameters tell program how many and what values the function needs, in the order they're given
void DisplayArea(int area);

int main()
{
    //Calls functions, executes the code in them and stores them in the int
    int length = GetLengthFromUser();
    int width = GetWidthFromUser(); 
    int area = CalculateArea(length, width); //After the values are received, parameters are put into CalculateArea equation
    DisplayArea(area); //Displays the area

    (void)_getch(); //After the area is written, the program will not close until a key is pressed
    return 0; //Ends the program successfully and without issue
}


int GetLengthFromUser() //A function, this is what will be sent back to int main
{
    int length; //Holds the user's input, which will be put into the function
    cout << "Please enter your length: "; //Console will prompt user for their length
    cin >> length; //The number the user inputs will become the value for length
    return length; //Takes user input and sends it to main
}

int GetWidthFromUser() //Same thing as GetLengthFromUser
{
    int width;
    cout << "Please enter your width: ";
    cin >> width;
    return width;
}

int CalculateArea(int length, int width) //The parameters are what the user input previously
{
    return length * width; //Takes the value from the parameters and multiplies them together, returning them to main
}

void DisplayArea(int area)
{
    cout << "Your area is: " << area << endl; //Displays the final result in the console
}