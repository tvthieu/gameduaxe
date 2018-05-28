#include"function.h"
#include <string>
#include <Windows.h>
#include <ctime>
#include <iostream>
using namespace std;
char map[50][50];
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle

(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void gotoxy(int x,int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x-1,y-1};
	hConsoleOutput = GetStdHandle

(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput ,

Cursor_an_Pos);
}

void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle

(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void VeDuongDua_1()
{

	for(int i = 0; i < 30; i++)
	{
		map[i][0] = '|';
		map[i][29] = '|';
		if(i % 2 == 0)
		{
			map[i][14] = '|';
		}

		for(int j = 1; j < 29 && j != 14; j++)
		{
			map[i][j] = ' ';
		}
	}
}

void VeDuongDua_2()
{

	for(int i = 0; i < 30; i++)
	{
		map[i][0] = '|';
		map[i][29] = '|';
		if(i % 2 != 0)
		{
			map[i][14] = '|';
		}

		for(int j = 1; j < 29 && j != 14; j++)
		{
			map[i][j] = ' ';
		}
	}
}

void InDuongDua()
{

	for(int i = 0; i < 30; i++)
	{
		cout << "\t\t";
		for(int j = 0; j < 30; j++)
		{
			if(j == 0 || j == 29)
			{
				textcolor(127);
				map[i][j] = ' ';
				cout << map[i][j];
				textcolor(7);
			}


			else if(map[i][j] == 'X' || map[i][j] == '*' || map[i][j] == '!')
			{
				textcolor(4); 
				cout << map[i][j];
				textcolor(7); 
			}

			else if(map[i][j] == 'o')
			{
				textcolor(160);
				cout << map[i][j];
				textcolor(7);
			}
			else if(j == 14)
			{
				textcolor(15);
				cout << map[i][j];
				textcolor(7);

				map[i][j] = ' '; 
			}


			else
			{
				cout << map[i][j];
			}
		}
		cout << endl;
	}
}

void VeXePlayer(int x, int y)
{
	map[x][y] = 'X'; 
	map[x][y - 1] = '!';
	map[x][y + 1] = '!'; 
	map[x - 1][y - 1] = '*'; 
	map[x + 1][y - 1] = '*'; 
	map[x - 1][y + 1] = '*'; 
	map[x + 1][y + 1] = '*'; 
}

void VeXeChuongNgaiVat(int x, int y)
{
	map[x][y] = 'o'; 
	map[x - 1][y - 1] = 'o'; 
	map[x + 1][y - 1] = 'o'; 
	map[x - 1][y + 1] = 'o'; 
	map[x + 1][y + 1] = 'o'; 
}

void XoaXeChuongNgai(int x, int y)
{
	map[x][y] = ' '; 
	map[x][y - 1] = ' '; 
	map[x][y + 1] = ' '; 
	map[x - 1][y - 1] = ' ';
	map[x + 1][y - 1] = ' ';
	map[x - 1][y + 1] = ' '; 
	map[x + 1][y + 1] = ' ';
}
void VeHinh(int x, int y, string str, int color)
{
	gotoxy(x, y); 
	textcolor(color); 
	cout << str;
	textcolor(7); 
}
void InDiem(int x, int y, int diem, int color)
{
	gotoxy(x, y);
	textcolor(color); 
	cout << diem;
	textcolor(7); 
}
void DiChuyenXe(int &x, int &y) 
{

	if(GetAsyncKeyState(VK_LEFT))
	{
		if(y > 2)
		{
			if(map[x][y] == 'o' || map[x - 1][y - 1] == 'o' || map[x + 1][y - 1] == 'o' || map[x - 1][y + 1] == 'o' || map[x + 1][y + 1] == 'o')
			{
				exit(0);
			}

			map[x][y] = ' ';
			map[x][y - 1] = ' ';
			map[x][y + 1] = ' '; 
			map[x - 1][y - 1] = ' '; 
			map[x + 1][y - 1] = ' '; 
			map[x - 1][y + 1] = ' '; 
			map[x + 1][y + 1] = ' '; 

			y--;
			VeXePlayer(x, y); 


		}

	}


	else if(GetAsyncKeyState(VK_RIGHT))
	{
		if(y <= 26)
		{
			if(map[x][y] == 'o' || map[x - 1][y - 1] == 'o' || map[x + 1][y - 1] == 'o' || map[x - 1][y + 1] == 'o' || map[x + 1][y + 1] == 'o')
			{
				exit(0);
			}

			map[x][y] = ' ';
			map[x][y - 1] = ' '; 
			map[x][y + 1] = ' '; 
			map[x - 1][y - 1] = ' ';
			map[x + 1][y - 1] = ' ';
			map[x - 1][y + 1] = ' '; 
			map[x + 1][y + 1] = ' '; 

			y++; 
			VeXePlayer(x, y);


		}
	}

	else if(GetAsyncKeyState(VK_UP))
	{
		if(x > 1)
		{
			if(map[x][y] == 'o' || map[x - 1][y - 1] == 'o' || map[x + 1][y - 1] == 'o' || map[x - 1][y + 1] == 'o' || map[x + 1][y + 1] == 'o')
			{
				exit(0);
			}

			map[x][y] = ' '; 
			map[x - 1][y - 1] = ' '; 
			map[x + 1][y - 1] = ' '; 
			map[x - 1][y + 1] = ' '; 
			map[x + 1][y + 1] = ' '; 

			x--; 
			VeXePlayer(x, y); 
		}
	}

	else if(GetAsyncKeyState(VK_DOWN))
	{
		if(x <= 27)
		{
			if(map[x][y] == 'o' || map[x - 1][y - 1] == 'o' || map[x + 1][y - 1] == 'o' || map[x - 1][y + 1] == 'o' || map[x + 1][y + 1] == 'o')
			{
				exit(0); 
			}

			map[x][y] = ' ';
			map[x][y - 1] = ' ';
			map[x][y + 1] = ' ';
			map[x - 1][y - 1] = ' ';
			map[x + 1][y - 1] = ' ';
			map[x - 1][y + 1] = ' ';
			map[x + 1][y + 1] = ' ';

			x++; 
			VeXePlayer(x, y); 
		}
	}
}

