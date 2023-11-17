#include <iostream>
#include "Recipe.h"
bool userExit = false;

int main()
{
    bool valid = true;
    DisplayIntro();
    do {


        do {
            DisplayUI();
             valid = true;
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
                userExit = true;
            } else {
                cout << "invalid command, try again" << endl;
                valid = false;

            }
        } while (!valid);

    }while (!userExit);
    return 0;
}
