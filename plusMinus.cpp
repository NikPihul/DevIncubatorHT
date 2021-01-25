#include <iostream>
using namespace std;
#define N 128

bool isDigit (char c);

int main () {
	char text[N];
	char answer[N];
	int number;
	cin.getline(text, N);
	
	for (int i = 0; text[i] != '\0'; i++) {
		if (isDigit(text[i])){
			number = text[i] - '0';
			if (number % 2 == 0) {
				for (int i = 0; i < number; i++) 
					cout << '+';
			} else 
				for (int i = 0; i < number; i++)
					cout << '-';
			i++;
		} else 
			cout << text[i];
	}
		
	return 0;
}

bool isDigit (char c)
{
	if (c >= '0' and c <= '9')
		return true;
	return false;
}
