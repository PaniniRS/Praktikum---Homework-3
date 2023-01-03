#include <stdio.h>
#include <stdbool.h>
void PrintBuilding();
void MoveElevetor();
bool DesiredFloorExists();

int main(){
    char floors[6] = {'G', '1', '2', '3', '4', '5'};
    char* pElevatorPosition = &floors[4];
    char userDesiredFloor;
    PrintBuilding(pElevatorPosition, floors, 6);
    printf("\n  [] Elevator current floor: %c", *pElevatorPosition);
    printf("\n  [?] Which floor would you like to go to? -Floor ");
    //Requests user input till he enters a floor that exists
    
    
    

}

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

void MoveElevator(char floorToMoveTo){

}

bool DesiredFloorExists(char floorToFind, char floors[6], int floorCount){
    for (int floor = 0; floor < floorCount; floor++){
        if (floorToFind == floors[floor]){
            return true;
        }
    }
    return false;
}


