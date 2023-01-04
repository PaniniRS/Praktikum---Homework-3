#include <stdio.h>
#include <stdbool.h>
void PrintBuilding();
void MoveElevetor();
void FindIndexDesiredFloor();

int main(){
    char floors[6] = {'G', '1', '2', '3', '4', '5'};
    char* pElevatorPosition = &floors[5];
    char userDesiredFloor;
    bool userDesiredFloorExists = false;
    PrintBuilding(pElevatorPosition, floors, 6);
    printf("\n  [] Elevator current floor: %c", *pElevatorPosition);
    //Requests user input till he enters a floor that exists
    // do{
        printf("\n  [?] Which floor would you like to go to? -Floor ");
        scanf("%c", &userDesiredFloor);
        FindIndexDesiredFloor(userDesiredFloor, floors, 6);
        //checks whether the inputed floor exits 
    //     for (int i = 0; i < 6; i++){
    //         if (userDesiredFloor == floors[i]){
    //             userDesiredFloorExists = true;
    //         }
    //     }
        
    // } while (!userDesiredFloorExists);
    
    
    

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

void FindIndexDesiredFloor(char* desiredFloor, char floors[], int floorCount){
    for (int i = 0; i < floorCount; i++){
        if (desiredFloor == floors[i]){
            printf("%i", i);
        }
    }
}
