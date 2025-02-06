#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main(){
    int mv = 1;
    FILE* infile = fopen("gukesh-makan.csv", "r");
    FILE* outfile = fopen("gukesh-makan-01.sql", "w");
    if (!infile){
        printf("Can't open the file");
        return 1;
    }
    int c = 45;
    char bk[3] = "e8";
    char wk[3] = "e1";
    char bq[3] = "d8";
    char wq[3] = "d1";
    char bap[3] = "a7";
    char wap[3] = "a2";
    char bbp[3] = "b7";
    char wbp[3] = "b2";
    char bcp[3] = "c7";
    char wcp[3] = "c2";
    char bdp[3] = "d7";
    char wdp[3] = "d2";
    char bep[3] = "e7";
    char wep[3] = "e2";
    char bfp[3] = "f7";
    char wfp[3] = "f2";
    char bgp[3] = "g7";
    char wgp[3] = "g2";
    char bhp[3] = "h7";
    char whp[3] = "h2";
    char blr[3] = "a8";
    char wlr[3] = "a1";
    char brr[3] = "h8";
    char wrr[3] = "h1";
    char bln[3] = "b8";
    char wln[3] = "b1";
    char brn[3] = "g8"; 
    char wrn[3] = "g1";
    char blb[3] = "c8";
    char wlb[3] = "c1";
    char brb[3] = "f8";
    char wrb[3] = "f1";
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

        if(move[strlen(move)-1] > '0' && move[strlen(move)-1] < '9'){
            end[1] = move[strlen(move)-1];
            end[0] = move[strlen(move)-2];
        }
        else if(move[strlen(move)-2] > '0' && move[strlen(move)-2] < '9'){
            end[1] = move[strlen(move)-2];
            end[0] = move[strlen(move)-3];
        }
        else{
            if(strlen(move) == 3){
                strcpy(end, "g1");
                strcpy(wrr, "f1");
                isCas = true;
            }
            else{
                strcpy(end, "c1");
                strcpy(wlr, "d1");
                isCas = true;
            }
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

        if(move[0] >='a' && move[0] <= 'h'){
            strcpy(piece, "Pawn");
            if(move[0] == wap[0] && ((int)(end[1] - wap[1]) == ((wap[1] != '2') ? 1 : 2) || (int)(end[1] - wap[1]) == 1)){
                strcpy(start, wap);
                strcpy(wap, end);
            }
            else if(move[0] == wbp[0] && ((int)(end[1] - wbp[1]) == ((wbp[1] != '2') ? 1 : 2) || (int)(end[1] - wbp[1]) == 1)){
                strcpy(start, wbp);
                strcpy(wbp, end);
            }
            else if(move[0] == wcp[0] && ((int)(end[1] - wcp[1]) == ((wcp[1] != '2') ? 1 : 2) || (int)(end[1] - wcp[1]) == 1)){
                strcpy(start, wcp);
                strcpy(wcp, end);
            }
            else if(move[0] == wdp[0] && ((int)(end[1] - wdp[1]) == ((wdp[1] != '2') ? 1 : 2) || (int)(end[1] - wdp[1]) == 1)){
                strcpy(start, wdp);
                strcpy(wdp, end);
            }
            else if(move[0] == wep[0] && ((int)(end[1] - wep[1]) == ((wep[1] != '2') ? 1 : 2) || (int)(end[1] - wep[1]) == 1)){
                strcpy(start, wep);
                strcpy(wep, end);
            }
            else if(move[0] == wfp[0] && ((int)(end[1] - wfp[1]) == ((wfp[1] != '2') ? 1 : 2) || (int)(end[1] - wfp[1]) == 1)){
                strcpy(start, wfp);
                strcpy(wfp, end);
            }
            else if(move[0] == wgp[0] && ((int)(end[1] - wgp[1]) == ((wgp[1] != '2') ? 1 : 2) || (int)(end[1] - wgp[1]) == 1)){
                strcpy(start, wgp);
                strcpy(wgp, end);
            }
            else if(move[0] == whp[0] && ((int)(end[1] - whp[1]) == ((whp[1] != '2') ? 1 : 2) || (int)(end[1] - whp[1]) == 1)){
                strcpy(start, whp);
                strcpy(whp, end);
            }
        }
        else{
            switch (move[0])
            {
            case 'K':
                strcpy(piece, "King");
                strcpy(start, wk);
                strcpy(wk, end);
                break;
            case 'Q':
                strcpy(piece, "Queen");
                strcpy(start, wq);
                strcpy(wq, end);
                break;
            case 'R':
                strcpy(piece, "Rook");
                if(move[1] == wlr[1]){
                    strcpy(start, wlr);
                    strcpy(wlr, end);
                }
                else if(move[1] == wrr[1]){
                    strcpy(start, wrr);
                    strcpy(wrr, end);
                }
                else if(move[1] == wlr[0] && move[2] >= 'a' && move[2] <= 'h'){
                    strcpy(start, wlr);
                    strcpy(wlr, end);
                }
                else if(move[1] == wrr[0] && move[2] >= 'a' && move[2] <= 'h'){
                    strcpy(start, wrr);
                    strcpy(wrr, end);
                }
                else if(wlr[0] == wrr[0] || wlr[1] == wrr[1]){
                    if(end[0] == wlr[0]){
                        if(abs((int)(end[1] - wlr[1])) < abs((int)(end[1] - wrr[1]))){
                            strcpy(start, wlr);
                            strcpy(wlr, end);
                        }
                        else{
                            strcpy(start, wrr);
                            strcpy(wrr, end);
                        }
                    }
                    else{
                        if(abs((int)(end[0] - wlr[0])) < abs((int)(end[0] - wrr[0]))){
                            strcpy(start, wlr);
                            strcpy(wlr, end);
                        }
                        else{
                            strcpy(start, wrr);
                            strcpy(wrr, end);
                        }
                    }
                }
                else if(end[0] == wlr[0] || end[1] == wlr[1]){
                strcpy(start, wlr);
                strcpy(wlr, end);
                }
                else if(end[0] == wrr[0] || end[1] == wrr[1]){
                    strcpy(start, wrr);
                    strcpy(wrr, end);
                }
                break;
            case 'B':
                strcpy(piece, "Bishop");
                if(abs((int)(end[0] - wlb[0])) == abs((int)(end[1] - wlb[1]))){
                    strcpy(start, wlb);
                    strcpy(wlb, end);
                }
                else if(abs((int)(end[0] - wrb[0])) == abs((int)(end[1] - wrb[1]))){
                    strcpy(start, wrb);
                    strcpy(wrb, end);
                }
                break;
            case 'N':
                strcpy(piece, "Knight");
                if(move[1] == wln[1]){
                    strcpy(start, wln);
                    strcpy(wln, end);
                }
                else if(move[1] == wrn[1]){
                    strcpy(start, wrn);
                    strcpy(wrn, end);
                }
                else if(move[1] == wln[0] && move[2] >= 'a' && move[2] <= 'h'){
                    strcpy(start, wln);
                    strcpy(wln, end);
                }
                else if(move[1] == wrn[0] && move[2] >= 'a' && move[2] <= 'h'){
                    strcpy(start, wrn);
                    strcpy(wrn, end);
                }
                else if((abs((int)(end[0] - wln[0])) == 2 && abs((int)(end[1] - wln[1])) == 1) || (abs((int)(end[0] - wln[0])) == 1 && abs((int)(end[1] - wln[1])) == 2)){
                    strcpy(start, wln);
                    strcpy(wln, end);
                }
                else if((abs((int)(end[0] - wrn[0])) == 2 && abs((int)(end[1] - wrn[1])) == 1) || (abs((int)(end[0] - wrn[0])) == 1 && abs((int)(end[1] - wrn[1])) == 2)){
                    strcpy(start, wrn);
                    strcpy(wrn, end);
                }
                break;
            default:
                strcpy(piece, "King");
                strcpy(start, wk);
                strcpy(wk, end);
                break;
            }
        }

        fprintf(outfile,"INSERT INTO T1 VALUES (%d, \"%s\", \"%s\", \"%s\", \"%s\", %d, %d ,%d, %d);\n", mv, "White", piece, start, end, isCap, isCas, isCheck, isCMate);
        
        token = strtok(NULL, ",");
        strcpy(move, token);
        start[2] = '\0';
        end[2] = '\0';

        if(move[strlen(move)-1] > '0' && move[strlen(move)-1] < '9'){
            end[1] = move[strlen(move)-1];
            end[0] = move[strlen(move)-2];
        }
        else if(move[strlen(move)-2] > '0' && move[strlen(move)-2] < '9'){
            end[1] = move[strlen(move)-2];
            end[0] = move[strlen(move)-3];
        }
        else{
            if(strlen(move) == 5){
                strcpy(end, "c8");
                strcpy(blr, "d8");
                isCas = true;
            }
            else{
                strcpy(end, "g8");
                strcpy(brr, "f8");
                isCas = true;
            }
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

        if(move[0] >='a' && move[0] <= 'h'){
            strcpy(piece, "Pawn");
            if(move[0] == bap[0] && ((int)(end[1] - bap[1]) == ((bap[1] != '7') ? -1 : -2) || (int)(end[1] - bap[1]) == -1)){
                strcpy(start, bap);
                strcpy(bap, end);
            }
            else if(move[0] == bbp[0] && ((int)(end[1] - bbp[1]) == ((bbp[1] != '7') ? -1 : -2) || (int)(end[1] - bbp[1]) == -1)){
                strcpy(start, bbp);
                strcpy(bbp, end);
            }
            else if(move[0] == bcp[0] && ((int)(end[1] - bcp[1]) == ((bcp[1] != '7') ? -1 : -2) || (int)(end[1] - bcp[1]) == -1)){
                strcpy(start, bcp);
                strcpy(bcp, end);
            }
            else if(move[0] == bdp[0] && ((int)(end[1] - bdp[1]) == ((bdp[1] != '7') ? -1 : -2) || (int)(end[1] - bdp[1]) == -1)){
                strcpy(start, bdp);
                strcpy(bdp, end);
            }
            else if(move[0] == bep[0] && ((int)(end[1] - bep[1]) == ((bep[1] != '7') ? -1 : -2) || (int)(end[1] - bep[1]) == -1)){
                strcpy(start, bep);
                strcpy(bep, end);
            }
            else if(move[0] == bfp[0] && ((int)(end[1] - bfp[1]) == ((bfp[1] != '7') ? -1 : -2) || (int)(end[1] - bfp[1]) == -1)){
                strcpy(start, bfp);
                strcpy(bfp, end);
            }
            else if(move[0] == bgp[0] && ((int)(end[1] - bgp[1]) == ((bgp[1] != '7') ? -1 : -2) || (int)(end[1] - bgp[1]) == -1)){
                strcpy(start, bgp);
                strcpy(bgp, end);
            }
            else if(move[0] == bhp[0] && ((int)(end[1] - bhp[1]) == ((bhp[1] != '7') ? -1 : -2) || (int)(end[1] - bhp[1]) == -1)){
                strcpy(start, bhp);
                strcpy(bhp, end);
            }
        }
        else{
            switch (move[0])
            {
            case 'K':
                strcpy(piece, "King");
                strcpy(start, bk);
                strcpy(bk, end);
                break;
            case 'Q':
                strcpy(piece, "Queen");
                strcpy(start, bq);
                strcpy(bq, end);
                break;
            case 'R':
                strcpy(piece, "Rook");
                if(move[1] == blr[1]){
                    strcpy(start, blr);
                    strcpy(blr, end);
                }
                else if(move[1] == brr[1]){
                    strcpy(start, brr);
                    strcpy(brr, end);
                }
                else if(move[1] == blr[0] && move[2] >= 'a' && move[2] <= 'h'){
                    strcpy(start, blr);
                    strcpy(blr, end);
                }
                else if(move[1] == brr[0] && move[2] >= 'a' && move[2] <= 'h'){
                    strcpy(start, brr);
                    strcpy(brr, end);
                }
                else if(blr[0] == brr[0] || blr[1] == brr[1]){
                    if(end[0] == blr[0]){
                        if(abs((int)(end[1] - blr[1])) < abs((int)(end[1] - brr[1]))){
                            strcpy(start, blr);
                            strcpy(blr, end);
                        }
                        else{
                            strcpy(start, brr);
                            strcpy(brr, end);
                        }
                    }
                    else{
                        if(abs((int)(end[0] - blr[0])) < abs((int)(end[0] - brr[0]))){
                            strcpy(start, blr);
                            strcpy(blr, end);
                        }
                        else{
                            strcpy(start, brr);
                            strcpy(brr, end);
                        }
                    }
                }
                else if(end[0] == blr[0] || end[1] == blr[1]){
                strcpy(start, blr);
                strcpy(blr, end);
                }
                else if(end[0] == brr[0] || end[1] == brr[1]){
                    strcpy(start, brr);
                    strcpy(brr, end);
                }
                break;
            case 'B':
                strcpy(piece, "Bishop");
                if(abs((int)(end[0] - blb[0])) == abs((int)(end[1] - blb[1]))){
                    strcpy(start, blb);
                    strcpy(blb, end);
                }
                else if(abs((int)(end[0] - brb[0])) == abs((int)(end[1] - brb[1]))){
                    strcpy(start, brb);
                    strcpy(brb, end);
                }
                break;
            case 'N':
                strcpy(piece, "Knight");
                if(move[1] == bln[1]){
                    strcpy(start, bln);
                    strcpy(bln, end);
                }
                else if(move[1] == brn[1]){
                    strcpy(start, brn);
                    strcpy(brn, end);
                }
                else if(move[1] == bln[0] && move[2] >= 'a' && move[2] <= 'h'){
                    strcpy(start, bln);
                    strcpy(bln, end);
                }
                else if(move[1] == brn[0] && move[2] >= 'a' && move[2] <= 'h'){
                    strcpy(start, brn);
                    strcpy(brn, end);
                }
                else if((abs((int)(end[0] - bln[0])) == 2 && abs((int)(end[1] - bln[1])) == 1) || (abs((int)(end[0] - bln[0])) == 1 && abs((int)(end[1] - bln[1])) == 2)){
                    strcpy(start, bln);
                    strcpy(bln, end);
                }
                else if((abs((int)(end[0] - brn[0])) == 2 && abs((int)(end[1] - brn[1])) == 1) || (abs((int)(end[0] - brn[0])) == 1 && abs((int)(end[1] - brn[1])) == 2)){
                    strcpy(start, brn);
                    strcpy(brn, end);
                }
                break;
            default:
                strcpy(piece, "King");
                strcpy(start, bk);
                strcpy(bk, end);
                break;
            }
        }

        if(mv != 45){
            fprintf(outfile,"INSERT INTO T1 VALUES (%d, \"%s\", \"%s\", \"%s\", \"%s\", %d, %d ,%d, %d);\n", mv, "Black", piece, start, end, isCap, isCas, isCheck, isCMate);
        }

        mv++;
    }
    fclose(infile);
    fclose(outfile);
}