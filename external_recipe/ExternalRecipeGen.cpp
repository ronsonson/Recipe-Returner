// Created by cabo_ on 11/20/2023.
//

#include "ExternalRecipeGen.h"

int main()
{
    auto quit = false;
    while(!quit)
    {
        ExternalRecipeGen::waitForMeal();

        std::string userInput;
        std::cout << "Enter 'quit' to exit, or press Enter to wait for another recipe: ";
        std::getline(std::cin, userInput);

        if (userInput == "quit") {
            quit = true;
        }
    }

};
