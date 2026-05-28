#include<stdio.h>
#include<string.h>

struct Player{
    char name[30];
    int games;
    int score;
};

void readRecord(struct Player *p) {
    FILE *fp;
    char uname[30];
    int gm,sc;

    fp = fopen("record.txt", "r");

    if(fp==NULL){
        return;
    }

    while(fscanf(fp, "%s %d %d", uname, &gm, &sc)!= EOF){
        if(strcmp(uname,p->name)==0){
            p->games = gm;
            p->score = sc;
        }
    }
    fclose(fp);
}

void saveRecord(struct Player *p){
    FILE *fp;

    fp = fopen("record.txt", "a");

    fprintf(fp, "%s %d %d\n",p->name, p->games, p->score);

    fclose(fp);
}
