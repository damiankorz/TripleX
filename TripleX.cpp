#include <iostream>

void PrintIntro()
{
    std::cout << "You are a clandestine operative tasked with hacking a secure mainframe...\n";
    std::cout << "You must enter the correct codes to continue...\n";
}

int main()
{
    const int CodeA = 4;
    const int CodeB = 3;
    const int CodeC = 2;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    PrintIntro();

    std::cout << "\n+ There are 3 numbers in the code\n";
    std::cout << "+ The code adds up to " << CodeSum << "\n";
    std::cout << "+ The product of the code is " << CodeProduct << "\n";

    int GuessA, GuessB, GuessC;

    std::cout << "Enter the code:\n";
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    return 0;
}