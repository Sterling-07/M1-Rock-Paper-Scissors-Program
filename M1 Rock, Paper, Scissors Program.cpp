// M1 Rock, Paper, Scissors Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
using namespace std;

void GetPlayerOption(int& option);
int GetRoundWinner(int &option, int &choice);
void UpdateScore(int &result, int& option, int& choice, int &player, int &computer);
void GetTournamentWinner(int &player, int &computer);

int main()
{
	int option, choice, player = 0, computer = 0, result, trial;

	do
	{
		random_device engine;
		uniform_int_distribution<int> randomInt(1, 3);
		choice = randomInt(engine);

		GetPlayerOption(option);
		GetRoundWinner(option, choice);
		UpdateScore(result, option, choice, player, computer);
		cout << "Player score: " << player << "\n";
		cout << "Computer score: " << computer << "\n";

		cout << "Enter 1 if you would like to play again, enter 2 if you would like to quit the program.\n";
		cin >> trial;
		if (trial == 2)
		{
			cout << "Tournament Results: \n";
			GetTournamentWinner(player, computer);
		}
		if (trial > 2 || trial < 1)
		{
			cout << "Please enter either 1 to play again, or 2 to quit the program.\n";
		}

	} while (trial == 1);

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

void UpdateScore(int &result, int &option, int &choice, int &player, int &computer)
{
	result = GetRoundWinner(option, choice);
	if (result == 1)
	{
		player++;
	}
	if (result == 2)
	{
		computer++;
	}
}

void GetTournamentWinner(int& player, int& computer)
{
	if (player > computer)
	{
		cout << "The player has won the tournament.\n";
		cout << "The player had a total of " << player << " win(s).\n";
	}
	if (player < computer)
	{
		cout << "The computer has won the tournament.\n";
		cout << "The computer had a total of " << computer << " win(s).\n";
	}
	if (player == computer)
	{
		cout << "The tournament has ended in a draw.\n";
	}
}


