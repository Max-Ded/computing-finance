#include <stdio.h>
#include "grid.h"
#include "cmd_color.h"

void print_grid(int grid[3][3],int end){
    //will print the grid at the current state, if end we don't print the numbers of the cell but '-'
    printf("\n-------------\n");
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (grid[i][j]>0){
                if (end){
                    // if end we don't print cell content if not played by the players (just '-')
                    if (j!=1){
                        // for outer cells we print both vertical borders
                        printf("| %d |",grid[i][j]);
                    }
                    else{
                        // no borders
                        printf(" %d ",grid[i][j]);
                    }
                }
                else{
                    if (j!=1){
                        printf("| - |",grid[i][j]);
                    }
                    else{
                        printf(" - ");
                    }
                }
            }
            else if (grid[i][j]==-1){
                if (j!=1){
                    printf("| ");
                    red();
                    printf("X");
                    reset();
                    printf(" |");
                }
                else{
                    red();
                    printf(" X ");
                    reset();
                }
            }
            else if (grid[i][j]==-2){
                if (j!=1){
                    printf("| ");
                    blue();
                    printf("O");
                    reset();
                    printf(" |");
                }
                else{
                    blue();
                    printf(" O ");
                    reset();
                }
            }
        }
        printf("\n-------------\n");
    }
}

int check_can_insert(int grid[3][3],int i, int j){
    // check if the i-j cell coordinate is empty
    if (grid[i][j]>0){
        return 1;
    }
    return 0;
}

void insert_into_grid(int grid[3][3],int i, int j,int value){
    // insert the value into the i-j coord of the grid (passed by reference)
    grid[i][j] = value;
}

int check_win(int grid[3][3],int player){
    // iterate over every winning sequence (vertical horizontal diagonal lines) to check if the player has won
    if (grid[0][0]==player && grid[1][1]==player && grid[2][2]==player){
        return 1;
    }
    if (grid[0][2]==player && grid[1][1]==player && grid[2][0]==player){
        return 1;
    }
    for (int i=0;i<3;i++){
        if (grid[i][0]==player && grid[i][1]==player && grid[i][2]==player){
            return 1;
        }
        if (grid[0][i]==player && grid[1][i]==player && grid[2][i]==player){
            return 1;
        }
    }
    return 0;
}

