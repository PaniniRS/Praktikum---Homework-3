#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

#define ArraySize(array) ( sizeof((array)) / sizeof((array[0])) )
const char *words[] = { "apple", "banana", "pear", "grape", "orange" };

void PrintGameOutput();
void PrintStickman();
void PrintGuessingWord();
void CheckGuess();
char GetUserGuess();
void FillGuessArray();


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

    }


}
