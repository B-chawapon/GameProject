#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<math.h>
void draw_ship(int x, int y);
void gotoxy(int x, int y);
void erase_ship(int x, int y);
void setcursor(bool visible);
void setcolor(int fg, int bg);
void draw_bullet(int a, int b);
void erase_bullet(int a, int b);
void map();
char ch = ' ';
int posx = 38, posy = 20;
int posbx = 38  , posby =20;
int movex, movey = 0;
bool bullet = 0;
int stack = 0;
int main()
{
	//map();
	setcursor(0);
	draw_ship(posx, posy);
	do
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'a')
			{
				movex = -1;
			}
			if (ch == 'd')
			{
				movex = 1;
			}
			if (ch == 's')
			{
				movex = 0;
			}
			if (ch == ' ')
			{
				bullet = 1;
				posbx = 38;
				posby = 19;
				stack += 1;
			
			}
			if (ch == 'r') // RELOAD AMMO
			{
				stack = 0;
			}
			
		}
		if (movex == -1)
		{
			if (posx >= 2)
			{
				erase_ship(posx, posy);
				draw_ship(--posx, posy);
			}
		}
		if (movex == 1)
		{
			if (posx <= 80)
			{
				erase_ship(posx, posy);
				draw_ship(++posx, posy);

			}
		}
		Sleep(9);
		if (bullet == 1)
		{
			if (stack <= 5)
			{
				do
				{
					erase_bullet(posx + 3, posby);
					if (posby == 0)
					{
						bullet = 0;
						break;
					}
					draw_bullet(posx + 3, --posby);
					Sleep(20);
				} while (posby >= 0);
				
			}
			else if (stack > 5)
			{
				printf("RELOAD AMMO  PRESS r");
				continue;
			}
		}
	fflush(stdin);
	} while (ch != 'x');

	return 0;
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(2, 4);
	printf(" <-0-> ");
}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(2, 0);
	printf("       ");
}
void draw_bullet(int a, int b)
{
	gotoxy(a, b);
	setcolor(2, 4);
	printf(" ");
}
void erase_bullet(int a, int b)
{
	gotoxy(a, b);
	setcolor(2, 0);
	printf("  ");
}

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void map()
{
	for (int i = 0; i <= 21; i++)
	{
		for (int j = 0; j <= 88; j++)
		{
			if (i == 0 || i == 21)
			{
				printf("*");
			}
			else
			{
				if (j == 0 || j == 88)
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}
