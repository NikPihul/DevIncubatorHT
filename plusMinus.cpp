#include <iostream>
using namespace std;
#define N 128
#define EVEN_SYMBOL '+'
#define UNEVEN_SYMBOL '-'

void changeDigit (char array[], int amount, int startPosition, char symbol);
int strLength (char array[]);
bool isDigit(char c);
void deleteSymbol (char array[], int position);

int main () {
	char text[N];
	int amount;
	
	cout << "Input text: ";
	cin.getline(text, N);
	
	for (int j = 0; text[j] != '\0'; j++) {
		if (isDigit(text[j])) {
			amount = text[j] - '0';
			if (amount == 0) {
				deleteSymbol(text, j);
				j--;
			} else if (amount % 2 == 0) {
				changeDigit(text, amount, j, EVEN_SYMBOL);
				j += amount - 1;
			} else {
				changeDigit(text, amount, j, UNEVEN_SYMBOL);
				j += amount - 1;
			} 
		}
	}
	
	cout << text;
	
	return 0;
}

void changeDigit (char array[], int amount, int startPosition, char symbol)
{
	int currentSize = strLength(array);
	int lastDigit = currentSize - 1;
	int newSize = currentSize + amount - 1;

	for (int i = newSize - 1; i >= startPosition; i--) {
		if (i < startPosition + amount) {
			array[i] = symbol;
		} else 
			array[i] = array[lastDigit];
			lastDigit--;
	}
}

int strLength (char array[])
{
	int i;
	
	for (i = 0; array[i] != '\0'; i++){
	}
	
	return i;
}

bool isDigit(char c)
{
	if (c >= '0' and c <= '9')
		return true;
	return false;
}

void deleteSymbol (char array[], int position)
{
	int lastIndex = strLength(array) - 1;
	
	for (int i = position; array[i] != '\0'; i++) {
		array[i] = array[i + 1];
	}
	
	array[lastIndex] = 0;
}
