#include <stdio.h>
void PrintBuilding();

int main(){
    char floors[6] = {'G', '1', '2', '3', '4', '5'};
    char* pElevatorPosition = &floors[4];
    PrintBuilding(pElevatorPosition, floors, 6);
    printf("\n  [] Elevator current floor: %c", *pElevatorPosition);
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


