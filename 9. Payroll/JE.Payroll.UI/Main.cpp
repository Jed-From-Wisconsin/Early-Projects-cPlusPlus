
// Pay Report
// Jed Engel, The Great, The Grand, The Spick and Span

#include <iostream>
#include <conio.h>

using namespace std;

//Establish Employee Struct
struct Employee {
    int ID = 0;
    string firstName = "";
    string lastName = "";
    float hoursWorked = 0;
    float hourlyRate = 0;
};

//Function Prototypes
Employee* MakeEmp(int count);
float CalculatePay(Employee* pEmployee);
void PrintEmpInfo(Employee* pEmployees, int count);
void GetEmpInfo(Employee& emp, int empNumber);

int main()
{

    //Ask for number of Employees
    cout << "How many Employees? ";
    int count = 0;
    cin >> count;

    Employee* pEmployees = MakeEmp(count); //Creates a pointer that points to a section of memory, and creates Employees inside of that memory


    PrintEmpInfo(pEmployees, count); //Display Input for Employee Info

    //Clear all information from memory before closing
    delete[] pEmployees;
    pEmployees = nullptr;

    (void)_getch();
    return 0;
}

Employee* MakeEmp(int count)
{
    Employee* pEmployees = new Employee[count]; //Create employee for every int in count, and store it in the memory location pointed to by pEmployees

    for (int i = 0; i < count; i++) //loop until all employees are created
    {
        GetEmpInfo(pEmployees[i], i + 1); //Get employee info for each employee, and store it in the memory location of the pointer
    }

    return pEmployees;

}

void GetEmpInfo(Employee& emp, int empNumber) //Reference employee and fill in parameters
{
    //Get user input
    cout << "Please enter the ID for Employee #" << empNumber << ": ";
    cin >> emp.ID;

    cout << "Please enter the first name for Employee #" << empNumber << ": ";
    cin >> emp.firstName;

    cout << "Please enter the last name for Employee # " << empNumber << ": ";
    cin >> emp.lastName;

    cout << "Please enter the hours worked for Employee #" << empNumber << ": ";
    cin >> emp.hoursWorked;

    cout << "Please enter the hourly rate for Employee #" << empNumber << ": ";
    cin >> emp.hourlyRate;

}

float CalculatePay(Employee* pEmployee)
{
    return pEmployee->hoursWorked * pEmployee->hourlyRate; //Access hoursWorked and hourlyRate and multiply them
}

void PrintEmpInfo(Employee* pEmployee, int count)
{
    float totalPay = 0.0f;

    cout << "\nPay Report\n";
    cout << "-------------\n";

    for (int i = 0; i < count; i++) //loop until all employees are printed
    {
        float empPay = CalculatePay(&pEmployee[i]); //Calculate pay for all employees and store it in empPay
        totalPay += empPay; //combine wages

        //list all
        cout << "\n" << pEmployee[i].ID << ". "
            << pEmployee[i].firstName << " "
            << pEmployee[i].lastName << ": $"
            << empPay;
    }

    cout << "\n Combined Pay: $" << totalPay;
}

/* Pay Report
----------
123. John Doe : $600
456. Jane Smith : $615

Total Pay : $1215
*/
//Format to be used