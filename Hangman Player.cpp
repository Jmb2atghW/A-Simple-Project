/*
Author: Joseph M. Baltz II
Date: 1/19/2016
Purpose of Program: This program is to simulate the game of hangman. It uses only character input and output to achieve
its goal. It will use the functions of class string, and its own functions. The program randomly guesses a word, and loads
it into memory. The user guesses a character of the word, and if it is correct, the program shows the positions the letter
that occurs in the word. If the user guesses the incorrect character, then the program will draw part of the hangman using only
crude characters. Maybe in the future, I will write a gui/ graphic C++ version of this program using windowed forms. I hope that
the user will enjoy using this program. I know I will.

*/ 

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

//string GenerateWord();	//Should genearate a word for the game.
int DisplayHM(int iWdLen, int iBadChars);	//Should display hangman a few characters at a time.
int DisplayCharPosns(char cInpChar[], char foundChar[], int iWL);	//Should display the positions a correct character occurs in a word.
void FindCharacter(char cInpChar, string passStr);	//Should find the character in the generated word. It may be case sensitive.

int main(){
	char cResp, cGuess;
	string strWord;

	do{
		strWord =  "Armature";   //GenerateWord();
		cout << "Hello, welcome to Joe's Hangman Game!" << endl;
		cout << "Try to guess the randomly generated word" << endl;
		cout << "before the man hangs himself. Note: The letters" << endl;
		cout << "used in the game are case sensitive." << endl;
		cout << endl << endl;
		cout << "Guess a letter of the word>";
		cin >> cGuess;

		FindCharacter(cGuess, strWord);
		
		
		cout << "Do you want to play again?>";
		cin >> cResp;
	} while(tolower(cResp) == 'y');

	return 10;
}

/*string GenerateWord(){
	string aWord, aWdSelected;
	int nWords = 1, wdCounter = 0, selectWd;

	ifstream aString("e:\\Programs\\theStrFile.str", ios::in);
	if(!aString){
		cerr << "Sorry, I can't open the input file to this program!" << endl;
		exit(1);
	}
	aString.read(reinterpret_cast<char *>(&aWord), sizeof(aWord));

	while(aString, !aString.eof()){
		aString.seekg(sizeof(aWord));
		nWords++;
	}

	selectWd = (rand() % nWords) + 1;

	while(aString, !aString.eof()){
		aString.seekg(sizeof(aWord));
		wdCounter++;
		if(wdCounter == selectWd)
			aString >> aWdSelected;

		break;
	}

	aString.close();

	return aWdSelected;
}*/	

int DisplayHM(int iWdLen, int iBadChars, string passStr){
	int iStage = 0;

	if(iBadChars != 0 && iWdLen / iBadChars == 4){
		cout << "\n|=========|" << endl;
		cout << "|==|      |" << endl;
		cout << "   O      |" << endl;
		cout << "          |" << endl;
		cout << "          |" << endl;
		cout << "===========" << endl;
		iStage = 25;
	}

	if(iBadChars != 0 && iWdLen / iBadChars == 3){
		cout << "\n|=========|" << endl;
		cout << "|==|      |" << endl;
		cout << "   O      |" << endl;
		cout << "   |      |" << endl;
		cout << "<--|-->   |" << endl;
		cout << "          |" << endl;
		cout << "          |" << endl;
		cout << "===========" << endl;
		iStage = 50;
	}

	if(iBadChars != 0 && iWdLen / iBadChars == 2){
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
		iStage = 75;
	}

	if(iBadChars != 0 && iWdLen / iBadChars == 1){
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
		cout << "Sorry, you lost the game, the full word is: " << passStr << "." << endl; 
		iStage = 100;
	}
	
	return iStage;

}	
int DisplayCharPosns(char cInpChar[], char foundChar[], int iWL){
	int iBChar = 0, k, i, iNTDisp = 0, iCDDisp = 0;
	
	for(i = 0; i < iWL ; i++){
		//If the input char array is at the null char, leave the outer loop.
		if(cInpChar[i] == '\0')
			break;
					
		for(k = 0; k < iWL; k++){
			//If a char. is found, display it.
			//Counts number of characters displayed.
			if(foundChar[k] == cInpChar[i]){
				cout << foundChar[k] << " ";
				iNTDisp++;
			}	

			//Otherwise display a dash.
			//Counts number of displayed dashes.
			else{ 
				cout << "_ ";
				iCDDisp++;
			}

		} 

		//Or if we display the allowed dashes, 
		//or chars, leave a new line.
		if(iCDDisp + iNTDisp >= iWL)
			cout << endl;
	
	}
	cout << endl;	//Displays another newline.

	//If no char. displayed, we have a "bad" character entered.
	if (iNTDisp == 0 || iCDDisp >= iWL){
		iBChar++;
	}

	return iBChar;
}	
void FindCharacter(char cInpChar, string passStr){
	int wdLength = passStr.length(), iBadChars = 0, j = 0;
	const char *theWd = 0;
	char *theInputs = new char[wdLength];
	char *cFChar = new char[wdLength];

	theWd = passStr.data();
	theInputs[0] = cInpChar;
	cFChar[0] = *(theWd + 0);

	for(int x = 1; x < wdLength; ++x){
		theInputs[x] = '\0';
		cFChar[x] = *(theWd + x);
	}

	cout << "The word will have " << wdLength << " characters." << endl;
	cout << "You will have upto " << wdLength << " tries to enter the correct characters." << endl;

	for(int iTries = 1; iTries < wdLength; iTries++){
		iBadChars += DisplayCharPosns(theInputs, cFChar, wdLength);
		if(DisplayHM(wdLength, iBadChars, passStr) == 100)
			break;
		cout << "\n\nEnter another character>";
		cin >> theInputs[iTries];
	}

	delete [] theInputs;
	delete [] cFChar;
}
