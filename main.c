#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Player{
    char name[30];
    int games;
    int score;
};

int login();
void playgame(struct Player *p);
void readRecord(struct Player *p);
void saveRecord(struct Player *p);

extern char currentuser[30];

int main()
{
    int choice;
    int signIn=0;

    struct Player *p;
    p = (struct Player *)malloc(sizeof(struct Player));
    p->games = 0;
    p->score = 0;

    while(1) {

        printf("=================================\n");
        printf("       SUDOKU GAME MENU       \n");
        printf("=================================\n");
        printf("\n1. Login\n");
        printf("2. Play Game\n");
        printf("3. View Records\n");
        printf("4. Exit\n");
        printf("=================================\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice==1){
            while(signIn==0){
                if(login()==1){
                    signIn = 1;
                    strcpy(p->name, currentuser);

                    readRecord(p);
                    printf("Welcome %s\n", p->name);
                }
                else {
                    printf("Try again!\n");
                }
            }
        }

        else if(choice==2) {
            if(signIn==1){
                p->games++;
                playgame(p);
                saveRecord(p);
            }
            else{
                printf("Login first!\n");
            }
        }
        else if(choice==3) {
            if(signIn==1){

                printf("=================================\n");
                printf("       PLAYER RECORDS       \n");
                printf("=================================\n");

                printf("Name         : %s\n", p->name);
                printf("Games Played : %d\n", p->games);
                printf("Score        : %d\n", p->score);
                printf("=================================\n");
            }
            else {
                printf("Login first!\n");
            }
        }
        else if(choice==4){
            printf("Thank you for playing Sudoku Game!\n");
            break;
        }
        else{
            printf("Wrong Input\n");
        }
    }
    free(p);
    return 0;
}
