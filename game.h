#define _CRT_SECURE_NO_WARNINGS
#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define MINE 20
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
void menu();
void InitBoard(char board[ROWS][COLS], int row, int col,char ch);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetBorder(char board[ROWS][COLS], int row, int col, char ch);
int Player(char mineboard[ROWS][COLS], char showboard[ROWS][COLS], int row, int col);
char Search(char mineboard[ROWS][COLS], char showboard[ROWS][COLS], int row, int col, int x, int y);
void Mine(char mineboard[ROWS][COLS], int row, int col);