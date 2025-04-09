//
// Created by Ronson on 10/25/2023.
//

#ifndef RECIPEUI_RECIPE_H
#define RECIPEUI_RECIPE_H

#include <iostream>
#include <fstream>
using namespace std;



const string PARAMETER = "parameters";
const string INGREDIENT = "ingredients";
const string MEAL = "meals";
const string SEARCH = "search";
const string HELP = "help";
const string MENU = "menu";
const string EXIT = "exit";

void DisplayIntro();
void DisplayUI();
void DisplayParameters();
void DisplayIngredients();
void DisplayHelp();
void DisplayMeal();
void Search();

string GetUserInput();
void writeToFile(const string& meal);


#endif //RECIPEUI_RECIPE_H
