/*CharacterFrequencies.cpp; Jackson Oravetz; Ahmed, Kishwar
* This code contains a header file title CharacterFrequencies.h
* The goal of this code is to parse through a given string and determine the number of occurances of each character.
* A vector pair is used to keep track of each character and its frequency.  
*/


#include <iostream>
#include <string>
#include "CharacterFrequencies.h"
using namespace std;

int main()
{
    string line = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";
    CharacterFrequencies lineCharFreq;      //create CharacterFrequencies object
    lineCharFreq.printFrequencies();        //prints curretn character freqeuncies, which would print nothing at this point

    cout << line << endl;                   //print the string
    lineCharFreq.readString(line);          //call the readString method
    lineCharFreq.printFrequencies();        //print the number of frequencies.

    lineCharFreq.reset();                   //clear the entire vector
    lineCharFreq.printFrequencies();        //print nothing, because vector is cleared

    string line2 = "Twinkle twinkle little star, how I wonder what you are.";
    cout << "\n" << line2 << endl;              //print new string
    CharacterFrequencies line2CharFreq(line2);  //create new object
    line2CharFreq.printFrequencies();           //print the number of frequencies of line2
    line2CharFreq.readString(line2);            //reread line 2
    line2CharFreq.printFrequencies();           //print frequencies again, doubling from previous print

    char c = 'x';
    cout << "Number of occurrences of character " << c << ": ";     //prints numbers of specificially requested characters
    cout << line2CharFreq.getFrequency(c) << endl;
    char c2 = 'w';
    cout << "Number of occurrences of character " << c2 << ": ";
    cout << line2CharFreq.getFrequency(c2) << endl;

    return 0;
}

CharacterFrequencies::CharacterFrequencies()   //No-arg constructor
{

}

CharacterFrequencies::CharacterFrequencies(string line) //arg-constructor that calls readString
{
    readString(line);
}

void CharacterFrequencies::readString(string line)      //method to read through the string 
{
    for (int i = 0; i < line.size(); i++)       //loop through entire string
    {
        char letter = line.at(i);
        bool letterFound = false;
        for (int j = 0; j < frequencies.size(); j++)    //loop through vector
        {
            if (letter == frequencies.at(j).first)  //if char of string matches char of vector, increment frequency of pair
            {
                frequencies.at(j).second++;
                letterFound = true;                 //matching character has bee found
            }
        }
        if (letterFound == false) frequencies.push_back(make_pair(letter, 1));  //if letter is not found, make new vector pair for it
        
    }

    
}

void CharacterFrequencies::reset()  //method to reset entire vector
{
    frequencies.clear();   //removes everything from vector
}
  
int CharacterFrequencies::getFrequency(char c)      //method for finding the frequency of certain character
{
    for (int i = 0; i < frequencies.size(); i++)    //loop for entire vector
    {
        if (c == frequencies.at(i).first)           //if requested char matches vector char, return its frequency
            return frequencies.at(i).second;
    }
    return 0;
}

void CharacterFrequencies::printFrequencies()       //method to print frequency of each char
{
    for (int i = 0; i < frequencies.size(); i++)    //loop for entire vector
    {  
        cout << frequencies.at(i).first << ": " << frequencies.at(i).second << endl;    //print each pairs char and frequency
    }
        
}

int CharacterFrequencies::getCharacterIndex(char c) //unused method to find index of requested char
{
    for (int i = 0; i < frequencies.size(); i++)    //loop for entire vector
    {
        if (c == frequencies.at(i).first)           //if requested char matches char in vector, return index
            return i;
    }
}

