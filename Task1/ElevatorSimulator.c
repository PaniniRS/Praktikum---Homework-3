#include <stdio.h> //standard 
#include <stdbool.h> //boolean
// #include <conio.h> //clearing screen
#include <windows.h> //time sleep for win
#include <unistd.h> //time sleep for linux

void PrintBuilding();
void MoveElevator();
int FindIndex();

int main(){
    char floors[6] = {'G', '1', '2', '3', '4', '5'};
    char* pElevatorPosition = &floors[0];
    char userDesiredFloor;
    bool userDesiredFloorExists = false;

    PrintBuilding(pElevatorPosition, floors, 6);
    printf("\n  [] Elevator current floor: %c", *pElevatorPosition);
    printf("\n  [?] Which floor would you like to go to? -Floor ");
    scanf("%c", &userDesiredFloor);
    char* pUserDesiredFloor = &userDesiredFloor;
    //TODO: proveri dali postoi spratot
    MoveElevator(pElevatorPosition, pUserDesiredFloor, floors, 6);
}

//=----------------------------------------------------------------------------=
//                          Functions
//=----------------------------------------------------------------------------=

void PrintBuilding(char* pElevatorPosition, char floors[], int floorCount){
        printf("+-------+\n");
    for (int i = floorCount-1; i > -1; i--){
        printf("|-     -|\n");
        //Finds and prints the elevator on the correct floor
        if (*pElevatorPosition == floors[i]){
        printf("+- [ ] -+\n");
        }else{
        printf("+-  %c  -+\n", floors[i]);
        }
    }
        printf("+-------+");
}

void MoveElevator(char* pElevatorPosition, char* pFloorToMoveTo, char array[], int arrayLength){
    int elevatorIndex = FindIndex(pElevatorPosition, array, arrayLength);
    int floorToMoveToIndex = FindIndex(pFloorToMoveTo, array, arrayLength);

    while (!(floorToMoveToIndex == elevatorIndex)){
        elevatorIndex = FindIndex(pElevatorPosition, array, arrayLength);
        //if the floor is above the elevator => move the elevator up
        if (floorToMoveToIndex > elevatorIndex){
            pElevatorPosition = &array[elevatorIndex+1];
            // clrscr();
            printf("=------------------------------------="); 
            // system("cls"); //clears terminal
            PrintBuilding(pElevatorPosition, array, 6);
        }
        //if the floor is below the elevator => move the elevator down
        else if (floorToMoveToIndex < elevatorIndex){
            pElevatorPosition = &array[elevatorIndex-1];
            // clrscr();
            printf("=------------------------------------="); 
            PrintBuilding(pElevatorPosition, array, 6);
        }
    }
        Sleep(5);
    
}

int FindIndex(char* elementToFind, char array[6], int arrayLength){
    int elementIndex;
    for (int i = 0; i < arrayLength; i++){
        char elementOfArray = array[i];
        if (*elementToFind == elementOfArray){ // error vamu nemoze da otvori memorija za adresata na pointerot
            elementIndex = i;
        }
    }
    return elementIndex;
}
