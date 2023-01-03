#include <stdio.h>
void PrintBuilding();
void MoveElevetor();
int CheckArrayFor();

int main(){
    char floors[6] = {'G', '1', '2', '3', '4', '5'};
    char* pElevatorPosition = &floors[4];
    char userDesiredFloor;
    PrintBuilding(pElevatorPosition, floors, 6);
    printf("\n  [] Elevator current floor: %c", *pElevatorPosition);
    printf("\n  [?] Which floor would you like to go to? -Floor ");
    //Requests user input till he enters a floor that exists
    do{
        scanf("%c", userDesiredFloor);
    } while (!DesiredFloorExists(userDesiredFloor, floors, 6));

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

int DesiredFloorExists(char floorToFind, char floors[], int floorCount){
    for (int floor = 0; floor < floorCount; floor++){
        if (floorToFind == floors[floor]){
            return 1;
        }
    }
    return 0;
}


