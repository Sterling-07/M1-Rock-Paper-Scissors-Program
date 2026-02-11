// M1 Rock, Paper, Scissors Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
using namespace std;

void GetPlayerOption(int& option);

int main()
{
	int option, choice;
	random_device engine;
	uniform_int_distribution<int> randomInt(1, 3);
	choice = randomInt(engine);

	GetPlayerOption(option);

	return 0;
}

void GetPlayerOption(int& option)
{
	do
	{
		cout << "Please select your option: \n";
		cout << "Option 1: Rock\n";
		cout << "Option 2: Paper\n";
		cout << "Option 3: Scissors\n";
		cout << "Option 4: Quit\n";
		cin >> option;
		if (option < 1 || option > 4)
		{
			cout << "Please enter an option between 1 - 4.\n";
		}
	} while (option < 1 || option > 4);
}


