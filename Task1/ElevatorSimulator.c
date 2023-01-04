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
    // bool userWantsToExit = false;

    PrintBuilding(pElevatorPosition, floors, 6);
    printf("\n\t[] Elevator current floor: %c", *pElevatorPosition);

    printf("\n\t[?] Which floor would you like to go to? -Floor ");

    //first time the elevator is moved
    scanf("%c", &userDesiredFloor);
    char* pUserDesiredFloor = &userDesiredFloor;
    MoveElevator(pElevatorPosition, pUserDesiredFloor, floors, 6);

    //TODO: proveri dali postoi spratot
    while (true){
        printf("\n\t Write E to exit or which floor you want the lift to move to: ");
        scanf("%c", &userDesiredFloor);
        char* pUserDesiredFloor = &userDesiredFloor;
        if(userDesiredFloor == 'E'){
            break;
        }
        else{
            MoveElevator(pElevatorPosition, pUserDesiredFloor, floors, 6);
        }
    }
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
        //else if the floor is below the elevator => move the elevator down
        if (floorToMoveToIndex > elevatorIndex){
            pElevatorPosition = &array[elevatorIndex+1];
        }else if (floorToMoveToIndex < elevatorIndex){
            pElevatorPosition = &array[elevatorIndex-1];
        }
    }
            PrintBuilding(pElevatorPosition, array, 6);
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
