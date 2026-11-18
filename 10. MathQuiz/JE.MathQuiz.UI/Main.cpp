// Math Quiz
// Jed Engel

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//function prototypes
vector<string> LoadQuestions(const string& questionFilepath); //A vector of strings, meaning more can be added over time
void AnswerQuestions(const vector<string>& questions, string& results);
void WriteToFile(const string& answerPath, const string& results);

int main()
{
    string questionPath;
    string answerPath;
    string results;

    //Enter filepath for questions and answers
    cout << "What is the filepath for the questions?\n";
    //C:\Users\Owner\Desktop\0. Problems.txt
    getline(cin, questionPath);
    cout << "\nEnter where you'd like the results to go -\n";
    //C:\Users\Owner\Desktop
    getline(cin, answerPath);

    vector<string> questions = LoadQuestions(questionPath); //Load questions from file and store them in the questions vector

    AnswerQuestions(questions, results); //Take questions and record results

    WriteToFile(answerPath + "\\results.txt", results); //Take results and save them in a notepad file
    cout << "\nQuiz finished, results saved in " << answerPath;

    (void)_getch();
    return 0;
}

vector<string> LoadQuestions(const string& questionPath) //Receive question file location
{
    vector<string> questions; //Create empty vector
    string line; //Temporarily hold each line read from the file
    ifstream file(questionPath); //Open the questions file

    while (getline(file, line)) //Read one line at a time until there are no more lines
    {
        if (!line.empty()) //If line is not empty, add it to the vector
        {
            questions.push_back(line); //Add line to the end of the questions vector
        }
    }
    //Close file and return filled vector to main
    file.close(); 
    return questions;
}

void AnswerQuestions(const vector<string>& questions, string& results) //Receive questions and the results
{
    string answer = "";
    srand(time(NULL)); //Use time to randomize selection and seed it
    for (int i = 0; i < 3; i++) //Get 3 questions
    {
        //Get a random number, use it to output a question, get user to input answer
        int randomNumber = rand() % 10;
        cout << "Question " << (i+1) << ": " << questions[randomNumber] << "\n"; 
        getline(cin, answer);


        results += questions[randomNumber] + " = " + answer + "\n"; //Add to results string
    }
    results += "\nJed was here";
}

void WriteToFile(const string& answerPath, const string& results)
{
    ofstream outFile(answerPath);//open file at answer path, and create or overwrite it
    outFile << results; //put results into file
    outFile.close(); //Close file and save data
}