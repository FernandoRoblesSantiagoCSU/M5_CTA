//============================================================================
// Name        : M5_CTA.cpp
// Author      : Nando
// Version     :
// Copyright   : Your copyright notice
// Description : CTAM5, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ofstream outFile;
	ifstream inFile;
	string userName;
	int userNumber;
	string fileName = "CSC450_CT5_mod5.txt";
	string fileReverse = "CSC450-mod5-reverse.txt";
	ifstream reverseInputFile;
	string fileContent;

	//check if file can be opened
	inFile.open(fileName);
	if(!inFile.is_open()){
		cout << "Error opening file... check if file exist in folder";
		return 1;
	}
	inFile.close();

	//Open file in append mode
	outFile.open(fileName, ios::app);

	//Error check if file can't be opened
	if(!outFile.is_open()){
		cout << "Error opening file." << endl;
		return 1;
	}

	//Get input from user
	cout << "Enter your name: ";
	getline(cin, userName);

	cout << "What is your favorite number?: ";
	cin >> userNumber;

	//Output data to file
	outFile << "\n";
	outFile << "Name: "<< userName << endl;
	outFile << "Your favorite number is: " << userNumber << endl;
	//Close file
	outFile.close();

	//Reverse content//Open file to be reversed
	reverseInputFile.open(fileName);

	//Read content of file into a string
	string line;
	while(getline(reverseInputFile, line)){
		fileContent += line +"\n";
	}

	reverseInputFile.close();
	//Reverse content
	reverse(fileContent.begin(), fileContent.end());
	//open reverse file
	outFile.open(fileReverse);
	//output content to reverse file
	outFile << fileContent;

	outFile.close();

	cout << "Program has executed!" << endl;
	cout << "User data successfully saved on file: " << fileName << endl;
	cout << "Reversed content saved in: " << fileReverse << endl;

	return 0;
}
