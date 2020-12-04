//The implementation of the InsultGenerator Class
// Adam Cooke - 10/2/2020

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "insultgenerator_17adc4.h"

using namespace std;

InsultGenerator::InsultGenerator(){}

void InsultGenerator::initialize(){
    string firstWord, secondWord, thirdWord;
    filename = "InsultsSource.txt";
    ifstream fileIn(filename);

    if(fileIn.fail()){
        throw FileException("File " + filename + " could not be opened");
    }


    //take three words from fileIn and push them into their corresponding vector strings
    while(fileIn >> firstWord >> secondWord >> thirdWord){
        listOfFirstWords.push_back(firstWord);
        listOfSecondWords.push_back(secondWord);
        listOfThirdWords.push_back(thirdWord);
    }
    fileIn.close();
}

//choose 3 words at random and create an insult
string InsultGenerator::talkToMe(){
    string firstWord = listOfFirstWords.at(rand() % listOfFirstWords.size());
    string secondWord = listOfSecondWords.at(rand() % listOfSecondWords.size());
    string thirdWord = listOfThirdWords.at(rand() % listOfThirdWords.size());

    return ("Thou " + firstWord + " " + secondWord + " " + thirdWord + "!");

}

vector<string> InsultGenerator::generate(const int numberOfInsults){

    if(numberOfInsults < 1 || numberOfInsults > 10000){
        throw NumInsultsOutOfBounds("The number of requested insults falls outside the allowed boundary (1-10000)");
    }

    vector<string> generatedInsults;
    int a, b, c;
    int lengthOfList = listOfFirstWords.size();
    //create 3d bool array to match array of sentence possibilities
    bool matchingArray[lengthOfList][lengthOfList][lengthOfList] = {false};
    while(generatedInsults.size() < numberOfInsults){
        a = rand() % lengthOfList;
        b = rand() % lengthOfList;
        c = rand() % lengthOfList;
        //if you have not selected this possibility add it, else choose a different sentence
        if(!matchingArray[a][b][c]){
            generatedInsults.push_back("Thou " + listOfFirstWords.at(a) + " " + listOfSecondWords.at(b) + " " + listOfThirdWords.at(c) + "!");
            matchingArray[a][b][c] = true;
        }
    }
    return generatedInsults;
}

void InsultGenerator::generateAndSave(const string& filename, const int amountOfInsults){

    vector<string> generatedInsults = generate(amountOfInsults);
    
    //sorts alphabetically in nlogn
    sort(generatedInsults.begin(), generatedInsults.end());

    ofstream fileOut(filename);
    int lineCount(0);

    if(fileOut.fail()){
        throw FileException("File " + filename + " could not be opened");
    }

    while(lineCount < amountOfInsults){
        fileOut << generatedInsults.at(lineCount) << endl;
        lineCount++;
    }

    fileOut.close();

}


FileException::FileException(const string& problem) : errorMessage(problem){
}

string FileException::what(){
    return errorMessage;
}


NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& problem) : errorMessage(problem){
}

string NumInsultsOutOfBounds::what(){
    return errorMessage;
}
