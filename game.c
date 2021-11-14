#include "game.h"
void game()
{
	int j = 1;
	char mineboard[ROWS][COLS];
	char showboard[ROWS][COLS];
	InitBoard(showboard, ROWS, COLS, '*');
	SetBorder(showboard, ROWS, COLS, ' ');
	InitBoard(mineboard, ROWS, COLS, ' ');
	SetBorder(mineboard, ROWS, COLS, ' ');
	Mine(mineboard, ROW, COL);
	while (j)
	{
		printf("一共%d个雷\n", MINE);
		DisplayBoard(showboard, ROWS, COLS);
		//DisplayBoard(mineboard, ROWS, COLS);
		j = Player(mineboard,showboard, ROWS, COLS);
		system("cls");
	}
	DisplayBoard(mineboard, ROWS, COLS);
	printf("返回菜单");
	getchar();
}
void menu()
{
	printf("################################################\n");
	printf("############         1.Play        #############\n");
	printf("############         2.Exit        #############\n");
	printf("################################################\n");
	printf("请输入:>");
}
void SetBorder(char board[ROWS][COLS], int row, int col,char ch)
{
	int i, j;
	char n = '0';
	for (i = 0 , j = 0; i < col; n++,i++)
	{
		board[j][i] = n;
	}
	for (i = 0, j = 0, n = '0'; i < col; n++, i++)
	{
		board[i][j] = n;
	}
	for (i = 0, j = row -1, n = '0'; i < col; n++,i++)
	{
		board[j][i] = n;
	}
	for (i = 0, j = row - 1, n = '0'; i < col; n++, i++)
	{
		board[i][j] = n;
	}
	board[row-1][col-1]='0';
}
void InitBoard(char board[ROWS][COLS], int row, int col,char ch)
{
	int i, j;
	for ( i = 0; i < row; i++)
	{
		for ( j = 0; j < col; j++)
		{
			board[i][j] = ch;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		if (i == 0)
		{
			printf(" ");
			for (int m = 0; m < col; m++)
			{
				printf("--- ");
			}
			printf("\n");
		}
		for (j = 0; j < col; j++)
		{
			if (j == 0)
			{
				printf("|");
			}
			printf(" %c |", board[i][j]);
		}
		printf("\n");
		for (int n = 0; n < col; n++)
		{
			if (n == 0)
			{
				printf("|");
			}
			printf("---|");
		}
		printf("\n");
	}
}
int Player(char mineboard[ROWS][COLS], char showboard[ROWS][COLS], int row, int col)
{
	int x, y,ret;
		printf("请输入扫雷坐标:>");
		scanf("%d%d", &x, &y);
		while (1)
		{
			if (x > 0 && x <= ROW && y > 0 && y <= COL)
			{
				if (showboard[x][y] == '*')
				{
					ret = Search(mineboard , showboard, ROWS, COLS, x, y);
					if (ret == '0')
					{
						printf("BOOM!!!");
						//DisplayBoard(mineboard, ROWS, COLS);
						return 0;
					}
					else
					{
						showboard[x][y] = ret;
						break;
					}
				}
				else
				{
					printf("坐标已被占用,请重新输入扫雷坐标:>");
					scanf("%d%d", &x, &y);
				}
			}
			else
			{
				printf("输入错误,请重新输入扫雷坐标:>");
				scanf("%d%d", &x, &y);
			}
			}
}
char Search(char mineboard[ROWS][COLS], char showboard[ROWS][COLS], int row, int col, int x, int y)
{
	int i,j;
	char count = '0';
	if (mineboard[x][y]=='0')
	{
		return '0';
	}
	else
	{
		for (i = x-1; i < x+2; i++)
		{
			for ( j = y-1; j < y + 2; j++)
			{
				if (mineboard[i][j] == '0')
					count++;
			}
		}
	}
	if (count == '0')
	{
		for (i = x - 1; i < x + 2; i++)
		{
			for (j = y - 1; j < y + 2; j++)
			{
				if (showboard[i][j] == '*')
				{
					showboard[i][j] = ' ';
				}
			}
		}
		return ' ';
	}
	return count;
}
void Mine(char mineboard[ROWS][COLS], int row, int col)
{
	int x, y,i,j = 0,temp;
	for ( i = 0; i <= MINE; i++)
	{
		if (j)
		{
			i = temp;
		}
		srand((unsigned int)time(NULL));
		x = (unsigned int)(rand() % row + 1);
		y = (unsigned int)(rand() % col + 1);
		if (mineboard[x][y] == '0')
		{
			j = 1;
		}
		else
		{
			j = 0;
			mineboard[x][y] = '0';
		}
		if (j)
		{
			temp = i;
		}
	}
}