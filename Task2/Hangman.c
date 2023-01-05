#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintGameOutput();
void PrintStickman();
void PrintGuessingWord();
void CheckGuess();
char GetUserGuess();
#define ARR_SIZE(array) ( sizeof((array)) / sizeof((array[0])) )


int main(){
    int wrongGuesses = 0;
    char* words[] ={"test", "dog", "cat"};
    char* randomWord = words[rand() % ARR_SIZE(words)];
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

}
// void CheckGuess(char* pUserGuess, char array[], char guessedArray[], int arrayLength){
//     for (int i = 0; i < arrayLength; i++){
//         if (pUserGuess == array[i]){
//             guessedArray[i] = array[i];
//         }
        
//     }
    
// }
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

