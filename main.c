#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX_DIE		6

int rolldie(void)
{
	return rand()%MAX_DIE + 1;
}
int main(int argc, char *argv[]) {
	
	srand((unsigned)time(NULL)); 
	
	printf("************************************\n");
	printf("************************************\n");
	printf("             GAME START             \n");
	printf("************************************\n");
	printf("************************************\n");
	
//step1. initiallization(player name setting, variables)
board_initBoard();
//step2. turn play (do-while)
int cnt = 0;
int pos;
do{
	int die_result;
	int coinResult;
//2-1.status printing
	board_printBoardStatus();
//2-2. roll die
	die_result = rolldie();
//2-3. move (result)
	pos += die_result;
	printf("pos : %i (die:%i\n)", pos, die_result);
	
	coinResult += board_getBoardCoin(pos);
	printf("coin : %i\n",coinResult);	
	
//2-4. change turn, shark move 
	cnt++;
}while(cnt<5);
//step3. game end(winner printing)	
	
	
	
	printf("************************************\n");
	printf("************************************\n");
	printf("         !!CONGRATULATION!!         \n");
	printf("               THE END              \n");
	printf("************************************\n");
	printf("************************************\n");
	
	return 0;
}
