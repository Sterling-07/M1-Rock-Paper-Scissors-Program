// M1 Rock, Paper, Scissors Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
/* Date: 2/13/26
* Programmer: Philip Rodgers
* Program Name: Rock, Paper, Scissors Program
* Program Explanation: This is a rock, paper, scissors program that allows the player to pick from 4 options which are rock, paper, scissors, and quit. 
* The program generates the computer's choice within the game using the <random> library. Uisng functions, gets the players option, decides the winner 
* of a round, updates the score of the game, and displays the tournament winner at the end of the game based on the results. The player can choose to
* play again after a round or decide to quit if they want. If round end in a draw, the both scores stay the same and this is displayed. 
*/

//Create and include the necessary header files, such as #include <random> for the computer's choice in the game of rock, paper, scissors.
#include <iostream>
#include <random>
using namespace std;

/*Create necessary functions that will be used throughout the program to get the player's option, determine the round winner, update the score
* based on the round winner, and determine the overall tournament winner. */
void GetPlayerOption(int& option);
int GetRoundWinner(int &option, int &choice);
void UpdateScore(int &result, int& option, int& choice, int &player, int &computer);
void GetTournamentWinner(int &player, int &computer);

//Main function where all of the functions will be called from and used.
int main()
{
	//Create necessary variables for the program.
	int option, choice, player = 0, computer = 0, result, trial;

	//do while loop that allows the player to repeat the program. 
	do
	{
		//Variables created using the random library that allows the computer to pick its choice within the game.
		random_device engine;
		uniform_int_distribution<int> randomInt(1, 3);
		choice = randomInt(engine);

		//Function calls that operate and allow the game to work properly.
		GetPlayerOption(option);
		GetRoundWinner(option, choice);
		UpdateScore(result, option, choice, player, computer);
		//Display of the player and computer scores after each round. 
		cout << "Player score: " << player << "\n";
		cout << "Computer score: " << computer << "\n";

		//Allows the player to choose to quit the program or play again.
		cout << "Enter 1 if you would like to play again, enter 2 if you would like to quit the program.\n";
		cin >> trial;
		//If player chooses to quit the program, the tournament results are called and displayed here. 
		if (trial == 2)
		{
			cout << "Tournament Results: \n";
			GetTournamentWinner(player, computer);
		}
		//If the player doesn't enter 1 to play again or 2 to quit the program, this message is displayed. 
		if (trial > 2 || trial < 1)
		{
			cout << "Please enter either 1 to play again, or 2 to quit the program.\n";
		}

	} while (trial == 1);

	return 0;
}

//The function that enables the player to choose between rock, paper, scissors, or quit.
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
		//If player's option isn't between 1 - 4 then this message is displayed. 
		if (option < 1 || option > 4)
		{
			cout << "Please enter an option between 1 - 4.\n";
		}
	} while (option < 1 || option > 4);
}

//The function that determines the round winner based on the player and computer's options using if and if else statements.
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

//The function that updates the round scores using the results gathered from the GetRoundWinner function. 
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

/*This function determines the tournament winner using the information from the GetRoundWinner and UpdateScore functions
* in order to decide the winner and display the according message based on who has won, or if there was a draw.*/
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


