#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
char g_board[ROW][COL];
void Print();
void Init() {
	for (int row = 0; row < ROW; ++row) {
		for (int col = 0; col < COL; ++col) {
			g_board[row][col] = ' ';
		}
	}
	Print();
}
void Print() {
	for (int row = 0; row < ROW; ++row){
		printf("| %c | %c | %c |\n", g_board[row][0], g_board[row][1], g_board[row][2]);
		if (row != ROW - 1) {
			printf("|---|---|---|\n");
		}
	}
}

void PlayerMove() {
	int row = 0;
	int col = 0;
	while (1) {
		printf("请玩家输入坐标（row col):");
		int row, col;
		scanf("%d %d", &row, &col);
		if (row < 0 || row > ROW || col < 0 || col > COL){
			printf("输入的坐标非法，请重新输入！\n");
			continue;
		}
		if (g_board[row - 1][col - 1] != ' ') {
			printf("请重新输入\n");
			continue;
		}
		g_board[row - 1][col - 1] = 'x';
		break;


	}

}


void ComputerMove() {
	printf("电脑落子！\n");
	printf("\n");
	srand((unsigned)time(NULL));
	while (1){
		int row = rand() % ROW;
		int col = rand() % COL;
		if (g_board[row][col] != ' '){
			continue;
		}
		g_board[row][col] = 'o';
		break;
	}
	Print();
}

int Ssr() {
	for (int row = 0; row < ROW; ++row) {
		for (int col = 0; col < COL; ++col) {
			if (g_board[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

char CheckWinner() {
	for (int row = 0; row < ROW; ++row) {
		if (g_board[row][0] == g_board[row][1]
			&& g_board[row][0] == g_board[row][2]) {
			return g_board[row][0];
		}
	}
	for (int col = 0; col < COL; ++col) {
		if (g_board[0][col] == g_board[1][col]
			&& g_board[0][col] == g_board[2][col]) {
			return g_board[0][col];
		}
	}
	if (g_board[0][0] == g_board[1][1]
		&& g_board[0][0] == g_board[2][2]) {
		return g_board[1][1];
	}
	if (g_board[0][2] == g_board[1][1]
		&& g_board[0][2] == g_board[2][0]) {
		return g_board[1][1];
	}
	int ret = Ssr();
	if (ret == 1) {
		return 'q';
	}
	return ' ';
}

int main() {
	Init();
	char winner;
	while (1) {
		PlayerMove();
		winner = CheckWinner();
		if (winner != ' ') {
			Print();
			break;
		}
		ComputerMove();
		winner = CheckWinner();
		if (winner != ' ') {
			Print();
			break;
		}
	}
	if (winner == 'x'){
		printf("玩家胜利\n");
	}
	else if (winner == 'o') {
		printf("电脑胜利\n");
	}
	else if (winner == 'q') {
		printf("平局\n");
	}
	system("pause");
	return 0;
}
