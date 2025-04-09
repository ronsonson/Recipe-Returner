#include <iostream>
#include "Recipe.h"
bool userExit = false;

int main()
{
    bool valid = true;
    DisplayIntro();


        do {
            DisplayUI();
             valid = true;
             cout << "Please enter a command: " << endl;
            string userCommand = GetUserInput();

            if (userCommand == MEAL) {
                DisplayMeal();
            } else if (userCommand == PARAMETER) {
                DisplayParameters();

            } else if (userCommand == INGREDIENT) {
                DisplayIngredients();

            } else if (userCommand == HELP) {
                DisplayHelp();

            } else if (userCommand == SEARCH) {
                Search();

            } else if (userCommand == MENU) {
                DisplayUI();

            } else if (userCommand == EXIT) {
                cout << "Thank you for using the Recipe Returner" << endl;
                return 0;
            } else {
                cout << "invalid command, try again" << endl;
                valid = false;

            }
        } while (!valid);

    return 0;
}
