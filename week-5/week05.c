#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int main(){
    int mv = 1;
    FILE* infile = fopen("gukesh-makan.csv", "r");
    FILE* outfile = fopen("gukesh-makan-01.sql", "w");
    if (!infile){
        printf("Can't open the file");
    }
    int c = 45;
    while(c--){
        char s[1000];
        char move[10];
        fgets(s,1000,infile);
        char* token = strtok(s,",");
        strcpy(move, token);
        bool isCap = false, isCas = false, isCheck = false, isCMate = false;
        char piece[10],start[3],end[3];
        start[2] = '\0';
        end[2] = '\0';

        if(move[0] >='a' && move[0] <= 'h'){
            strcpy(piece, "Pawn");
        }
        else{
            switch (move[0])
            {
            case 'K':
                strcpy(piece, "King");
                break;
            case 'Q':
                strcpy(piece, "Queen");
                break;
            case 'R':
                strcpy(piece, "Rook");
                break;
            case 'B':
                strcpy(piece, "Bishop");
                break;
            case 'N':
                strcpy(piece, "Knight");
                break;
            default:
                strcpy(piece, "King");
                break;
            }
        }

        if(move[strlen(move)-1] > '0' && move[strlen(move)-1] < '9'){
            end[1] = move[strlen(move)-1];
            end[0] = move[strlen(move)-2];
        }
        else if(!strcmp(move, "O-O")){
            strcpy(end,"g1");
            isCas = true;
        }
        else if(!strcmp(move, "O-O-O")){
            strcpy(end,"c1");
            isCas = true;
        }
        else{
            end[1] = move[strlen(move)-2];
            end[0] = move[strlen(move)-3];
        }

        if(move[strlen(move)-1] == '+'){
            isCheck = true;
        }

        if(move[strlen(move)-1] == '#'){
            isCMate = true;
        }
        if(move[1] == 'x'){
            isCap = true;
        }

        fprintf(outfile,"INSERT INTO T1 VALUES (%d, \"%s\", \"%s\", \"%s\", \"%s\", %d, %d ,%d, %d);\n", mv, "White", piece, start, end, isCap, isCas, isCheck, isCMate);
        
        token = strtok(NULL, ",");
        strcpy(move, token);
        start[2] = '\0';
        end[2] = '\0';

        if(move[0] >='a' && move[0] <= 'h'){
            strcpy(piece, "Pawn");
        }
        else{
            switch (move[0])
            {
            case 'K':
                strcpy(piece, "King");
                break;
            case 'Q':
                strcpy(piece, "Queen");
                break;
            case 'R':
                strcpy(piece, "Rook");
                break;
            case 'B':
                strcpy(piece, "Bishop");
                break;
            case 'N':
                strcpy(piece, "Knight");
                break;
            default:
                strcpy(piece, "King");
                break;
            }
        }

        if(move[strlen(move)-1] > '0' && move[strlen(move)-1] < '9'){
            end[1] = move[strlen(move)-1];
            end[0] = move[strlen(move)-2];
        }
        else if(!strcmp(move, "O-O")){
            strcpy(end,"g8");
            isCas = true;
        }
        else if(!strcmp(move, "O-O-O")){
            strcpy(end,"c8");
            isCas = true;
        }
        else{
            end[1] = move[strlen(move)-2];
            end[0] = move[strlen(move)-3];
        }

        if(move[strlen(move)-1] == '+'){
            isCheck = true;
        }

        if(move[strlen(move)-1] == '#'){
            isCMate = true;
        }
        if(move[1] == 'x'){
            isCap = true;
        }
        if(strcmp(move,"1-0")){
            fprintf(outfile,"INSERT INTO T1 VALUES (%d, \"%s\", \"%s\", \"%s\", \"%s\", %d, %d ,%d, %d);\n", mv, "Black", piece, start, end, isCap, isCas, isCheck, isCMate);
        }

        mv++;
    }
    fclose(infile);
    fclose(outfile);
}