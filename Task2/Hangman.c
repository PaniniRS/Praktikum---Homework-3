#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

#define ArraySize(array) ( sizeof((array)) / sizeof((array[0])) )
const char *words[] = { "apple", "banana", "pear", "grape", "orange" };

// Art for stickman figure, stored in hangman string array
const char *hangman[] = {
    "   ____\n"
    "   |   |\n"
    "   |   O\n"
    "   |\n"
    "   |\n"
    "   |\n"
    " __|__\n",
    "   ____\n"
    "   |   |\n"
    "   |   O\n"
    "   |   |\n"
    "   |\n"
    "   |\n"
    " __|__\n",
    "   ____\n"
    "   |   |\n"
    "   |   O\n"
    "   |  /|\n"
    "   |\n"
    "   |\n"
    " __|__\n",
    "   ____\n"
    "   |   |\n"
    "   |   O\n"
    "   |  /|\\\n"
    "   |\n"
    "   |\n"
    " __|__\n",
    "   ____\n"
    "   |   |\n"
    "   |   O\n"
    "   |  /|\\\n"
    "   |  /\n"
    "   |\n"
    " __|__\n",
    "   ____\n"
    "   |   |\n"
    "   |   O\n"
    "   |  /|\\\n"
    "   |  / \\\n"
    "   |\n"
    " __|__\n"
};

int main(){
    srand(time(NULL));  // seed the random number generator
    char userLettersGuessed[26] = {0};  // array to store tried letters
    int userLettersGuessedCount = 0;  // number of tried letters
    char userGuess;
    int userWrongGuesses = 0;
    int* pUserWrongGuesses = 0;
    char* randomWord = words[rand() % ArraySize(words)];
    int randomWordLength = strlen(randomWord);
    char guessArray[randomWordLength + 1];
    
    //fills guessArray with _
    for (int i = 0; i < randomWordLength; i++) {
        guessArray[i] = '_';  
    }


    printf("Random word selected: %s", randomWord);

    while (userWrongGuesses < 6){
        printf("Word: %s\n", guessArray); 

    
        printf("\nEnter a letter: ");
        scanf(" %c", &userGuess);

        //check if the letter has already been guessed
        int letterAlreadyGuessed = 0;
        for (int i = 0; i < userLettersGuessedCount; i++) {
            if (userLettersGuessed[i] == userGuess) {
                letterAlreadyGuessed = 1;  
                break;
            }
        }
        
        //if it has already been guessed inform the user for that
        if (letterAlreadyGuessed) {
            printf("You have already guessed '%c'. Try a different letter.\n", userGuess);
            continue;  
        }

        //Adds the guess to the list of guessed letters
        userLettersGuessed[userLettersGuessedCount++] = userGuess;

        //check if the guessed letter is correct
        int correct = 0;  // flag to store if the letter is correct or not
        for (int i = 0; i < randomWordLength; i++) {
            if (randomWord[i] == userGuess) {
                guessArray[i] = userGuess;  
                correct = 1;  
            }
        }
        //if the guessed letter is wrong
        if (!correct) {  
            userWrongGuesses++;  
            printf("Incorrect! %d mistakes out of %d allowed.\n", userWrongGuesses, 6);
            printf("%s", hangman[userWrongGuesses - 1]);  // print the stick figure
        }

        //compares the guessed word with the random selected word
        if (strcmp(guessArray, randomWord) == 0) { 
            printf("You won! The word was %s.\n", randomWord);
            break; 
        }
    }

    return 0;
}
