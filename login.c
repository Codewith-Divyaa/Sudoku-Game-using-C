#include<stdio.h>
#include<string.h>

char currentuser[30];

int login() {
    char username[4][30] = {"Divya","AvniK","avniP","Ivy"};
    char password[4][30] = {"123","abc","xyz","789"};

    char loginID[30], key[30];
    int i;

    printf("Enter Username:");
    scanf("%s", loginID);
    printf("Enter Password:");
    scanf("%s", key);

    for(i=0;i<4;i++) {
        if(strcmp(loginID,username[i])==0 && strcmp(key,password[i])==0) {
            strcpy(currentuser, loginID);
            printf("\nLogin Successful!!\n");
            return 1;
        }
    }
    printf("Invalid Username or Password\n");
    return 0;
}

