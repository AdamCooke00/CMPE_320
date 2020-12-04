//Declaration file fot the JumblePuzzle Class
// Adam Cooke - 11/18/2020

#pragma once

using namespace std;

class JumblePuzzle{
    public:
        JumblePuzzle(string secretWord, string puzzleDifficulty); //constructor. takes word to hide and the puzzle difficulty and puts it into a 2d array
        JumblePuzzle(JumblePuzzle&);
        ~JumblePuzzle(); //destructor
        char** getJumble(); //returns the 2d array
        const int getSize(); //returns the width / height of the puzzle
        const int getRowPos(); //returns the row position of the hidden word
        const int getColPos(); //returns the column position of the hidden word
        const char getDirection(); //returns the direction the hidden word is spelt as char

        JumblePuzzle& operator=( JumblePuzzle& right); //overloaded assignment operator
        
    private:
        int sizeOfPuzzle;    //size of Puzzle
        string hiddenWord; //word the user needs to find
        int rowPosition; //int denoting word position
        int columnPosition; //int denoting word position
        char wordDirection; //direction word is spelt in jumble
        char** jumbleCharacters;  //characters in Jumble

};

class BadJumbleException{
    public:
        BadJumbleException(const string& problem); //takes in a string of what the problem is and sets it to the error message
        string what(); //getter method for error message, returns the errorMessage
    private:
        string errorMessage; //what the error is
};