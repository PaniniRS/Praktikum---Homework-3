#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char PickRandomWord();
void Game();
void PrintGameOutput();
void CheckGuess();
char GetUserGuess();

int main(){
    
    int wrongGuesses = 0;
    char* words[] ={"Test","Dog" , "Cat"};


}

char PickRandomWord(char words[], int arrayLength){
    int wordIndexRandom = (rand() % (arrayLength - 0 + 1)) + 0;
    char word = words[wordIndexRandom];

    return word;
}

void Game(){

}
void PrintGameOutput(){

}
void CheckGuess(){

}
char GetUserGuess(){
    char userGuess = "";
    printf("\nEnter your guess character: ");
    scanf(" %s", userGuess);
    return userGuess;
}
