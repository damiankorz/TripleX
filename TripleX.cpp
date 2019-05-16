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

void PrintIntro(int LevelDifficulty)
{
    if(LevelDifficulty == 1)
    {
        std::cout << "\nYou are a secret agent tasked with disarming a nuclear warhead by bypassing a level " << LevelDifficulty << " security layer...\n";
        std::cout << "You must bypass each security layer by entering the correct codes...\n\n";
    }
    else
    {
        std::cout << "\nBypass level " << LevelDifficulty << " security...\n";
    }
}

bool PlayGame(int LevelDifficulty, int Attempts)
{
    const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeC = rand() % LevelDifficulty + LevelDifficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    PrintIntro(LevelDifficulty);

    std::cout << "\n+ There are 3 numbers in the code\n";
    std::cout << "+ The code adds up to " << CodeSum << "\n";
    std::cout << "+ The product of the code is " << CodeProduct << "\n\n";

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n++ Security layer " << LevelDifficulty  << " bypassed\n";
        return true;
    }
    else 
    {
        std::cout <<"\n++ Access Denied\n";
        std::cout <<"++ WARNING! You have " << Attempts - 1 << " remaining attempt(s) before detonation\n";
        return false;
    }
}

int SetGameDifficulty()
{
    std::cout << "Please select difficulty\n\n";
    std::cout << "++ 1 - Easy\n";
    std::cout << "++ 2 - Normal\n";
    std::cout << "++ 3 - Hard\n\n";

    int GameDifficulty;

    std::cin >> GameDifficulty;

    return GameDifficulty;
}

int main()
{
    LoadASCIIArt();
    srand(time(NULL)); // Creates new random sequence based on time of day

    int GameDifficulty = SetGameDifficulty();
    int LevelDifficulty = 1;
    int Attempts, Difficulty;

    switch(GameDifficulty)
    {
        case 1: 
            Attempts = 8;
            Difficulty = 3;
            break;
        case 2:
            Attempts = 5;
            Difficulty = 5;
            break;
        case 3: 
            Attempts = 3;
            Difficulty = 8;
            break;
        default:
            Attempts = 5;
            Difficulty = 5;
            break;
    }
    
    const int MaxDifficulty = Difficulty;

    while(LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty, Attempts);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if(bLevelComplete) 
        {
            ++LevelDifficulty;
        }
        else 
        {
            --Attempts;
        }

        if(Attempts == 0)
        {
            std::cout << "\nThe warhead detonated and you were burned to a crisp!\n";
            std::getchar();
            return 0;
        }
    }

    std::cout << "\nSecurity protocal override initiated. Warhead disarmed.\n";
    std::cout << "Congrats Agent, just another walk in the park.\n";

    std::getchar();
    return 0;
}