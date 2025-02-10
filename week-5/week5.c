#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

 char board[10][10] = {
    { 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x','x' },  
    { 'x', 'R', 'P', '0', '0', '0', '0', 'p', 'r' ,'x'},  
    { 'x', 'N', 'P', '0', '0', '0', '0', 'p', 'n' ,'x'},  
    { 'x', 'B', 'P', '0', '0', '0', '0', 'p', 'b' ,'x'},  
    { 'x', 'Q', 'P', '0', '0', '0', '0', 'p', 'q' ,'x'},  
    { 'x', 'K', 'P', '0', '0', '0', '0', 'p', 'k' ,'x'},  
    { 'x', 'B', 'P', '0', '0', '0', '0', 'p', 'b' ,'x'},  
    { 'x', 'N', 'P', '0', '0', '0', '0', 'p', 'n' ,'x'},  
    { 'x', 'R', 'P', '0', '0', '0', '0', 'p', 'r','x' },
    { 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x' ,'x'}   
};
int KX = 5,KY =1;//since king is always unique to a color we can store its state
int kx = 5, ky =8; 

void findssq_white (char ssq[],char esq[],const char * pc,char move[],bool isCap, bool isCheck, bool isCM,int spx,int spy){
  //printf("esq = %s\n",esq);
  int x = esq[0]-'a'+1;
  int y = esq[1]-'0';
  
  //logic for white pieces
  
  int i =x,j=y;
  //printf("x= %d , y = %d \n",x,y);
  //printf("%c %c %c %c %c %c\n",board[i][0],board[i][1],board[i][2],board[i][3],board[i][4],board[i][5]);
  for (int ii = 8;ii>0;ii--){
    for (int jj= 1;jj<9;jj++){
      printf("%c ",board[jj][ii]);
    }
    printf("\n");
  }
    if (!strcmp(pc, "King")){
      board[x][y] = 'K';
      
      i = KX;
      y = KY;
      KX=x;
      KY=y;
    }


    else if (!strcmp(pc, "Pawn")){
      
      
      if (isCap){
        i = move[0] - 'a' + 1;
        j = y-1;

      }
      else {
        while (board[i][j]=='0'){
        j--;
        }
      }     
    board[x][y]='P';  
    }

//rook's special case is yet to be handled - NOW HANDLED!
    else if (!strcmp(pc, "Rook")){


      bool tofind = true;
      board[i][j]='0';

      while (board[i][j]=='0'){
        i++;//right
      }
      if (board[i][j]=='R'){tofind=false;}

      
      if (tofind){
        i=x;j=y;
        while (board[i][j]=='0'){
          i--;//left
        }
        if (board[i][j]=='R'){tofind=false;}
      }

      
      if (tofind){
        i=x;j=y;
        while (board[i][j]=='0'){
          j--;//bottom
        }
        if (board[i][j]=='R'){tofind=false;}
      }

      
      if (tofind){
        i=x;j=y;
        while (board[i][j]=='0'){
          j++;//up
        }
        if (board[i][j]=='R'){tofind=false;}
      }
    board[x][y]='R';
    if (spx!=0){i=spx;j=y;}
    if (spy!=0){i=x;j=spy;}

    }
 
 //special  case for bishop is left
    else if (!strcmp(pc, "Bishop")){
      bool tofind = true;
      board[i][j]='0';

      while (board[i][j]=='0'){
        i++;j++;//top-right diagonal
      }
      if ((spx==0 || spx==i) && (spy==0 || spy==j)){
        if (board[i][j]=='B') tofind=false;
      }

      
      if (tofind){
        i=x;j=y;
        while (board[i][j]=='0'){
          i--;j++;//top left diagonal
        }
        if ((spx==0 || spx==i) && (spy==0 || spy==j)){
          if (board[i][j]=='B') tofind=false;
        }
      }

      
      if (tofind){
        i=x;j=y;
        while (board[i][j]=='0'){
          i++;j--;//right-bottom diagonal
        }
        if ((spx==0 || spx==i) && (spy==0 || spy==j)){
          if (board[i][j]=='B') tofind=false;
        }
      }

      
      if (tofind){
        i=x;j=y;
        while (board[i][j]=='0'){
          i--;j--;//left-bottom diagonal
        }
        if ((spx==0 || spx==i) && (spy==0 || spy==j)){
          if (board[i][j]=='B') tofind=false;
        }
      }
    board[x][y]='B';
    //  if (spx!=0){
    //   i=spx;j=y;
    //   }



    }

    else if (!strcmp(pc, "Knight")){

      if (board[(i-1)%10][(j-2)%10]=='N'){
        i = i-1;
        j=  j-2;
      }
      if (board[(i-1)%10][(j+2)%10]=='N'){
        i = i-1;
        j=  j+2;
      }
      if (board[(i+1)%10][(j-2)%10]=='N'){
        i = i+1;
        j=  j-2;
      }
      if (board[(i+1)%10][(j+2)%10]=='N'){
        i = i+1;
        j=  j+2;
      }
     if (board[(i-2)%10][(j-1)%10]=='N'){
        i = i-2;
        j=  j-1;
      }
      if (board[(i-2)%10][(j+1)%10]=='N'){
        i = i-2;
        j=  j+1;
      }
      if (board[(i+2)%10][(j-1)%10]=='N'){
        i = i+2;
        j=  j-1;
      }
      if (board[(i+2)%10][(j+1)%10]=='N'){
        i = i+2;
        j=  j+1;
      }
      if (spx!=0){
        i = spx;
        int d = 3 - abs(x-spx);
        if (board[spx][y + d]=='N') {j = y+d;}
        if (board[spx][y - d]=='N') {j = y-d;}

      }
       if (spy!=0){
        j= spy;
        int d = 3 - abs(y-spy);
        if (board[x+d][spy]=='N') {i = x+d;}
        if (board[x-d][spy]=='N') {i = x-d;}

      }

      board[x][y]='N';

    }
    //special case of queen to be handled
    else if (!strcmp(pc, "Queen")){
       bool tofind = true;
      board[i][j]='0';

     
      while (board[i][j]=='0'){
        i++;//right
      }

      if ((spx==0 || spx==i) && (spy==0 || spy==j)){
        if (board[i][j]=='Q') tofind=false;
      }
      
      if (tofind){
        i=x;j=y;
        while (board[i][j]=='0'){
          i--;//left
        }
        if ((spx==0 || spx==i) && (spy==0 || spy==j)){
        if (board[i][j]=='Q') tofind=false;
      }
      }

      
      if (tofind){
        i=x;j=y;
        while (board[i][j]=='0'){
          j--;//bottom
        }
        if ((spx==0 || spx==i) && (spy==0 || spy==j)){
        if (board[i][j]=='Q') tofind=false;
      }
      }

      
      if (tofind){
        i=x;j=y;
        while (board[i][j]=='0'){
          j++;//up
        }
        if ((spx==0 || spx==i) && (spy==0 || spy==j)){
        if (board[i][j]=='Q') tofind=false;
      }
      }

        if (tofind){
        i=x;j=y;
        while (board[i][j]=='0'){
          i++;j++;//top-right diagonal
        }
        if ((spx==0 || spx==i) && (spy==0 || spy==j)){
        if (board[i][j]=='Q') tofind=false;
      }
      }

      
      if (tofind){
        i=x;j=y;
        while (board[i][j]=='0'){
          i--;j++;//top left diagonal
        }
        if ((spx==0 || spx==i) && (spy==0 || spy==j)){
        if (board[i][j]=='Q') tofind=false;
      }
      }

      
      if (tofind){
        i=x;j=y;
        while (board[i][j]=='0'){
          i++;j--;//right-bottom diagonal
        }
        if ((spx==0 || spx==i) && (spy==0 || spy==j)){
        if (board[i][j]=='Q') tofind=false;
      }
      }

      
      if (tofind){
        i=x;j=y;
        while (board[i][j]=='0'){
          i--;j--;//left-bottom diagonal
        }
        if ((spx==0 || spx==i) && (spy==0 || spy==j)){
        if (board[i][j]=='Q') tofind=false;
      }
      }

    board[x][y]='Q';


    }


  board[i][j]= '0';  
  ssq[0] = i + 'a' -1;
  ssq[1] = '0'+ j;
  return;

}  


int main (){
  
  
  int mv =1;
  
  
  //TASK 2 
  FILE* fptr = fopen("gukesh-makan.csv","r");
  FILE* fout = fopen("gukesh-makan-01.sql","w");
  if (fptr==NULL){printf("can't open file");}
  int xx = 45;
  while (xx--){
    char s[1000];
    char move[10];
    fgets(s,1000,fptr);
    
    char *tok = strtok(s,",");
    strcpy(move,tok);
   
    printf("%s\n",move);
    bool isCap = false,isCas = false,isCheck=false,isCM=false;
    const char * pc;
    char ssq[3],esq[3];
    ssq[2]='\0';
    esq[2] = '\0';
     
      
    if (move[0]=='1' && move[1]=='-' && move[2]=='0'){  
      printf("White wins!\n");
      break;
     }
     
      if (move[0]=='0' && move[1]=='-' && move[2]=='1'){  
      printf("Black wins!\n");
      break;
     }
     
      if (!strcmp("1/2x/2",move)){  
      printf("Draw.\n");
      break;
     }
     
     switch (move[0]) {
          case 'K' : pc = "King";break;
          case 'Q' : pc = "Queen";break;
          case 'R' : pc = "Rook";break;
          case 'B' : pc = "Bishop";break;
          case 'N' : pc = "Knight";break;
          default : pc = "Pawn";        
      
      }
    
    //check move
    if (move[2]=='+' || move[3]=='+' || move[4]=='+'){
      isCheck = true;
    }
    
     //check-mate move
    if (move[2]=='#' || move[3]=='#' || move[4]=='#'){
      isCM = true;
    }
    
    
     //capture move
    if (move[1]=='x' || move[2]=='x' ){
      isCap = true;
    }
      
    //standard pawn move
    if (move[1]>'0' && move[1] < '9'){
      
      esq[0] = move[0];
      esq[1] = move[1];
      move[2]='\0';
      move[3]='\0';
      move[4]='\0';
      //printf("standard pawn update? esq = %s\n",esq);
    }
    
     //any other standard move
    else if (move[2]>'0' && move[2] < '9'){
      esq[0] = move[1];
      esq[1] = move[2];
      move[3]='\0';
      move[4]='\0';
    }
  
    char sp = move[1];
    int spx=0,spy=0;
      //some special move (capture or resolving ambiguity)
    if (move[3]>'0' && move[3] < '9'){
    
      esq[0] = move[2];
      esq[1] = move[3];
      if (sp>'0' && sp<'9'){
        spy = sp- '0';
      }
     if (sp>='a' && sp<'i'){
        spx = sp- 'a'+1;
      }
      //printf("mid-check? esq = %s\n",esq);
      
    }
    //some special move (capture && resolving ambiguity)
    else if (move[3]>'0' && move[3] < '9'){
    
      esq[0] = move[2];
      esq[1] = move[3];

      if (sp>'0' && sp<'9'){
        spy = sp- '0';
      }
     if (sp>='a' && sp<'i'){
        spx = sp- 'a'+1;
      }


      
    }
    
    
    if (move[2]=='='){
      //pawn gets promoted
      pc = "Pawn";
    }
    
    // ssq[0] = 'a' + (mv%7);
    // ssq[1] = '3' + (mv%4);

    

     //castling move
     if (!strcmp("O-O",move)){
     
     pc = "King";
     isCas = true;
     ssq[0]='e';
     ssq[1]='1';
     esq[0]='g';
     esq[1]='1';
     board[5][1]='0';
     board[8][1]='0';
     board[7][1]='K';
     board[6][1]='R';
     }
      else if (!strcmp("O-O-O",move)){
     
     pc = "King";
     isCas = true;
     ssq[0]='e';
     ssq[1]='1';
     esq[0]='c';
     esq[1]='1';

     board[5][1]='0';
     board[1][1]='0';
     board[3][1]='K';
     board[4][1]='R';
     }
   
     else {
      //lets find ssq
    //printf("before passing esq = %s\n",esq);
    findssq('W',ssq,esq,pc,move,isCap,isCheck,isCM,spx,spy);
     }
     
    
  //fprintf(fout,"INSERT INTO T1 (move_no,player,piece,ssq,esq,isCap,isCas,isCheck,isCM) VALUES ('%d','WHITE','%s','%s','%s',%d,%d,%d,%d); \n",mv,pc,ssq,esq,isCap,isCas,isCheck,isCM);
  printf("INSERT INTO T1 (move_no,player,piece,ssq,esq,isCap,isCas,isCheck,isCM) VALUES ('%d','WHITE','%s','%s','%s',%d,%d,%d,%d)\n",mv,pc,ssq,esq,isCap,isCas,isCheck,isCM);
    mv++;
    
    
    
    
    //now move f|| black starts
    
    tok = strtok(NULL,",");

   
   
    strcpy(move,tok);
    printf("%s",move);
    
    
    isCap = false;isCas = false;isCheck=false;isCM=false;
    
    if (move[0]=='1' && move[1]=='-' && move[2]=='0'){  
      printf("White wins!\n");
      break;
     }
     
      if (move[0]=='0' && move[1]=='-' && move[2]=='1'){  
      printf("Black wins!\n");
      break;
     }
     
      if (!strcmp("1/2x/2",move)){  
      printf("Draw.\n");
      break;
     }
     
     
     switch (move[0]) {
          case 'K' : pc = "King";break;
          case 'Q' : pc = "Queen";break;
          case 'R' : pc = "Rook";break;
          case 'B' : pc = "Bishop";break;
          case 'N' : pc = "Knight";break;
          default : pc = "Pawn";        
      
      }
    
    //check move
    if (move[2]=='+' || move[3]=='+' || move[4]=='+'){
      isCheck = true;
    }
    
     //check-mate move
    if (move[2]=='#' || move[3]=='#' || move[4]=='#'){
      isCM = true;
    }
    
    
     //capture move
    if (move[1]=='x' || move[2]=='x' ){
      isCap = true;
    }
    
    //standard pawn move
    if (move[1]>'0' && move[1] < '9'){
      
      esq[0] = move[0];
      esq[1] = move[1];
    }
    
     //any other standard move
    else if (move[2]>'0' && move[2] < '9'){
      esq[0] = move[1];
      esq[1] = move[2];
    }
    
    
      //some special move (capture or resolving ambiguity)
    else if (move[3]>'0' && move[3] < '9'){
    
      esq[0] = move[2];
      esq[1] = move[3];
    }
    
    if (move[2]=='='){
      //pawn gets promoted
      pc = "Pawn";
    }
  

    



     //castling move
     if (!strcmp("O-O",move)){
     
     pc = "King";
     isCas = true;
     ssq[0]='e';
     ssq[1]='8';
     esq[0]='g';
     esq[1]='8';

     board[5][8]='0';
     board[8][8]='0';
     board[7][8]='K';
     board[6][8]='R';
     }
      if (!strcmp("O-O-O",move)){
     
     pc = "King";
     isCas = true;
     ssq[0]='e';
     ssq[1]='8';
     esq[0]='c';
     esq[1]='8';


     board[5][8]='0';
     board[1][8]='0';
     board[3][8]='K';
     board[4][8]='R';
     }
     
    
 // fprintf(fout,"INSERT INTO T1 (move_no,player,piece,ssq,esq,isCap,isCas,isCheck,isCM) VALUES ('%d','BLACK','%s','%s','%s',%d,%d,%d,%d);\n",mv,pc,ssq,esq,isCap,isCas,isCheck,isCM);
  printf("INSERT INTO T1 (move_no,player,piece,ssq,esq,isCap,isCas,isCheck,isCM) VALUES ('%d','BLACK','%s','%s','%s',%d,%d,%d,%d) \n\n",mv,pc,ssq,esq,isCap,isCas,isCheck,isCM);
    mv++;
  
 
  }



 // fprintf(fout,"%s : ",rec||ds[i].place);
 
  
  printf("\nWorking! Thank you.\n");
  
return 0;
}