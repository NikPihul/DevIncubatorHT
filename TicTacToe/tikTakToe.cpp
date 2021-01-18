#include <iostream>
#include <stdlib.h>
using namespace std;
#define SQUARES_AMOUNT 9
#define BOARD_SIZE 11

void drawBoard(char values[]);
void userTurn(char values[]);
void computerTurn(char values[]);
bool checkPlace(int choice, char values[]);
bool checkArea(int choice);
bool checkResult(char values[], char symbol);

int main () {
	char marks[SQUARES_AMOUNT] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	int stepCounter = 0;
	
	drawBoard(marks);
	
	while (stepCounter < 9) {
		if (stepCounter % 2 == 0)
			userTurn(marks);
		else
			computerTurn(marks);
			
		drawBoard(marks);
		
		if (checkResult(marks, 'X')) {
			cout << "Player wins." << endl;
			break;
		} else if (checkResult(marks, 'O')) {
			cout << "Computer wins." << endl;
			break;
		}
		stepCounter++;
		if (stepCounter == 9) {
			cout << "Draw." << endl;
		}
	}
	return 0;
}

void userTurn(char values[])
{
	int choice;
	
	while (true) {
		cout << "Enter your choice: ";
		cin >> choice;
		
		if (checkPlace(choice, values)) {
			values[choice - 1] = 'X';
			break;
		} else
			cout << "This square isn't empty. Choose another." << endl;
	}
}

void drawBoard(char values[])
{
	system("cls");
	int counter = 0;
	int j;
	for (int i = 1; i <= BOARD_SIZE; i++) {
		if (i & 2 != 0) {
			j = 0;
			while (j < 2) {
				cout.width(4);
				cout << "|";
				j++;
			}
			cout << endl;
		} else if (i == 2 or i == 6 or i == 10) {
			j = 0;
			while (j < 3) {
				if (j < 2) {
					cout.width(2);
					cout << values[counter];
					cout.width(2);
					cout << "|";
				} else {
					cout.width(2);
					cout << values[counter];
				}
				j++;
				counter++;
			}
			cout << endl;
		} else {
			j = 0;
			while (j < 3) {
				if (j == 0) 
					cout << "---";
				else
					cout << "+---";
				j++;
			}
			cout << endl;
		} 
			
	}
}

bool checkPlace(int choice, char values[])
{
	if (choice >= 1 and choice <= 9) {
		if (values[choice - 1] != 'X' and values[choice - 1] != 'O')
			return true;
	}
	return false;
}

void computerTurn(char values[])
{
	int choice;
	bool turnFlag = false;
	
	do {
		choice = rand() % 9 + 1;
		
		if (checkPlace(choice, values)) {
			values[choice - 1] = 'O';
			turnFlag = true;
		}
	} while (!turnFlag);
}

bool checkResult(char values[], char symbol)
{
	if (values[0] == values[4] and values[4] == values[8] and values[8] == symbol)
		return true;
	else if (values[1] == values[4] and values[4] == values[7] and values[7] == symbol)
		return true;
	else if (values[2] == values[4] and values[4] == values[6] and values[6] == symbol)
		return true;
	else if (values[3] == values[4] and values[4] == values[5] and values[5] == symbol)
		return true;
	else if (values[0] == values[3] and values[3] == values[6] and values[6] == symbol)
		return true;
	else if (values[2] == values[5] and values[5] == values[8] and values[8] == symbol)
		return true;
	else if (values[0] == values[1] and values[1] == values[2] and values[2] == symbol)
		return true;
	else if (values[6] == values[7] and values[7] == values[8] and values[8] == symbol)
		return true;
	else 
		return false;
}
