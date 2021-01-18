#include <iostream>
using namespace std;
#define ARRAY_LENGTH 10

bool powerOfTwo (int num);
void printArray(int array[], int length);

int main ()
{
	int array[ARRAY_LENGTH] = {10, 20, 16, 40, 50, 60, 70, 64, 0, 2};
	
	cout << "Source array: ";
	printArray(array, ARRAY_LENGTH);
	
	cout << endl << "Elements, which is equal to power of 2: ";
	for (int i = 0; i < ARRAY_LENGTH; i++) {
		if (powerOfTwo(array[i]))
			cout << array[i] << " ";
	}
}

bool powerOfTwo (int num)
{
	while (num > 1) {
		if (num % 2 == 0)
			num /= 2;
		else 
			break;
	}
	if (num == 1)
		return true;
	else 
		return false;
}

void printArray(int array[], int length)
{	
	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	
	cout << endl;
}
