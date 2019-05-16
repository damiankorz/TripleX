#include <iostream>

void PrintIntro()
{
    std::cout << " ___      ___ ___      ___ ___    ____ _________ ___        ___    ____          ____\n";
    std::cout << "|   \\    |   |   |    |   |   |  /   /|         |   \\      /   |   \\   \\        /   /\n";
    std::cout << "|    \\   |   |   |    |   |   | /   / |   ______|    \\    /    |    \\   \\      /   /\n";
    std::cout << "|     \\  |   |   |    |   |   |/   /  |  |      |     \\  /     |     \\   \\    /   /\n";
    std::cout << "|      \\ |   |   |    |   |       /   |  |______|      \\/      |      \\   \\  /   / \n";
    std::cout << "|       \\|   |   |    |   |      /    |         |              |       \\   \\/   /\n";
    std::cout << "|   |\\       |   |    |   |      \\    |   ______|   |\\    /|   |       /        \\\n";
    std::cout << "|   | \\      |   |    |   |       \\   |  |      |   | \\  / |   |      /    /\\    \\\n";
    std::cout << "|   |  \\     |   |____|   |   |\\   \\  |  |______|   |  \\/  |   |     /    /  \\    \\\n";
    std::cout << "|   |   \\    |            |   | \\   \\ |         |   |      |   |    /    /    \\    \\\n";
    std::cout << "|___|    \\___|____________|___|  \\___\\|_________|___|      |___|   /____/      \\____\\\n\n";

    std::cout << "You are a clandestine operative tasked with disarming a nuclear warhead...\n";
    std::cout << "You must bypass each security layer by entering the correct codes...\n\n";
}

void PlayGame()
{
    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    PrintIntro();

    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The code adds up to " << CodeSum << "\n";
    std::cout << "+ The product of the code is " << CodeProduct << "\n\n";

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You win!\n";
    }
    else 
    {
        std::cout << "Incorrect code entered\n";
    }
}

int main()
{
    PlayGame();

    return 0;
}