cmake_minimum_required(VERSION 3.20)
project(RecipeUI)

set(CMAKE_CXX_STANDARD 23)

add_executable(RecipeUI main.cpp Recipe.cpp Recipe.h)
add_subdirectory(external_recipe)
