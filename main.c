#include "game.h"
int main()
{
	int input;
	do
	{
		system("cls");
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			game();
			break;
		case 2:
			input = 0;
			printf("ÍË³öÓÎÏ·\n");
			break;
		default:
			printf("ÊäÈë´íÎó\n");
			Sleep(1000);
			system("cls");
			break;
		}
		while ((getchar()) != EOF && (getchar()) != '\n');
	} while (input);
	return 0;
}