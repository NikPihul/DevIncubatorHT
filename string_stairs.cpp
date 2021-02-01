#include <iostream>
using namespace std;
#define N 128

bool isSeparator (char c);

int main () {
	char text[N], word[N];
	char frequentChar = ' ';
	int i, iw = 0, wordAmount = 0, startIndex = 0, maxLength = 0, repeatCounter = 0, maxRepeats = 0;
	int wordLength[N] = {0};
	
	cout << "Input text: ";
	cin.getline(text, N);
	
	for (i = 0; text[i] != '\0'; i++) {
		if (!isSeparator(text[i])) {
			word[iw] = text[i];
			iw++;
			if (isSeparator(text[i+1]) or text[i+1] == '\0') {
				if (iw > maxLength) {
					maxLength = iw;
					startIndex = (i - iw + 1);
				}
				word[iw] = '\0';
				wordAmount++;
				cout << word << endl;
				iw = 0;
			}
		}
	}
	
	for (i = 0; text[i] != '\0'; i++) {
		for (int j = 0; text[j] != '\0'; j++) {
			if (text[i] == text[j]) {
				repeatCounter++;
				if (repeatCounter > maxRepeats) {
					maxRepeats = repeatCounter;
					frequentChar = text[i];
				}
			}
		}
		repeatCounter = 0;
	}
	
	cout << "There are " << wordAmount << " words in input line." << endl;
	
	if (maxLength == 0) {
		cout << "There are no words in input line" << endl;
	} else {
		cout << "The longest word is: ";
		for (i = startIndex; i < startIndex + maxLength; i++) {
			cout << text[i];
		}
		cout << endl;
	}
	
	cout << "Frequentest character is \"" << frequentChar << "\" it repeats " << maxRepeats << " times" << endl;
	
	return 0;
}

bool isSeparator (char c)
{
	char s[] = ",.! ?";
	for (int i = 0; s[i] != '\0'; i++)
		if (c == s[i])
			return true;
	return false;
}


