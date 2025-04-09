//
// Created by Ronson on 10/25/2023.
//

#ifndef RECIPEUI_RECIPE_H
#define RECIPEUI_RECIPE_H
#include <thread>
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
const int MAX_INGREDIENTS = 15;
const int MAX_MEALS = 10;
const int MAX_RECIPE_INGREDIENTS = 5;
const int MAX_RECIPES = 10;
const int MAX_PARAMETERS = 3;
const int MAX_RETURN_ARRAY = 10;

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
