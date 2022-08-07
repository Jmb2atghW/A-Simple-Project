/*
Author: Joseph M. Baltz II
Date: 3/31/2017
Purpose of Program: This program is to simulate the game of hangman. It uses only word input and output to achieve
its goal. It will use the functions of class string, and its own functions. The program randomly guesses a word, and loads
it into memory. The user guesses a word, and if it is correct, the program will congratulate the user and prompt to play again.
If the word is incorrect, a man hanging on a gallows will be partially displayed, and it will allow three additional tries. 
If the next entries are incorrect, the man will progressively be displayed on a gallows until he is fully hanging on it.
Maybe in the future, I will write a gui/ graphic C++ version of this program using windowed forms. I hope that
the user will enjoy using this program. I know I will.

*/ 

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;


string GenerateWord();	//Should genearate a word for the game.
void DisplayHM(int iChances);	//Should display hangman a few characters at a time.
void FindTheWord(string passStr1, string passStr2, int & iTried); //Should find the character in the generated word. It may be case sensitive.

int main(){
	char cResp;
	string strWord, strGuess;
	const int iTries = 4;
	int iChance = 0;

	do{
		strWord = GenerateWord();
		cout << "Hello, welcome to Joe's Hangman Game!" << endl;
		cout << "Try to guess the randomly generated word" << endl;
		cout << "before the man hangs himself. Note: The words" << endl;
		cout << "used in the game are case sensitive." << endl;
		cout << endl << endl;
		cout << "Guess a whole word>";
		cin >> strGuess;

		do{
			FindTheWord(strGuess, strWord, iChance);
			DisplayHM(iChance);
			if(iChance == 0){
				cout << "Good guess! The word is : " << strWord << endl;
				break;
			}
			if(iChance < iTries){
				cout << "Guess a whole word>";
				cin >> strGuess;
			}

		}while(iChance < iTries);

		if(iChance == iTries)
			cout << "Sorry, you lost the game, the full word is: " << strWord << "." << endl; 
		iChance = 0;
		cout << "Do you want to play again?>";
		cin >> cResp;
		cout << endl;
	} while(tolower(cResp) == 'y');

	return 10;
}

string GenerateWord(){

	string strWord;
	srand(time(0));
	int i = 1, iEntry, iFileEntries = 0;

	ifstream aString("/storage/6466-6234/Computer Programs/theStrFile.str", ios::in);
	if(!aString){
		cerr << "Sorry, I can't open the input file to this program!" << endl;
		exit(1);
	}

	while(!aString.eof()){
		aString >> strWord;
		iFileEntries++;
	}
	
	aString.close();

	iEntry = rand() % iFileEntries;

	ifstream aString2("/storage/6466-6234/Computer Programs/theStrFile.str", ios::in);
	if(!aString2){
		cerr << "Sorry, I can't open the input file to this program!" << endl;
		exit(1);
	}

	while(!aString2.eof() && i < iEntry){
		aString2 >> strWord;
		i++;
	}
	
	aString2.close();

	return strWord;
}

void DisplayHM(int iChances){
	if(iChances == 1){
		cout << "\n|=========|" << endl;
		cout << "|==|      |" << endl;
		cout << "   O      |" << endl;
		cout << "          |" << endl;
		cout << "          |" << endl;
		cout << "===========" << endl;
		
	}

	if(iChances == 2){
		cout << "\n|=========|" << endl;
		cout << "|==|      |" << endl;
		cout << "   O      |" << endl;
		cout << "   |      |" << endl;
		cout << "<--|-->   |" << endl;
		cout << "          |" << endl;
		cout << "          |" << endl;
		cout << "===========" << endl;
		
	}

	if(iChances == 3){
		cout << "\n|=========|" << endl;
		cout << "|==|      |" << endl;
		cout << "   O      |" << endl;
		cout << "   |      |" << endl;
		cout << "<--|-->   |" << endl;
		cout << "   |      |" << endl;
		cout << "   |      |" << endl;
		cout << "          |" << endl;
		cout << "          |" << endl;
		cout << "===========" << endl;

	}

	if(iChances == 4){
		cout << "\n|=========|" << endl;
		cout << "|==|      |" << endl;
		cout << "   O      |" << endl;
		cout << "   |      |" << endl;
		cout << "<--|-->   |" << endl;
		cout << "   |      |" << endl;
		cout << "   |      |" << endl;
		cout << "  / \\     |" << endl;
		cout << " /   \\    |" << endl;
		cout << "--   --   |" << endl;
		cout << "===========" << endl;
	
	}
	
}
void FindTheWord(string passStr1, string passStr2, int & iTried){
	if(passStr1.compare(passStr2) == 0)
		iTried = 0;
	else
		iTried++;
		
}