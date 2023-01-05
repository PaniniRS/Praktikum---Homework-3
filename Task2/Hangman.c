#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char PickRandomWord();
void PrintGameOutput();
void PrintStickman();
void PrintGuessingWord();
void CheckGuess();
char GetUserGuess();

int main(){
    int wrongGuesses = 0;
    char* words[] ={"Test", "Dog", "Cat"};
    char randomWord = PickRandomWord(words, 3); 
    printf("%s", randomWord);
}

char PickRandomWord(char words[], int arrayLength){
    int wordIndexRandom = (rand() % (arrayLength - 0 + 1)) + 0;
    char word = words[wordIndexRandom];

    return word;
}


void PrintGameOutput(){

}
void CheckGuess(char* pUserGuess, char array[], char guessedArray[], int arrayLength){
    for (int i = 0; i < arrayLength; i++){
        if (array[i] == pUserGuess){
            guessedArray[i] = array[i];
        }
        
    }
    
}
void PrintStickman(){

}
void PrintGuessingWord(){

}
char GetUserGuess(){
    char userGuess = "";
    printf("\nEnter your guess character: ");
    scanf(" %s", userGuess);
    return userGuess;
}
