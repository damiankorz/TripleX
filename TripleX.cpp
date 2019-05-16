#include <iostream>

void LoadASCIIArt() 
{
    std::cout << " ___      ___ ___      ___ ___    ____ _________ ___        ___\n";
    std::cout << "|   \\    |   |   |    |   |   |  /   /|         |   \\      /   |\n";
    std::cout << "|    \\   |   |   |    |   |   | /   / |   ______|    \\    /    |\n";
    std::cout << "|     \\  |   |   |    |   |   |/   /  |  |      |     \\  /     |\n";
    std::cout << "|      \\ |   |   |    |   |       /   |  |______|      \\/      |\n";
    std::cout << "|       \\|   |   |    |   |      /    |         |              |\n";
    std::cout << "|   |\\       |   |    |   |      \\    |   ______|   |\\    /|   |\n";
    std::cout << "|   | \\      |   |    |   |       \\   |  |      |   | \\  / |   |\n";
    std::cout << "|   |  \\     |   |____|   |   |\\   \\  |  |______|   |  \\/  |   |\n";
    std::cout << "|   |   \\    |            |   | \\   \\ |         |   |      |   |\n";
    std::cout << "|___|    \\___|____________|___|  \\___\\|_________|___|      |___|\n\n";
}

void PrintIntro(int Difficulty)
{
    std::cout << "You are a clandestine operative tasked with disarming a nuclear warhead by bypassing a level " << Difficulty << " security layer...\n";
    std::cout << "You must bypass each security layer by entering the correct codes...\n\n";
}

bool PlayGame(int Difficulty)
{
    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    PrintIntro(Difficulty);

    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The code adds up to " << CodeSum << "\n";
    std::cout << "+ The product of the code is " << CodeProduct << "\n\n";

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nSecurity layer bypassed\n";
        return true;
    }
    else 
    {
        std::cout <<"\nAccess Denied\n";
        return false;
    }
}

int main()
{
    LoadASCIIArt();
    int LevelDifficulty = 1;
    const int MaxDifficulty = 10;

    while(LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if(bLevelComplete) 
        {
            ++LevelDifficulty;
        }
    }

    return 0;
}