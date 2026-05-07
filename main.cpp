//Monty Hall Simulation

#include <iostream>
#include "MontyHall.h"

using namespace std;

int main()
{
    //Argument 1 numOfDoors, argument 2 Keep/Swap, argument 3 numDoorRevealed
    MontyHall game(6, false, 1);
    MontyHall gameTwo(6, true, 1);

    MontyHall gameThree(9, false, 1);
    MontyHall gameFour(9, true, 1);

    MontyHall gameFive(20, false, 1);
    MontyHall gameSix(20, true, 1);

    MontyHall gameSeven(100, false, 1);
    MontyHall gameEight(100, true, 1);

    MontyHall gameNine(3, false, 1);
    MontyHall gameTen(3, true, 1);

    for (int i = 0; i < 100000; i++)
    {
        game.playGame();
        gameTwo.playGame();
    }
    system("cls");
    game.displayResults();
    gameTwo.displayResults();

    for (int i = 0; i < 100000; i++)
    {
        gameThree.playGame();
        gameFour.playGame();
    }

    system("cls");
    gameThree.displayResults();
    gameFour.displayResults();

    for (int i = 0; i < 100000; i++)
    {
        gameFive.playGame();
        gameSix.playGame();
    }

    system("cls");
    gameFive.displayResults();
    gameSix.displayResults();

    for (int i = 0; i < 100000; i++)
    {
        gameSeven.playGame();
        gameEight.playGame();
    }

    system("cls");
    gameSeven.displayResults();
    gameEight.displayResults();

    for (int i = 0; i < 100000; i++)
    {
        gameNine.playGame();
        gameTen.playGame();
    }

    system("cls");
    gameNine.displayResults();
    gameTen.displayResults();

    exit(EXIT_SUCCESS);
}
