#include <iostream>
#include <ctime>

void LoadASCIIArt() 
{
    std::cout << " ___      ___ ___      ___ ___    ____ _________ ___        ___\n";
    std::cout << "|   \\    |   |   |    |   |   |  /   /|         |   \\      /   |\n";
    std::cout << "|    \\   |   |   |    |   |   | /   / |    _____|    \\    /    |\n";
    std::cout << "|     \\  |   |   |    |   |   |/   /  |   |     |     \\  /     |\n";
    std::cout << "|      \\ |   |   |    |   |       /   |   |_____|      \\/      |\n";
    std::cout << "|       \\|   |   |    |   |      /    |         |              |\n";
    std::cout << "|   |\\       |   |    |   |      \\    |    _____|   |\\    /|   |\n";
    std::cout << "|   | \\      |   |    |   |       \\   |   |     |   | \\  / |   |\n";
    std::cout << "|   |  \\     |   |____|   |   |\\   \\  |   |_____|   |  \\/  |   |\n";
    std::cout << "|   |   \\    |            |   | \\   \\ |         |   |      |   |\n";
    std::cout << "|___|    \\___|____________|___|  \\___\\|_________|___|      |___|\n\n";
}

void PrintIntro(int Difficulty)
{
    if(Difficulty == 1)
    {
        std::cout << "\nYou are a clandestine operative tasked with disarming a nuclear warhead by bypassing a level " << Difficulty << " security layer...\n";
        std::cout << "You must bypass each security layer by entering the correct codes...\n\n";
    }
    else
    {
        std::cout << "\nBypass level " << Difficulty << " security...\n";
    }
}

bool PlayGame(int Difficulty)
{
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    PrintIntro(Difficulty);

    std::cout << "\n+ There are 3 numbers in the code\n";
    std::cout << "+ The code adds up to " << CodeSum << "\n";
    std::cout << "+ The product of the code is " << CodeProduct << "\n\n";

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n++ Security layer " << Difficulty  << " bypassed\n";
        return true;
    }
    else 
    {
        std::cout <<"\n++ Access Denied\n";
        return false;
    }
}

int main()
{
    LoadASCIIArt();
    srand(time(NULL)); // Creates new random sequence based on time of day
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

    std::cout << "\nAll security layers bypassed. Override accepted. Nuclear warhead disarmed.";

    return 0;
}