#include "MontyHall.h"

void MontyHall::populateDoors()
{
	for (auto& door : list)
	{
		door.first = false;
		door.second = false;
	}

	list[doorWithPrize].second = true;

}

void MontyHall::randomlyAssignPrize()
{
	doorWithPrize = intRandomizer(0, doors - 1);
	return;
}

int MontyHall::intRandomizer(int min, int max)
{
	static std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution range(min, max);
	return range(generator);
}

void MontyHall::playGame()
{
	//Print out we are playing the game
	gamesPlayed++;
	//system("cls");
	std::println("Playing Game number {} {:.{}}", gamesPlayed, "..........", loading);
	loading++;
	loading = (loading >= 10) ? 0 : loading;

	//Randomly choose a door
	chosenDoor = intRandomizer(0, doors - 1);

	//Randomly open a door
	int revealedDoor = intRandomizer(0, doors - 1);
	while (revealedDoor == chosenDoor || revealedDoor == doorWithPrize)
	{
		revealedDoor = intRandomizer(0, doors - 1);
	}

	list[revealedDoor].first = true;

	int revealedDoorTwo = intRandomizer(0, doors - 1);
	if (numDoorsRevealed > 1)
	{
		
		while (revealedDoorTwo == chosenDoor || revealedDoorTwo == revealedDoor)
		{
			revealedDoorTwo = intRandomizer(0, doors - 1);
		}

	}

	//Does player want to open door?
	//Always keep
	
	switch (stateChoice)
	{
	case KEEPDOOR:
		if (chosenDoor == doorWithPrize)
			wins.push_back(true);
		else
			wins.push_back(false);

		break;

	case SWAPDOOR:
		int newChosenDoor = intRandomizer(0, doors - 1);

		if (numDoorsRevealed > 1 && doors > 3)
		{
			while (newChosenDoor == chosenDoor || newChosenDoor == revealedDoor || newChosenDoor == revealedDoorTwo)
			{
				newChosenDoor = intRandomizer(0, doors - 1);
			}
		}
		else
		{
			while (newChosenDoor == chosenDoor || newChosenDoor == revealedDoor)
			{
				newChosenDoor = intRandomizer(0, doors - 1);
			}
		}

		if (numDoorsRevealed > 1 && (revealedDoorTwo == doorWithPrize || doors == 3))
			newChosenDoor = doorWithPrize;

		if (newChosenDoor == doorWithPrize)
			wins.push_back(true);
		else
			wins.push_back(false);
		
		break;
	}
}

void MontyHall::displayResults()
{
	int numWins = 0;
	int numLosses = 0;
	std::ofstream file("Results.txt", std::ios::app);

	
	std::println("Processing Wins {:.{}}", "..........", loading);
	loading++;
	loading = (loading >= 10) ? 0 : loading;


	for (const auto& a : wins)
	{
		if (a)
			numWins++;
		else
			numLosses++;
	}

	std::println("Out of {} games, You won {} times and lost {} times", wins.size(), numWins, numLosses);
	
	if(file.is_open())
	{
		file << std::format("Game with {} doors, and Door Reveal is {}, Out of {} games, You won {} times and lost {} times.\n", doors, stateChoice, wins.size(), numWins, numLosses);
	}


	file.close();

	return;
}
