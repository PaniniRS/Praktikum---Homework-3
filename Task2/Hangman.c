#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    char lettersGuessed[26] = {0};  // array to store tried letters
    int lettersGuessedCount = 0;  // number of tried letters
    char userGuess;
    int wrongGuesses = 0;
    int* pWrongGuesses = 0;
    char* randomWord = words[rand() % ArraySize(words)];
    int randomWordLength = strlen(randomWord);
    char guessArray[ArraySize(randomWord)];
    
    //fills guessArray with _
    for (int i = 0; i < randomWordLength; i++) {
        guessArray[i] = '_';  
    }


    printf("Random word selected: %s", randomWord);

    //
    // printf("\nEnter your guess character: ");
    // scanf(" %s", &userGuess);
    //
    char userGuess = GetUserGuess();
    char* pUserGuess = &userGuess;

    printf("UserGuess: %c", userGuess);
    CheckGuess(pUserGuess, randomWord, guessArray, ArraySize(randomWord), pWrongGuesses);


}

void PrintGameOutput(){
    PrintGuessingWord();
    PrintStickman();
}
void CheckGuess(char* pUserGuess, char* word, char* guessedArray, int wordLength, int* pWrongGuesses){
    int CounterCorrectlyGuessed = 0;
    for (int i = 0; i < wordLength; i++){
        if (pUserGuess == word[i]){ //FIX: for some reason it thinks word[i] is an integer
            guessedArray[i] = word[i]; 
            CounterCorrectlyGuessed++;
        }
    }
    if (CounterCorrectlyGuessed < 1){
        pWrongGuesses = *pWrongGuesses + 1; // TODO: make it so the value of that the pointer points to gets increased by 1
        printf("Your letter isn't present in the word(( Wrong Guesses so far %*i ", *pWrongGuesses);
    }else
    {
        printf("You correctly guessed %i characters from the word!", CounterCorrectlyGuessed);
    }
    
}
void PrintStickman(){

}
void PrintGuessingWord(char* guessedArray, int arrayLength){
    for (int i = 0; i < arrayLength; i++){
        printf("%")
    }
    
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

