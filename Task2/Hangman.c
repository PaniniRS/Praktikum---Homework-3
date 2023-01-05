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
    char userGuess;
    char* words[] ={"Test", "Dog", "Cat"};
    char* randomWord = words[rand() % ARR_SIZE(words)];
    printf("Random word selected: %s", randomWord);

    //
    printf("\nEnter your guess character: ");
    scanf(" %s", &userGuess);
    //
    // char userGuess = GetUserGuess();
    // char* pUserGuess = &userGuess;

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
    scanf(" %s", userGuess);
    return userGuess;
}
