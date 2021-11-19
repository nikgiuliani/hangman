#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string word;
    string wordHolder;
    string letterGuess;
    int i;
    int guessIndex;
    const int RANDOM_WORDS = 10;
    bool quit;
    string userInput;
    vector<string> wrongGuesses;
    quit = false;

    cout << "Welcome to Hang Man!" << endl;

    while (!quit) {
        int numCorrectGuesses = 0;
        int numWrongGuesses = 0;
        string responsesB[RANDOM_WORDS]{
                "Ape",
                "Fat",
                "Superman",
                "Math",
                "Simple",
                "Jupiter",
                "Peach",
                "Car",
                "Tesla",
                "McDonalds"};
        srand(time(nullptr));
        word = (responsesB[rand() % RANDOM_WORDS]);
        wordHolder = word;

        for (i = 0; i < word.size(); ++i) {
            if (word.at(i) != ' ') {
                word.at(i) = '_';
            }
        }

        while (word.find('_') != string::npos) {
            cout << "Enter a letter guess: " << endl;
            cin >> letterGuess;
            guessIndex = wordHolder.find(letterGuess);
            if (guessIndex != string::npos) {
                word.replace(wordHolder.find(letterGuess), 1, letterGuess);
                ++numCorrectGuesses;
            }
            else {
                cout << "Wrong! Here's all the incorrect guesses" << endl;
                wrongGuesses.insert(wrongGuesses.end(), letterGuess);
                wrongGuesses.insert(wrongGuesses.end(), " ");
                for (i = 0; i < wrongGuesses.size(); ++i) {
                    cout << wrongGuesses.at(i);
                }
                ++numWrongGuesses;
                cout << endl;
            }
            cout << "Number of Correct Guesses: " << numCorrectGuesses << endl;
            cout << "Number of Wrong Guesses: " << numWrongGuesses << endl;
            cout << word << endl;
        }
        cout << "You got it! Well done!! " << endl << "Total guesses: " << numCorrectGuesses + numWrongGuesses << endl;
        cout << "Thanks for playing!" << endl << "Would you like to play again? Type yes or no" << endl;
        cin >> userInput;
        if (userInput == "no" || userInput == "No") {
            quit = true;
        }
        else {
            continue;
        }
    }

    cout << "Have a great day!" << endl;
    return 0;
}
