#include <stdio.h>
#include <conio.h>
#define X 8

char board[X][X] = {
	"RHBKQBHR", 
	"PPPPPPPP",
	"________",
	"________",
	"________",
	"________",
	"PPPPPPPP",
	"RHBKQBHR", 
};

void display();
void input(int x, int y);
void rover(int x, int y);

int main(){
	rover(5, 5);
	gotoxy(0, 35);
	return 0;
}

void display(){
	gotoxy(0, 0);
	printf("Use (wasd) for directions and (l) for drag and drop");
	gotoxy(5, 5);
	for(int i = 0; i < X; i++){
		for(int j = 0; j < X; j++){
			printf("%c  ", board[i][j]);
		}
		printf("\n\n    ");
	}
}

void input(int x, int y){
	static char ch = 'x';
	x = x - 5;
	x = x/3;
	y = y - 5;
	y = y/2;
	if(ch == 'x'){
	ch = board[y][x];
	board[y][x] = '_';
	}
	else{
		board[y][x] = ch;
		ch = 'x';
	}
}

void rover(int x, int y){
	display();
	if(y < 5 || y > 19){
		y = y - 16;
	}
	else if(x < 5 || x > 26){
		x = x - 24;
	}
	gotoxy(x, y);
	switch(getch()){
		case 'w': y = y - 2; gotoxy(x, y); break;
		case 'a': x = x - 3; gotoxy(x, y); break;
		case 's': y = y + 2; gotoxy(x, y); break;
		case 'd': x = x + 3; gotoxy(x, y); break;
		case 'l': input(x, y); break;
		default: rover(x, y); break; exit(0);
	}
	rover(x, y);
}