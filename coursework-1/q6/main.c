#include <stdio.h>
#include "cmd_color.h"
#include "grid.h"

void play(){
    int grid[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; // init the grid
    int count=0; // count the legal moves
    char choice; // store the player choice
    int end = 0;
    int player = -1; //player character : -1 for X ; -2 for O
    char *alert = ""; // Store the alert message from the last play (can be empty)
    while (count<9 && !end){
        // Will run until there has been 9 legal moves (tie), or a player has won (end = 1)
        printf("\e[1;1H\e[2J"); // to clear the screen
        print_grid(grid,!end); // to print the grid at the current state of the game
        printf("%sInput your choice : ",alert);
        scanf(" %c",&choice);
        alert = "";
        switch (choice){
            // for each legal move (1-9), we check if can insert the character, and we increment the number of legal move, else we print an alert
            case '1':
                if  (check_can_insert(grid,0,0)){
                    insert_into_grid(grid,0,0,player);
                    count ++;
                }
                else{
                    alert = "Cell already taken\n";
                }
                break;
            case '2':
                if  (check_can_insert(grid,0,1)){
                    insert_into_grid(grid,0,1,player);
                    count ++;
                }
                else{
                    alert = "Cell already taken\n";
                }
                break;
            case '3':
                if  (check_can_insert(grid,0,2)){
                    insert_into_grid(grid,0,2,player);
                    count ++;
                }
                else{
                    alert = "Cell already taken\n";
                }
                break;
            case '4':
                if  (check_can_insert(grid,1,0)){
                    insert_into_grid(grid,1,0,player);
                    count ++;
                }
                else{
                    alert = "Cell already taken\n";
                }
                break;
            case '5':
                if  (check_can_insert(grid,1,1)){
                    insert_into_grid(grid,1,1,player);
                    count ++;
                }
                else{
                    alert = "Cell already taken\n";
                }
                break;
            case '6':
                if  (check_can_insert(grid,1,2)){
                    insert_into_grid(grid,1,2,player);
                    count ++;
                }
                else{
                    alert = "Cell already taken\n";
                }
                break;
            case '7':
                if  (check_can_insert(grid,2,0)){
                    insert_into_grid(grid,2,0,player);
                    count ++;
                }
                else{
                    alert = "Cell already taken\n";
                }
                break;
            case '8':
                if  (check_can_insert(grid,2,1)){
                    insert_into_grid(grid,2,1,player);
                    count ++;
                }
                else{
                    alert = "Cell already taken\n";
                }
                break;
            case '9':
                if  (check_can_insert(grid,2,2)){
                    insert_into_grid(grid,2,2,player);
                    count ++;
                }
                else{
                    alert = "Cell already taken\n";
                }
                break;
            default:
                // if the move is not recognized, we print an alert
                alert = "Invalid Input\n";
                break;
        }
        end = check_win(grid,player); // we check if the last play has resulted in one of the player winning the game
        if (alert==""){
            // if there has been an alert (wrong move), we don't change turn, else we do
            player = player ==-1 ? -2:-1;
        }
    }
    printf("\e[1;1H\e[2J"); // to clear the screen
    print_grid(grid,!end);
    //Display the winning message (or Tie)
    if (end){
        printf("\nWinner is : %s !\n",player ==-1 ? "\033[0;34m0\033[0m":"\033[1;31mX\033[0m");
    }
    else{
        printf("\nIt's a tie !\n");
    }
}

int main(){
    int replay =1;
    char replayquestion;
    while(replay){
        //loops while the .exe is running
        play();
        printf("\nPlay again (Y/N) : ");
        scanf(" %c",&replayquestion);
        replay = replayquestion=='Y' ? 1 : 0;
    }
    return 0;
}

// Compile CMD : gcc -o tic_tac_toe.exe main.c grid.c cmd_color.c 