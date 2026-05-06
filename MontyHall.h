#pragma once
#include <vector>
#include <utility>
#include <random>
#include <time.h>
#include <print>
#include <stdlib.h>
#include <fstream>
#include <format>

class MontyHall
{
private:
	int doors;
	int doorWithPrize;
	int chosenDoor;
	int stateChoice;
	int gamesPlayed;
	int loading;
	int numDoorsRevealed;
	//Pair holds if door is open and if door has the prize 
	std::vector <std::pair<bool, bool>> list;
	std::vector<bool> wins;

	enum {KEEPDOOR, SWAPDOOR};

	void populateDoors();
	void randomlyAssignPrize();
	int intRandomizer(int, int);
public:
	MontyHall(int numDoors, bool state, int doorsRevealed) {
		doors = numDoors;
		numDoorsRevealed = doorsRevealed;
		gamesPlayed = 0;
		loading = 0;
		list.resize(doors);
		randomlyAssignPrize();
		populateDoors();

		if (state)
			stateChoice = SWAPDOOR;
		else
			stateChoice = KEEPDOOR;
	};

	void playGame();
	void displayResults();

};

