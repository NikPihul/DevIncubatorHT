#include <iostream>
using namespace std;
#define N 128

bool isSeparator (char c);
bool isUnique (char word[], char wordList[]);

int main () {
	char text[N];
	char temp[N];
	char words[N] = {' '};
	int tempIndex = 0;
	bool isWordEnds = false;
	int carriage = 0;
	
	cout << "Input line: ";
	cin.getline(text, N);
	//hello
	for (int i = 0; text[i] != '\0'; i++) {
		if (!isSeparator(text[i])) {
			temp[tempIndex] = text[i];
			tempIndex++;
			
			if(text[i+1] == '\0' or isSeparator(text[i+1])) {
				temp[tempIndex] = '\0';
				tempIndex = 0;
				isWordEnds = true;
			}
		}
		if (isWordEnds) {
			if (isUnique (temp, words)) {
				for (int i = 0; temp[i] != '\0'; i++) {
					words[carriage] = temp[i];
					carriage++;
					if (temp[i+1] == '\0') {
						words[carriage] = ' ';
						carriage++;
					}	
				}
				
			}
		}
		isWordEnds = false;
	}
	
	for (int i = 0; words[i] != '\0'; i++)
		cout << words[i];
	
	return 0;
}

bool isSeparator (char c)
{
	char separatorList[] = " ";
	
	for (int i = 0; separatorList[i] != '\0'; i++)
		if (separatorList[i] == c)
			return true;
	return false;
}

bool isUnique (char word[], char wordList[])
{
	int j = 0;
	
	for (int i = 0; wordList[i] != '\0'; i++) {
		if (wordList[i] == word[j]) {
			if (wordList[i+1] == ' ' and word[j+1] == '\0')
				return false;
			j++;
		} else {
			j = 0;
		}
	}
	return true;
}
