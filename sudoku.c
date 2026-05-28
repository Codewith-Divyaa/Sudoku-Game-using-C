#include <stdio.h>
#include<stdlib.h>

struct Player{
    char name[30];
    int games;
    int score;
};

int puzzle[9][9] = {
{0,6,0,3,0,8,1,0,0},
{5,8,1,0,0,9,6,0,0},
{0,0,3,5,0,0,0,0,0},
{0,9,0,8,0,2,0,0,0},
{0,0,0,7,4,5,9,3,6},
{3,5,0,0,0,6,8,0,4},
{1,3,5,0,0,0,0,0,0},
{7,0,8,6,1,3,4,0,0},
{9,4,0,0,0,7,3,0,0}
};

int solution[9][9] = {
{2,6,9,3,7,8,1,4,5},
{5,8,1,4,2,9,6,7,3},
{4,7,3,5,6,1,2,9,8},
{6,9,4,8,3,2,5,1,7},
{8,1,2,7,4,5,9,3,6},
{3,5,7,1,9,6,8,2,4},
{1,3,5,9,8,4,7,6,2},
{7,2,8,6,1,3,4,5,9},
{9,4,6,2,5,7,3,8,1}
};

void display(){
    int i,j;
    printf("\n==== Sudoku Board ====\n");
    printf("\n+-------+-------+-------+\n");

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){

            if(j%3==0)
                printf("| ");

            if(puzzle[i][j]==0)
                printf(". ");
            else
                printf("%d ", puzzle[i][j]);
        }

        printf("|\n");

        if((i+1)%3==0)
            printf("+-------+-------+-------+\n");
    }
}

int isComplete() {
    int i,j;
    int flag=1;

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(puzzle[i][j] == 0) flag = 0;
        }
    }
    return flag;
}

void playgame(struct Player *p) {
    int row,col,ele;
    int ch=0;

    printf("\n----INSTRUCTIONS----\n");
    printf("1.Each row and column and 3x3 box must have numbers 1 to 9 without repetition.\n");
    printf("2.Enter row, column (0-8).\n");
    printf("3.Enter elements between (1-9).\n");
    printf("4.Correct input will be accepted.\n");
    printf("5.Press 1 to exit.\n\n");

    display();

    while(ch == 0) {
        printf("\nEnter row (0-8):");
        scanf("%d", &row);
        printf("Enter col (0-8):");
        scanf("%d", &col);
        printf("Enter element (1-9):");
        scanf("%d", &ele);

        if(puzzle[row][col] != 0){
            printf("Cell is already filled!\n");
        }

        else if(ele == solution[row][col]){
            puzzle[row][col] = ele;
            printf("\nCorrect!!\n");
            p->score++;
        }
        else{
            printf("\nWrong Input!Try Again.\n");
        }
        printf("\n");

        display();

        if(isComplete() == 1){
            printf("\n**** CONGRATULATIONS ****\n");
            printf(">>>> PUZZLE COMPLETED <<<<\n");
            ch=1;
        }

        printf("\n");

        if(ch==0){
            printf("Press 0 to continue, 1 to exit: ");
            scanf("%d", &ch);
        }
    }
}
