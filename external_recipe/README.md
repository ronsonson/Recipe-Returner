# ExternalRecipeGen

ExternalRecipeGen can be used to retrieve external links to meal recipes.

## Usage

When REQUESTING a link for a certain meal, consider the example below:

```cpp
std::string mealName = GetUserInput();
ofstream mealOut;

mealOut.open("recipe-service.txt");
mealOut << meal;
mealOut.close();
std::this_thread::sleep_for(std::chrono::seconds(2)); // wait for service to write link
```
After the wait period, you should be good to RECIEVE the link from the same file, as follows:

```cpp
// create a ifstream to hold the text from file and a string to hold the link
ifstream linkIn;
string link;

//open file, extract link into link string
linkIn.open("recipe-service.txt");
linkIn >> link;

// diplay to user
cout << "Requested recipe for " << meal << endl;
cout << "Copy and paste this link into your browser: " << link << endl;

// clear and close the file for later use
linkIn.clear();
linkIn.close();
```
