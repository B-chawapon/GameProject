#include<stdio.h>
#include<Windows.h>
#include<time.h>
void draw_star(int x, int y);
void gotoxy(int x, int y);
void erase_star(int x, int y);
void setcursor(bool visible);
int xran, yran;
int main()
{
	int i;
	setcursor(0);
	srand(time(NULL));
	for (i = 0; i < 20; i++)
	{
		xran = rand() % 100;
		yran = rand() % 10;
		//printf("1 %d %d\n", xran, yran);
		while (yran<2||yran>5)
		{
			yran = rand() % 10;
		}
		while (xran < 10 || xran>70)
		{
			xran = rand() % 100;
		}
		//printf("2  %d %d\n", xran, yran);
		draw_star(xran, yran);
	}
	return 0;
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_star(int x, int y)
{
	gotoxy(x, y);
	printf("*");
}
void erase_star(int x, int y)
{
	gotoxy(x, y);
	printf(" ");
}

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
