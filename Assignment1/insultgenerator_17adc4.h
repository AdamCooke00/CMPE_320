//Declaration file fot the InsultGenerator Class
// Adam Cooke - 10/2/2020

#pragma once

using namespace std;


class InsultGenerator{
    public:
        InsultGenerator();                  //default constructor, does nothing in this code
        void initialize();                  //reads in 3 columns of words from a file and sets them to vector strings
        string talkToMe();                  //generated 3 random numbers that range from 0 to the length of the vector string lists and creates an insult with the words selected
        vector<string> generate(const int numberOfInsults); //takes in the number of Shakespearian insults requested, then returns a vector string of randomly generated unique insults                
        void generateAndSave(const string& filename, const int amountOfInsults); //takes in the desired filename and number of insults and calls generate, then takes the returned vector string and sorts it alphabetically, then writes the insults to the filename.

    private:
        string filename;                    //name of file initialize is reading from
        vector<string> listOfFirstWords;    //first column read from file in initialize
        vector<string> listOfSecondWords;   //second column ...
        vector<string> listOfThirdWords;    //third column ...
};

class FileException{
    public:
        FileException(const string& problem); //takes in a string of what the problem is and sets it to the error message
        string what();          //getter method for error message, returns the errorMessage
    private:
        string errorMessage;    //what the error is
};

class NumInsultsOutOfBounds{
    public:
        NumInsultsOutOfBounds(const string& problem); //takes in a string of what the problem is and sets it to the error message
        string what();          //getter method for error message, returns the errorMessage
    private:
        string errorMessage;    //what the error is
};