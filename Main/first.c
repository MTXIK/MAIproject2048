#include<stdio.h>

#include<stdlib.h>

#include <time.h>

#define SIZE 4

int main() {
	time_t t1;
	srand ((unsigned) time (&t1));
	int board[SIZE][SIZE] = {
	  0
	};
}

void generete_new_numb() //генерация числа в случайном месте
{
time_t t1;
srand ((unsigned) time (&t1));
int x,y;
do {
x = rand() % SIZE;
y = rand() % SIZE;
} while (board[x][y] != 0;//board==имя поля
board[x][y] = (rand() % 2)*2;
}
void print_board(int board[SIZE][SIZE]) {
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%4d", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void shift_left(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE - 1; j++) {
            if (board[i][j] == 0) {
                for (int k = j + 1; k < SIZE; k++) {
                    if (board[i][k] != 0) {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
            else {
                for (int k = j + 1; k < SIZE; k++) {
                    if (board[i][k] == board[i][j]) {
                        board[i][j] *= 2;
                        board[i][k] = 0;
                        break;
                    }
                    else if (board[i][k] != 0) {
                        break;
                    }
                }
            }
        }
    }
}

void shift_right(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = SIZE - 1; j >= 1; j--) {
            if (board[i][j] == 0) {
                for (int k = j - 1; k >= 0; k--) {
                    if (board[i][k] != 0) {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
            else {
                for (int k = j - 1; k >= 0; k--) {
                    if (board[i][k] == board[i][j]) {
                        board[i][j] *= 2;
                        board[i][k] = 0;
                        break;
                    }
                    else if (board[i][k] != 0) {
                        break;
                    }
                }
            }
        }
    }
}

void shift_up(int board[SIZE][SIZE]) {
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE - 1; i++) {
            if (board[i][j] == 0) {
                for (int k = i + 1; k < SIZE; k++) {
                    if (board[k][j] != 0) {
                        board[i][j] = board[k][j];
                        board[k][j] = 0;
                        break;
                    }
                }
            }
            else {
                for (int k = i + 1; k < SIZE; k++) {
                    if (board[k][j] == board[i][j]) {
                        board[i][j] *= 2;
                        board[k][j] = 0;
                        break;
                    }
                    else if (board[k][j] != 0) {
                        break;
                    }
                }
            }
        }
    }
}

void shift_down(int board[SIZE][SIZE]) {
    for (int j = 0; j < SIZE; j++) {
        for (int i = SIZE - 1; i >= 1; i--) {
            if (board[i][j] == 0) {
                for (int k = i - 1; k >= 0; k--) {
                    if (board[k][j] != 0) {
                        board[i][j] = board[k][j];
                        board[k][j] = 0;
                        break;
                    }
                }
            }
            else {
                for (int k = i - 1; k >= 0; k--) {
                    if (board[k][j] == board[i][j]) {
                        board[i][j] *= 2;
                        board[k][j] = 0;
                        break;
                    }
                    else if (board[k][j] != 0) {
                        break;
                    }
                }
            }
        }
    }
}
