#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PLAYER_LETTER 'O'
#define COMPUTER_LETTER 'X'
#define SIZE 3
void drawBoard(char board[][SIZE]){
	int i,j; char ch;
	printf("-----------\n");
	for(i=0;i<SIZE;i++){
		printf("|");
		for(j=0;j<SIZE;j++){
			if (board[i][j]=='\0')
				ch=' ';
			else
				ch=board[i][j];
			printf(" %c ",ch);
		}printf("|\n");
	}printf("-----------\n");
}
char whoGoesFirst(int i){
	if(i%2==1){
		printf("The computer will go first.\n");return 0;
	}
	else{
		printf("Player will go first.\n");return 1;
	}
}
void getPlayerMove(char board[][SIZE]){
	int n;printf("Please, select a location from the numeric keypad. (1~9) :");scanf("%d",&n);
	switch(n){
		case 1:if(board[2][0]==NULL){
					board[2][0]=PLAYER_LETTER;
				}
			else{
				  printf("Not an empty seat\n");getPlayerMove(board);
			   }break;
		case 2:if(board[2][1]==NULL){
					 board[2][1]=PLAYER_LETTER;
			   }
			   else{
				  printf("Not an empty seat\n");getPlayerMove(board);
			   }break;
		case 3:if(board[2][2]==NULL){
					board[2][2]=PLAYER_LETTER;
				}
			   else{
				   printf("Not an empty seat\n");getPlayerMove(board);
			   }break;
		case 4:if(board[1][0]==NULL){
					board[1][0]=PLAYER_LETTER;
			   }
			   else{
				   printf("Not an empty seat\n"); getPlayerMove(board);
			   }break;
		case 5:if(board[1][1]==NULL){
					 board[1][1]=PLAYER_LETTER; 
			   }
			   else{
				  printf("Not an empty seat\n"); getPlayerMove(board);
			   }break;
		case 6:if(board[1][2]==NULL){
				     board[1][2]=PLAYER_LETTER;
			   }
			   else{
				  printf("Not an empty seat\n"); getPlayerMove(board);
			   }break;
		case 7:if(board[0][0]==NULL){
					board[0][0]=PLAYER_LETTER;
			   }
			   else{
				   printf("Not an empty seat\n"); getPlayerMove(board);
			   }break;
		case 8:if(board[0][1]==NULL){
					board[0][1]=PLAYER_LETTER;
			   }
			   else{
				   printf("Not an empty seat\n"); getPlayerMove(board);
			   }break;
		case 9:if(board[0][2]==NULL){
					board[0][2]=PLAYER_LETTER;
			   }
		   	   else{
				   printf("Not an empty seat\n"); getPlayerMove(board);
			   }break;
		default: printf("It is not a right key\n");getPlayerMove(board);break;
		}
}
void getComputerMove(char board[][SIZE]){
	int i,j;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if( ((board[i][0]==COMPUTER_LETTER&&board[i][1]==COMPUTER_LETTER) || (board[i][0]==COMPUTER_LETTER&&board[i][2]==COMPUTER_LETTER) || (board[i][1]==COMPUTER_LETTER&&board[i][2]==COMPUTER_LETTER) ) ){
				if(board[i][j]=='\0'){
					board[i][j]=COMPUTER_LETTER;return;
				}
			}
			if( ((board[0][i]==COMPUTER_LETTER&&board[1][i]==COMPUTER_LETTER) || (board[0][i]==COMPUTER_LETTER&&board[2][i]==COMPUTER_LETTER) || (board[1][i]==COMPUTER_LETTER&&board[2][i]==COMPUTER_LETTER))){
				if(board[j][i]=='\0'){
					board[j][i]=COMPUTER_LETTER;return;
				}
			}
		}
	}
	for(i=0;i<2;i++){
		if(board[i][i]==COMPUTER_LETTER&&board[i+1][i+1]==COMPUTER_LETTER){
			if(i==1){
				if(board[0][0]=='\0'){
					board[0][0]=COMPUTER_LETTER;return;
				}
			}
			if(board[2][2]=='\0'){
				board[2][2]=COMPUTER_LETTER;return;
			}
		}
	}	
	if(board[0][0]==COMPUTER_LETTER&&board[2][2]==COMPUTER_LETTER){
		if(board[1][1]=='\0'){
			board[1][1]=COMPUTER_LETTER;return;
		}
	}
	if(board[0][2]==COMPUTER_LETTER&&board[2][0]==COMPUTER_LETTER){
		if(board[1][1]=='\0'){
			board[1][1]=COMPUTER_LETTER;return;
		}
	}
	if(board[0][2]==COMPUTER_LETTER&&board[1][1]==COMPUTER_LETTER){
		if(board[2][0]=='\0'){
			board[2][0]=COMPUTER_LETTER;return;
		}
	}
	if(board[1][1]==COMPUTER_LETTER&&board[2][0]==COMPUTER_LETTER){
		if(board[0][2]=='\0'){
			board[0][2]=COMPUTER_LETTER;return;
		}
	}
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if( ((board[i][0]==PLAYER_LETTER&&board[i][1]==PLAYER_LETTER) || (board[i][0]==PLAYER_LETTER&&board[i][2]==PLAYER_LETTER) || (board[i][1]==PLAYER_LETTER&&board[i][2]==PLAYER_LETTER) ) ){
				if(board[i][j]=='\0'){
					board[i][j]=COMPUTER_LETTER;return;
				}
			}
			if( ((board[0][i]==PLAYER_LETTER&&board[1][i]==PLAYER_LETTER) || (board[0][i]==PLAYER_LETTER&&board[2][i]==PLAYER_LETTER) || (board[1][i]==PLAYER_LETTER&&board[2][i]==PLAYER_LETTER))){
				if(board[j][i]=='\0'){
					board[j][i]=COMPUTER_LETTER;return;
				}
			}
		}
	}
	for(i=0;i<2;i++){
		if(board[i][i]==PLAYER_LETTER&&board[i+1][i+1]==PLAYER_LETTER){
			if(i==1){
				if(board[0][0]=='\0'){
					board[0][0]=COMPUTER_LETTER;return;
				}
			}
			if(board[2][2]=='\0'){
				board[2][2]=COMPUTER_LETTER;return;
			}
		}
	}	
	if(board[0][0]==PLAYER_LETTER&&board[2][2]==PLAYER_LETTER){
		if(board[1][1]=='\0'){
			board[1][1]=COMPUTER_LETTER;return;
		}
	}
	if(board[0][2]==PLAYER_LETTER&&board[2][0]==PLAYER_LETTER){
		if(board[1][1]=='\0'){
			board[1][1]=COMPUTER_LETTER;return;
		}
	}
	if(board[0][2]==PLAYER_LETTER&&board[1][1]==PLAYER_LETTER){
		if(board[2][0]=='\0'){
			board[2][0]=COMPUTER_LETTER;return;
		}
	}
	if(board[1][1]==PLAYER_LETTER&&board[2][0]==PLAYER_LETTER){
		if(board[0][2]=='\0'){
			board[0][2]=COMPUTER_LETTER;return;
		}
	}
	//xtx
	if(board[1][1]=='\0'){
		board[1][1]=COMPUTER_LETTER;return;
	}//가운데
	if((board[1][1]==COMPUTER_LETTER&&board[0][1]==PLAYER_LETTER)||(board[1][1]==COMPUTER_LETTER&&board[1][0]==PLAYER_LETTER)){
		if(board[0][0]=='\0'){
			board[0][0]=COMPUTER_LETTER;return;
		}
		else if(board[1][0]=='\0'){
			board[1][0]=COMPUTER_LETTER;return;
		}
		else if(board[0][1]=='\0'){
			board[0][1]=COMPUTER_LETTER;return;
		}
	}
	if(board[1][1]==COMPUTER_LETTER&&board[1][2]==PLAYER_LETTER){
		if(board[0][2]=='\0'){
			board[0][2]=COMPUTER_LETTER;return;
		}
		else if(board[0][1]=='\0'){
			board[0][1]=COMPUTER_LETTER;return;
		}
		else if(board[1][2]=='\0'){
			board[1][2]=COMPUTER_LETTER;return;
		}
	}
	if(board[1][1]==COMPUTER_LETTER&&board[2][1]==PLAYER_LETTER){
		if(board[2][2]=='\0'){
			board[2][2]=COMPUTER_LETTER;return;
		}
		else if(board[1][2]=='\0'){
			board[1][2]=COMPUTER_LETTER;return;
		}
		else if(board[2][1]=='\0'){
			board[2][1]=COMPUTER_LETTER;return;
		}
	}
	if(board[1][0]==PLAYER_LETTER||board[0][1]==PLAYER_LETTER){	
		if(board[0][0]=='\0'){
			board[0][0]=COMPUTER_LETTER;return;
		}
	}
	if(board[0][1]==PLAYER_LETTER||board[1][2]==PLAYER_LETTER){
		if(board[0][2]=='\0'){
			board[0][2]=COMPUTER_LETTER;return;
		}
	}
	if(board[1][0]==PLAYER_LETTER||board[2][1]==PLAYER_LETTER){
		if(board[2][0]=='\0'){
			board[2][0]=COMPUTER_LETTER;return;
		}
	}
	if(board[2][1]==PLAYER_LETTER||board[1][2]==PLAYER_LETTER){
		if(board[2][2]=='\0'){
			board[2][2]=COMPUTER_LETTER;return;
		}
	}//두변 사이 모서리
	if(board[0][2]==PLAYER_LETTER&&board[2][0]==PLAYER_LETTER){
		if(board[1][2]=='\0'){
			board[1][2]=COMPUTER_LETTER;return;
		}
	}
	if(board[0][0]=='\0'){
		board[0][0]=COMPUTER_LETTER;return;
	}
	else if(board[0][0]==PLAYER_LETTER){
		if(board[1][0]=='\0'){
			board[1][0]=COMPUTER_LETTER;return;
		}
	}
	if(board[0][2]=='\0'){
		board[0][2]=COMPUTER_LETTER;return;
	}
	else if(board[0][2]=PLAYER_LETTER){
		if(board[1][2]=='\0'){
			board[1][2]=COMPUTER_LETTER;return;
		}
	}
	if(board[2][0]=='\0'){
		board[2][0]=COMPUTER_LETTER;return;
	}
	if(board[2][2]=='\0'){
		board[2][2]=COMPUTER_LETTER;return;
	}
}
int isWinner(char board[][SIZE],char letter){
	int i,j,n,ct=0;
	if(letter==PLAYER_LETTER){
		for(i=0;i<SIZE;i++){//가로 검사
			ct=0;
			for(j=0;j<SIZE;j++){
				if(board[i][j]==letter)
					ct++;
			}
			if(ct==3)
				return 1;
		}
		for(i=0;i<SIZE;i++){//세로 검사
			ct=0;
			for(j=0;j<SIZE;j++){
				if(board[j][i]==letter)
					ct++;
			}
			if(ct==3)
				return 1;
		}
		if(board[0][0]==letter&&board[1][1]==letter&&board[2][2]==letter)return 1;
		if(board[0][2]==letter&&board[1][1]==letter&&board[2][0]==letter)return 1;
		return 0;
	}
	if(letter==COMPUTER_LETTER){
		for(i=0;i<SIZE;i++){//가로 검사
			ct=0;
			for(j=0;j<SIZE;j++){
				if(board[i][j]==letter)ct++;
			}
			if(ct==3)return 1;
		}
		for(i=0;i<SIZE;i++){//세로 검사
			ct=0;
			for(j=0;j<SIZE;j++){
				if(board[j][i]==letter)ct++;
			}
			if(ct==3)return 1;
		}
		if((board[0][0]==letter&&board[1][1]==letter&&board[2][2]==letter)||(board[0][2]==letter&&board[1][1]==letter&&board[2][0]==letter))return 1;
		return 0;
	}
}
int isFull(char board[][SIZE]){
	int i,j;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			if(board[i][j]==NULL)
				return 0;
		}
	}return 1;
}
int ticTacToe(int a){
	char board[SIZE][SIZE]={'\0'};
	if(whoGoesFirst(a)==0){
		getComputerMove(board);
	}
	else{
		drawBoard(board);getPlayerMove(board);getComputerMove(board);
	}drawBoard(board);
	while(1){
		if(isFull(board)==0){
				getPlayerMove(board);
				if(isWinner(board,PLAYER_LETTER)==1){
					drawBoard(board);printf("Hooray! You have won the game!");return 0;
				}
				if(isFull(board)==0){
					getComputerMove(board);drawBoard(board);
					if(isWinner(board,COMPUTER_LETTER)==1){
						printf("The computer has beaten you! You lose.");return 2;
					}
				}
				else drawBoard(board);
		}
		else{
			printf("The game is a tie!");return 1;
		}
	}
}
int main(){ 
	int i, round; int results[3] = {0},p=1;
	srand(time(NULL));printf("How many times do you want to play the game? ");scanf("%d", &round);
	for(i=0; i<round; i++){ 
		printf("\n==========================================\n\n");printf("%d Time :",p);
		switch(ticTacToe(i)){
			case 0: results[0]++;break;
			case 1: results[1]++;break;
			case 2: results[2]++;break;
		}p++;
	}printf("\n\n%d win, %d draw and %d loss", results[0], results[1], results[2]);return 0;
}