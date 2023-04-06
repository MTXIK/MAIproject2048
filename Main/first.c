#include<stdio.h>

#include<stdlib.h>

#include <time.h>

#include <conio.h>

#define SIZE 4


void generete_new_numb(int board[SIZE][SIZE]) //генерация числа в случайном месте
{
time_t t1;
srand ((unsigned) time (&t1));
int x,y;
do {
x = rand() % SIZE;
y = rand() % SIZE;
} while (board[x][y] != 0);//board==имя поля
int b;
b = rand() % 2;
while (b < 1)
    b = rand() % 2;
board[x][y] = b * 2;//запись в матрицу
}


void print_board(int board[SIZE][SIZE], int *score) {
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%4d", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
    printf("%4d", *score);
    printf("\n");
}

void shift_left(int board[SIZE][SIZE], int *score) {
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
                        *score += board[i][j];
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
//    return score;
}

void shift_right(int board[SIZE][SIZE], int *score) {
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
                        *score += board[i][j];
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
//    return score;
}

void shift_up(int board[SIZE][SIZE], int *score) {
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
                        *score += board[i][j];
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
 //   return score;
}

void shift_down(int board[SIZE][SIZE], int *score) {
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
                        *score += board[i][j];
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
 //   return score;
}

int game_over(int board[SIZE][SIZE]) {
    int over = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                over = 0;
                break;
            }
            if (i < SIZE - 1 && board[i][j] == board[i + 1][j]) {
                over = 0;
                break;
            }
            if (j < SIZE - 1 && board[i][j] == board[i][j + 1]) {
                over = 0;
                break;
            }
        }
    }
    return over;
}

int main() {
 int score = 0;
 time_t t1;
 srand ((unsigned) time (&t1));
int board[SIZE][SIZE] = {
    0
};
generete_new_numb(board);
generete_new_numb(board);
print_board(board, &score);
while (!game_over(board)) {
    char move = getch();
    printf("Enter move (a, d, w, s): ");
    switch (move) {
    case 'a':
        shift_left(board, &score);
        break;
    case 'd':
        shift_right(board, &score);
        break;
    case 'w':
        shift_up(board, &score);
        break;
    case 's':
        shift_down(board, &score);
        break;
    default:
        printf("Invalid move!\n");
        continue;
    }
    generete_new_numb(board);
    print_board(board, &score);
    }
    printf("Game over!\n");
    return 0;
}



//gcc -c file.c

//ar rcs namebibl bsdkf.o dsad.o