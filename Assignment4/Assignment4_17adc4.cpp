//The implementation of the JumblePuzzle Class
// Adam Cooke - 11/18/2020

#include <iostream>
#include <string>
#include <cstring>
#include <ctime>


#include "Assignment4_17adc4.h"

using namespace std;


JumblePuzzle::JumblePuzzle(string secretWord, string puzzleDifficulty){
    //ensure the word length is between 3 and 10 characters
    int wordLength = secretWord.length();
    if(wordLength < 3 || wordLength > 10){
        throw BadJumbleException("Secret Word Entered is too short or too long. Must be between 3 and 10 characters.");
    }
    //ensure the user entered a viable word
    for(char& c : secretWord) {
        if(isalpha(c) == 0){
            throw BadJumbleException("Secret Word Entered is not a viable word. Choose a single word with no numbers.");
        }
    }

    hiddenWord = secretWord;

    if (strcmp(puzzleDifficulty.c_str(), "easy") == 0){
        sizeOfPuzzle = 2*wordLength;
    } else if (strcmp(puzzleDifficulty.c_str(), "medium") == 0){
        sizeOfPuzzle = 3*wordLength;
    } else if (strcmp(puzzleDifficulty.c_str(), "hard") == 0){
        sizeOfPuzzle = 4*wordLength;
    } else {
        throw BadJumbleException("Puzzle difficulty entered is Invalid. Enter 'easy', 'medium' or 'hard'.");
    }     

    //seed random
    srand(time(NULL));

    //create jumble
    char** jumble = new char*[getSize()];

    //fill in jumble with random characters
    for(int i=0; i<getSize(); i++){
        jumble[i] = new char[getSize()]; 
        for(int j=0; j<getSize(); j++){
            char randomChar = 'a' + rand()%26; 
            jumble[i][j] = randomChar;
        }
    }
    //choose a random direction. if its legal (doesnt overflow the chart) add it. else choose a different direction.
    string possibleDirections = "news";
    bool isLegal = false;
    int counterAtFour = 4;
    int randomNum;
    char chosenDirection;
    columnPosition = rand()%sizeOfPuzzle;
    rowPosition = rand()%sizeOfPuzzle;
    while(!isLegal){
        randomNum = rand()%counterAtFour;
        chosenDirection = possibleDirections[randomNum];

        switch(chosenDirection){
            case 'n':
                if(wordLength <= rowPosition + 1){
                    isLegal = true;
                    for(int i = 0; i < wordLength; i++){
                        jumble[rowPosition - i][columnPosition] = hiddenWord[i];
                    }
                }
                break;
            case 'e':
                if(wordLength <= sizeOfPuzzle - columnPosition){
                    isLegal = true;
                    for(int i = 0; i < wordLength; i++){
                        jumble[rowPosition][columnPosition + i] = hiddenWord[i];
                    }
                }
                break;
            case 'w':
                if(wordLength <= columnPosition + 1){
                    isLegal = true;
                    for(int i = 0; i < wordLength; i++){
                        jumble[rowPosition][columnPosition - i] = hiddenWord[i];
                    }
                }
                break;
            case 's':
                if(wordLength <= sizeOfPuzzle - rowPosition){
                    isLegal = true;
                    for(int i = 0; i < wordLength; i++){
                        jumble[rowPosition + i][columnPosition] = hiddenWord[i];
                    }
                }
                break;
        }
        possibleDirections.erase(randomNum, 1);
        counterAtFour--;
    }
    wordDirection = chosenDirection;

    // printf("\n\nCHOSEN DIRECTION : %c\nCHOSEN ROW : %d\nCHOSEN COLUMN : %d\n", chosenDirection, rowPosition, columnPosition);

    jumbleCharacters = jumble;

}

JumblePuzzle::JumblePuzzle(JumblePuzzle &right)
{
	hiddenWord = right.hiddenWord;
	sizeOfPuzzle = right.sizeOfPuzzle;
	rowPosition = right.rowPosition;
	columnPosition = right.columnPosition;
	wordDirection = right.wordDirection;
	jumbleCharacters = right.getJumble();
}

JumblePuzzle::~JumblePuzzle()
{
	for (int i = 0; i < sizeOfPuzzle; i++) {
		delete jumbleCharacters[i];
		jumbleCharacters[i] = nullptr;
	}
	delete jumbleCharacters;    
	jumbleCharacters = nullptr;
}

JumblePuzzle& JumblePuzzle::operator=( JumblePuzzle& right){
    sizeOfPuzzle = right.getSize();
    rowPosition = right.getRowPos();
    columnPosition = right.getColPos();
    wordDirection = right.getDirection();
    jumbleCharacters = right.getJumble();
}

char** JumblePuzzle::getJumble(){

    char** newJumble = new char*[sizeOfPuzzle];
	for (int i = 0; i < sizeOfPuzzle; i++) {
		newJumble[i] = new char[sizeOfPuzzle];
        for (int j = 0; j < sizeOfPuzzle; j++) {
			newJumble[i][j] = jumbleCharacters[i][j];
		}
	}
    return newJumble;
}

const int JumblePuzzle::getSize(){
    return sizeOfPuzzle;
}

const int JumblePuzzle::getRowPos(){
    return rowPosition;
}

const int JumblePuzzle::getColPos(){
    return columnPosition;
}

const char JumblePuzzle::getDirection(){
    return wordDirection;
}


BadJumbleException::BadJumbleException(const string& problem) : errorMessage(problem){
}

string BadJumbleException::what(){
    return errorMessage;
}

