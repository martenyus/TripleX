#include <iostream>
#include <ctime>

void PrintIntroduction()
{
    std::cout << "\n\nYou are hero trying to save princess from highest floor of dark tower!\n\n";
}

void BeforeLevel(int LevelDifficulty)
{
    std::cout << "You find yourself on " << LevelDifficulty << " floor of the tower\n";
    std::cout << "Before you is door with code lock on them!\n\n";
}


bool PlayGame(int LevelDifficulty)
{
    BeforeLevel(LevelDifficulty);

    int FirstDigit = rand() % (5 * LevelDifficulty) + 1;
    int SecondDigit = rand() % (5 * LevelDifficulty) + 1;
    int ThirdDigit = rand() % (5 * LevelDifficulty) + 1;

    int CodeSum = FirstDigit + SecondDigit + ThirdDigit;
    int CodeProduct = FirstDigit * SecondDigit * ThirdDigit;

    std::cout << "+ There are three numbers in the code\n+ These numbers multiplied together give "
     << CodeProduct << "\n+ These numbers adds-up to "<< CodeSum << std::endl;

    int FirstGuess, SecondGuess, ThirdGuess;
    std::cin >> FirstGuess >> SecondGuess >> ThirdGuess;
    std::cin.clear();
    std::cin.ignore();

    int GuessSum = FirstGuess + SecondGuess + ThirdGuess;
    int GuessProduct = FirstGuess * SecondGuess * ThirdGuess;

    // Check for correct guess
    if(GuessSum == CodeSum && CodeProduct == GuessProduct)
    {
        std::cout << "You guessed correctly\nDoor opens, and you continue to another floor...\n\n";
        return true;
    }else
    {
        std::cout << "Wrong! Better luck next time...\nWith that you have been thrown out of the tower.\n\n";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    PrintIntroduction();
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    while(LevelDifficulty < MaxDifficulty)
    {
        if(!PlayGame(LevelDifficulty))
        {
            std::cout << "Do you want to try again?(y/n)\n";
            char AnotherTry;
            std::cin >> AnotherTry;
            std::cin.clear();
            std::cin.ignore();
            if(AnotherTry == 'y')
            {
                LevelDifficulty = 1;
                continue;
            }
            LevelDifficulty = MaxDifficulty;
        }
        ++LevelDifficulty;
        if(LevelDifficulty == MaxDifficulty)
        {
            std::cout << "\n\nYou take the stairs to next floor only to find out that princess is long gone...\nAfter that, you leave the tower and get ready for another adventure!\n";
        }
    }
    return 0;
}
