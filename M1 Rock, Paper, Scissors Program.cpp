// M1 Rock, Paper, Scissors Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
using namespace std;

void GetPlayerOption(int& option);
int GetRoundWinner(int &option, int &choice);
void UpdateScore(int result, int& option, int& choice);

int main()
{
	int option, choice;
	random_device engine;
	uniform_int_distribution<int> randomInt(1, 3);
	choice = randomInt(engine);

	GetPlayerOption(option);
	GetRoundWinner(option, choice);
	

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

int GetRoundWinner(int &option, int &choice)
{
	if ((option == 1 && choice == 3) ||
		(option == 2 && choice == 1) ||
		(option == 3 && choice == 2))
	{
		return 1;
	}
	if (option == choice)
	{
		return 0;
	}
	else
	{
		return 2;
	}
}

void UpdateScore(int result, int &option, int &choice)
{
	result = GetRoundWinner(option, choice);

}


