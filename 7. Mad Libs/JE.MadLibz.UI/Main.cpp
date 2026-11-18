#include <iostream>
#include <conio.h>

using namespace std;

//Function Prototypes
struct ENTRY;
struct ENTRY
{
    string type;
    string input;
};

void FixMistake(ENTRY entries[]);
void MadLib(ENTRY entries[]);

int main()
{
    
    cout << "Welcome to mad libs.\n";

    //Establishing the arrays
    ENTRY entries[] = {
    {"1. Place", ""},
    {"2. Occupancy", ""},
    {"3. An action", ""},
    {"4. another action", ""},
    {"5. Species of animal, plural", ""},
    {"6. Another Place", ""},
    {"7. adjective", ""},
    {"8. Your family member", ""},
    {"9. Number", ""},
    {"10. Charity", ""},
    {"11. Object", "" }
    };

    
    const int ListCount = 11; //How many arrays are in the list, will have to be changed with each addition or removal

    for (int i = 0; i < ListCount; i++) //i goes up with every loop, until it exceeds ListCount
    {
        cout << "Please enter " << entries[i].type << ": "; 
        cin >> entries[i].input;
    }

    //Do code in here
    FixMistake(entries);
    MadLib(entries);

    (void)_getch();
    return 0;
}

//Today I went to (Place) and saw a (occupancy) doing (an action). I asked him what he was doing, and he said he was trying to save the (Animals) in (place).
//I told him that was (adjective) because (your family member) is donating (number) dollars to a (charity), who will buy a (object) to help out.

void FixMistake(ENTRY entries[])
{
    char yn;
    int choice = 0;

    //After everything has been input, ask user if they'd like to fix mistakes
    cout << "Would you like to fix any mistakes? (y/n): ";
    cin >> yn;
    cout << "\n";

    while (yn == 'y') //If user continues to input y,
        {
            cout << "what entry would you like to fix? (1-11): ";
            cin >> choice;

            while (choice < 1 || choice > 11) //If a number is entered that is outside of the range
            {
                //prompt user to enter a right number
                cout << "This is not a valid number. Please re-enter: ";
                cin >> choice;
            }

            choice = choice - 1; //Account for offset

            //Let user change an entry
            cout << "You have chosen to change: " << entries[choice].type << ": " << entries[choice].input << ". Type in your new entry: ";
            cin >> entries[choice].input;

            //Ask user if they need to change anything else, allow loop to run again
            cout << "Entry updated. Is there anything else you'd like to fix?";
            cin >> yn;
        }

        if (yn == 'n') //If n is selected
        {
            return; //Go back to main and continue
        }
}

void MadLib(ENTRY entries[]) //Take struct and arrays and put into mad lib
{
    //The mad lib with everything in it
    cout << "Today I went to " << entries[0].input << " and saw a " << entries[1].input << " " << entries[2].input;
    cout << ".\n I asked him what he was doing, and he said he was trying to " << entries[3].input << " the " << entries[4].input << " in " << entries[5].input;
    cout << ".\n I told him that was " << entries[6].input << " because " << entries[7].input << " is donating $" << entries[8].input << " to " << entries[9].input;
    cout << ", \n who will buy a " << entries[10].input << " To help out.";
}