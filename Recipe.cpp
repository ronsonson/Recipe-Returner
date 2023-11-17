//
// Created by Ronson on 10/25/2023.
//

#include "Recipe.h"
string mealArray[10] = {"pancakes", "breakfast-burritos", "bean-and-cheese burritos", "BLT-sandwich",
                          "quesadillas", "tacos", "burgers", "sloppy-joes", "rice-bowls", "french-fries"};

string parameterArray[3] = {"", "", ""};
string ingredientArray[30] = {"flour", "tortillas", "beans", "bread", "bacon", "cheese", "potatoes", "ground-beef", "buns", "rice", "milk", "vegetable-oil"
, "eggs", "tomatoes", "lettuce", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
string mealRecipeArray[20][5] = {"pancakes", "flour", "milk", "eggs","",
                                 "breakfast-burritos", "eggs", "tortillas", "potatoes", "cheese",
                                 "bean-and-cheese-burritos", "beans", "cheese", "tortillas", "",
                                 "BLT-sandwich", "bread", "bacon", "tomato", "lettuce",
                                 "quesadillas", "tortillas", "cheese", "", "",
                                 "tacos", "tortillas", "rice", "beans", "ground-beef",
                                 "burgers", "buns", "ground-beef", "cheese", "lettuce",
                                 "sloppy-joes", "buns", "cheese", "ground-beef", "",
                                 "rice-bowls", "rice", "beans", "tomatoes", "lettuce",
                                 "french-fries", "potatoes", "vegetable-oil", "", ""

                                 };
string returnArray[10];
void DisplayIntro()
{
    cout << "Welcome to the Recipe Returner! \nThis program is designed to help you decide what you want to eat! Or perhaps use up pesky ingredients laying around that you are unsure what to make with!" << endl;
}
void DisplayUI()
{
    cout << "Available commands:" << endl;
    cout << " 'Parameters' To view current, and add new search parameters \n 'Ingredients' To view the list of ingredients recognized as search parameters\n 'meals' to view all meals in the database "
            "\n 'Search' to search for meals in the database that use the current ingredients added as parameters\n 'help' To get detailed help on how to use the program.\n 'Exit' to exit the program."<< endl;
}
string GetUserInput()
{
    string userCommand;

        cout << "Input a command: " << endl;
        cin >> userCommand;
        for (int i = 0; i < userCommand.length(); i++) {
            userCommand[i] = tolower(userCommand[i]);
        }

    return userCommand;
}

void DisplayParameters()
{
    bool menu = false;
    bool valid = true;
    string userInput;
    do
    {


    cout << "Current search parameters are: " << endl;
    for(int i =0; i < 3; i++)
    {
        cout << "Parameter "<< i+1 << ": " << parameterArray[i] << endl;
    }

        cout << "To add a search parameter enter a valid ingredient (3 parameter max) "
                "Or enter 'menu' to return to the main menu. To clear parameters enter 'clear' (You must return to main menu before searching)\n"
                "The more search parameters you add the fewer meals will return upon searching. Search with less parameters to be given more meal options. " << endl;
    do
    {
        bool added = false;
        valid = true;
        cin >> userInput;
        for (int i = 0; i < userInput.length(); i++)
        {
            userInput[i] = tolower(userInput[i]);
        }

        for (int i =0; i <30; i++)
        {
            bool done = false;
            if (userInput == ingredientArray[i])
            {
                int k =0;
                while(!done)
                {
                    if (parameterArray[k].empty())
                    {
                        parameterArray[k] = userInput;
                        done = true;
                        added = true;
                        cout << "Parameter Added!" << endl;
                    }
                    else
                    {
                        if (k == 3)
                        {
                            cout << "Parameters full! clear parameters then add new ones" << endl;
                            done = true;
                        }
                        k++;
                    }
                }
            }
        }
        if (userInput == "clear")
        {
            for (int i =0; i<3; i++)
            {
                parameterArray[i] = "";
            }
            cout << "Parameters cleared!" << endl;
        }
        else if (userInput == MENU)
        {
            menu = true;
            cout << "Returning to menu..." << endl;
        }
        else if (!added and userInput != "clear")
        {
            cout << "Invalid command try again" << endl;
            valid = false;
        }



    }
    while(!valid);
    }
    while(!menu);



}
void DisplayIngredients()
{
    cout << "Current ingredients recognized in the database are: " << endl;

    for (int i =0; i<12; i++)
    {
        cout << ingredientArray[i] << endl;
    }
}
void DisplayHelp()
{
    cout <<"help:" << endl;
    cout << "This program is designed to help you use a specific ingredient or two for a meal, "
            "as well as help you choose what to make. \n Steps to use:" << endl;
    cout << "Step 1: It is recommended to take a look at our meal list using the 'recipe' command as well as look at "
            " our ingredient list by using the 'ingredients' command. This way you know what ingredients and recipes are recognized as commands."
            "\n Step 2: Use the 'parameters' command to see current search parameters and add/remove them. After using the parameters command you can "
            "add recognized ingredients (viewed using the 'ingredients' command as search parameters to find meals."
            "\n Step 3: Once you have ingredients added as search parameters, you can search for meals that use those ingredients using the 'search' command from the main menu."
            "\n (To be implemented still) Step 4: Once you search for meals you can retrieve recipes for them in the search window using the recipe name as a command" << endl;
}
void DisplayMeal()
{
    cout << "Current meals in the database are: " << endl;

    for (int i =0; i<10; i++)
    {
        cout << mealArray[i] << endl;
    }
}
void Search()
{
    if (parameterArray[0].empty())
    {
        cout << "No search parameters. Use 'parameters' command to add parameters before searching" << endl;

    }
    else
    {
        int n = 0;
        for (int i =0; i < 10; i++)
        {
            for (int k =0; k < 5; k++)
            {
                for(int j =0; j <3; j++)
                {
                    if (mealRecipeArray[i][k] == parameterArray[j] and parameterArray[j] != "")
                    {
                        if (returnArray[n-1] != mealRecipeArray[i][0] )
                        {
                            returnArray[n] = mealRecipeArray[i][0];
                            n++;
                        }
                    }
                }
            }

        }


        cout << "Search results are:" << endl;
        for (int i =0; i < 10; i++)
        {
            if (returnArray[i] != "")
            {

                cout << i+1 << ". " << returnArray[i] << endl;

            }
        }
        bool done = false;
        bool valid;
        while (!done) {
            cout << "You may enter one of the search result meals as a command to open an external recipe for it.\n"
                    "(Recommended: You can simply copy and paste the name of the meal and hit enter)"
                    " Or you can input 'menu' to return to the main menu" << endl;
            do
            {
                 valid = false;
                string userInput = GetUserInput();

                for (int i=0 ; i < 10; i++)
                {
                    if (userInput == returnArray[i] or userInput == "menu")
                    {
                        valid = true;
                    }
                }
                    if (!valid)
                    {
                        cout << "Invalid command, try again." << endl;
                        valid = false;
                    }

                if (userInput == "menu")
                {
                    done = true;
                    cout <<"Returning to main menu..." << endl;
                }
                else if (valid and !done)
                {
                    writeToFile(userInput);
                }
            } while (!valid);
        }
    }

}
void writeToFile(string meal)
{
ofstream mealOut;
mealOut.open("recipe-service.txt");
mealOut << meal;
mealOut.close();
}