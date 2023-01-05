#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void PrintGameOutput();
void PrintStickman();
void PrintGuessingWord();
void CheckGuess();
char GetUserGuess();
void FillGuessArray();
#define ArraySize(array) ( sizeof((array)) / sizeof((array[0])) )


int main(){
    int wrongGuesses = 0;
    char* words[] ={"test", "dog", "cat"};
    char* randomWord = words[rand() % ArraySize(words)];
    char guessArray[ArraySize(randomWord)];
    FillGuessArray(randomWord, guessArray);
    printf("Random word selected: %s", randomWord);

    //
    // printf("\nEnter your guess character: ");
    // scanf(" %s", &userGuess);
    //
    char userGuess = GetUserGuess();
    char* pUserGuess = &userGuess;

    printf("UserGuess: %c", userGuess);


}

void PrintGameOutput(){
    PrintGuessingWord();
    PrintStickman();
}
void CheckGuess(char* pUserGuess, char* array, char* guessedArray, int arrayLength, int* pWrongGuesses){
    int CounterCorrectlyGuessed = 0;
    for (int i = 0; i < arrayLength; i++){
        if (pUserGuess == array[i]){
            guessedArray[i] = array[i];
            CounterCorrectlyGuessed++;
        }
    }
    if (CounterCorrectlyGuessed < 1){
        pWrongGuesses = *pWrongGuesses + 1;
        printf("Your letter isn't present in the word(( Wrong Guesses so far %*i ", *pWrongGuesses);
    }else
    {
        printf("You correctly guessed %i characters from the word!", CounterCorrectlyGuessed);
    }
    
}
void PrintStickman(){

}
void PrintGuessingWord(){

}
char GetUserGuess(){
    char userGuess;
    printf("\nEnter your guess character: ");
    scanf(" %s", &userGuess);
    if (userGuess > 96 && userGuess < 123){
    return userGuess;
    }else if (userGuess > 64 && userGuess < 91){
        return userGuess + 32;
    }else{
        printf("Error with your guessed character, only letters allowed!");
    }
}

//might not work
void FillGuessArray(char* word, char* guessArray){
    for (int i = 0; i < ArraySize(word); i++){
       guessArray[i] = '_';
    }
}
