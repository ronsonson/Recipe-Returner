// Created by cabo_ on 11/20/2023.
//

#pragma once

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>


static std::unordered_map<std::string, std::string> GlobalRecipes = {
        {"pancakes",                    "https://www.allrecipes.com/recipe/21014/good-old-fashioned-pancakes/"},
        {"breakfast-burritos",          "https://www.favfamilyrecipes.com/ham-and-cheese-breakfast-burritos/"},
        {"bean-and-cheese burritos",    "https://www.isabeleats.com/bean-and-cheese-burritos/"},
        {"BLT-sandwich",                "https://natashaskitchen.com/blt-sandwich/"},
        {"quesadillas",                 "https://www.recipetineats.com/quesadilla/"},
        {"tacos",                       "https://houseofyumm.com/best-ever-taco-meat/"},
        {"burgers",                     "https://www.aspicyperspective.com/best-hamburger-patty-recipe/"},
        {"sloppy-joes",                 "https://natashaskitchen.com/sloppy-joe-recipe/"},
        {"rice-bowls",                  "https://insanelygoodrecipes.com/rice-bowl-recipes/"},
        {"french-fries",                "https://www.wellplated.com/baked-fries/"}
};


class ExternalRecipeGen {
public:
    static inline void waitForMeal() {
        std::string mealName;

        // Wait for recipe-service.txt to have content
        while (true) {
            std::ifstream file("../recipe-service.txt");
            if (file.peek() != std::ifstream::traits_type::eof()) {
                file.close();
                break;
            }
            file.close();

            std::cout << "Waiting for file to have content..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }



        // Read the meal name from recipe-service.txt
        std::ifstream file("../recipe-service.txt");
        file >> mealName;
        file.close();

        std::string newRecipeLink = GlobalRecipes[mealName];

        // Write the recipe link to the file
        std::ofstream outFile("../recipe-service.txt");
        outFile.clear();
        outFile << newRecipeLink;
        outFile.close();

        std::cout << "Recipe written successfully." << std::endl;
    }
};
