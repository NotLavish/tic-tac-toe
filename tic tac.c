#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int printBoard(char boxes[]){
	printf("%c | %c | %c\n", boxes[0], boxes[1], boxes[2]);
	printf("---------\n");
	printf("%c | %c | %c\n", boxes[3], boxes[4], boxes[5]);
	printf("---------\n");
	printf("%c | %c | %c\n", boxes[6], boxes[7], boxes[8]);
}

int doMove(char boxes[]) {
	int move;
	printf("Choose the box: you want to play: ");
	scanf("%d", &move);
	switch (move) {
		case 1:
			if (boxes[6] != ' '){
				break;
			} else {
				boxes[6] = 'X';
				break;
			}
		case 2:
			if (boxes[7] != ' '){
				break;
			} else {
				boxes[7] = 'X';
				break;
			}
		case 3:
			if (boxes[8] != ' '){
				break;
			} else {
				boxes[8] = 'X';
				break;
			}
		case 4:
			if (boxes[3] != ' '){
				break;
			} else {
				boxes[3] = 'X';
				break;
			}
		case 5:
			if (boxes[4] != ' '){
				break;
			} else {
				boxes[4] = 'X';
				break;
			}
		case 6:
			if (boxes[5] != ' '){
				break;
			} else {
				boxes[5] = 'X';
				break;
			}
		case 7:
			if (boxes[0] != ' '){
				break;
			} else {
				boxes[0] = 'X';
				break;
			}
		case 8:
			if (boxes[1] != ' '){
				break;
			} else {
				boxes[1] = 'X';
				break;
			}
		case 9:
			if (boxes[2] != ' '){
				break;
			} else {
				boxes[2] = 'X';
				break;
			}
	}
	return 0;
}

bool checkMove(char boxes[]) {
	int t[9] = {0,6,7,8,3,4,5,0,1,2};
	for (int i=1; i <= 7; i += 2) {
		if (boxes[t[i]] == boxes[t[i+1]] && boxes[t[i+1]] == boxes[t[i+2]] && boxes[t[i+2]] != ' ') {
			return true;
		}
	}
	
	for (int i=1; i <= 3; i++){
		if (boxes[t[i]] == boxes[t[i+2]] && boxes[t[i+2]] == boxes[t[i+5]] && boxes[t[i+5]] != ' ') {
			return true;
		}
	}
	
	if (boxes[t[1]] == boxes[t[5]] && boxes[t[5]] == boxes[t[9]] && boxes[t[9]] != ' ') {
		return true;
	} else if (boxes[t[3]] == boxes[t[5]] && boxes[t[5]] == boxes[t[7]] && boxes[t[7]] != ' ') {
		return true;
	} else{
		return false;
	}
}

int botMove(char boxes[]) {
	int r = rand() % 10;
	if (boxes[r] == ' ') {
		boxes[r] = 'O';
	} else {
		botMove(boxes);
	}
}
int main(void) {
  char boxes[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  srand(time(NULL));
  for(;;) {
  	system("cls");
	printf("The boxes correspond to the numpad\n");
  	printBoard(boxes);
  	doMove(boxes);
  	if (checkMove(boxes)) {
  		system("cls");
  		printBoard(boxes);
  		printf("Won!");
  		break;
		  } else {
			botMove(boxes);
			printBoard(boxes);
			if (checkMove(boxes) == true) {
  				system("cls");
  				printBoard(boxes);
  				printf("Bot Won!");
  				break;
	  			}
		}
	} 
}