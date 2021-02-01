#include <iostream>
using namespace std;
#define N 128

int main () {
	char word[] = "hello";
	char shownWord[N] = {' '};
	char letter;
	bool isLettersHidden = true;
	bool isWordHidden = true;
	
	for(int i = 0; word[i] != '\0'; i++) {
		shownWord[i] = '*';
	}
	
	while(isWordHidden) {
		cout << shownWord;
		
		cout << endl;
		cout << "Input letter: ";
		cin >> letter;
		
		for (int i = 0; word[i] != '\0'; i++) {
			if (word[i] == letter) {
				shownWord[i] = letter;
				isLettersHidden = false;
			}	
		}
		
		for (int i = 0; shownWord[i] != '\0'; i++) {
			if (shownWord[i] == '*')
				isLettersHidden = true;
		}
		
		for (int i = 0; shownWord[i] != '\0'; i++) {
			if (shownWord[i] == word[i])
				isWordHidden = false;
			else {
				isWordHidden = true;
				break;
			}
		}
		
		if (!isWordHidden) {
			system("cls");
			cout << "Congratulations! The word is: " << shownWord << endl;
			cout << "And before us is the finalist of the capital show \"Field of Miracles\"." << endl;
			cout << "Prizes for the three players in the studio!";
		}
	}
	return 0;
}
