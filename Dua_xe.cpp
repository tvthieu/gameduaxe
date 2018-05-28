#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include "function.h"
#include "function.cpp"

using namespace std;

int main()
{

	int x = 25, y = 10; 
	int x1 = 2, y1; 
	int x2 = 5, y2 = 8;
	int x3 = 3, y3 = 5;
	int x4 = 4, y4;
	int level1 = 20;
	int level2 = 40; 
	int a = 0;
	int diem = 0;
	while(true)
	{
		a++;
		if(a % 2 != 0)
		{
			VeDuongDua_1();
		}
		else
		{
			VeDuongDua_2();
		}
		
		srand(time(0)); 
		if(rand() % 2 ){
			y1 = 27 - rand() % 26; 
		}
		else {
			y1 = 2 + rand() % 26; 
		}
		

		VeXePlayer(x, y);
		VeXeChuongNgaiVat(x1, y1);
		VeXeChuongNgaiVat(x2, y2);
		if(diem >= level1){
			VeXeChuongNgaiVat(x3, y3);
		}
		if(diem >= level1){
			y4 = 1 + rand() % 26; 
			VeXeChuongNgaiVat(x4, y4);
		}
		XoaManHinh();

		InDuongDua();

		DiChuyenXe(x, y);

		Sleep(0);

		if(a >= 30)
		{
			a = 0;
		}


		if(map[x][y] == 'o' || map[x - 1][y - 1] == 'o' || map[x + 1][y - 1] == 'o' || map[x - 1][y + 1] == 'o' || map[x + 1][y + 1] == 'o')
		{
			Beep(523,500);
			printf("\a");
			VeHinh(10, 10, "\t\t\t\t\t", 116);
			VeHinh(10, 11, "\t\t\t\t\t", 116);
			VeHinh(10, 12, "\t\t\t\t\t", 116);
			VeHinh(10, 13, "\t\t\t\t\t", 116);
		
		
			VeHinh(13, 11, "Game over!", 116);
			VeHinh(13, 13, "Diem: ", 116);
			InDiem(18, 13, diem/2, 116);
			
			return 0; // Ket thuc
		}

		XoaXeChuongNgai(x1, y1);
		x1++;
		if(x1 == 31)
		{
			x1 = 2;
			diem ++;
		}
		
		XoaXeChuongNgai(x2, y2);
		x2++;
		if(x2 == 31)
		{
			x2 = 5;
			y2 = 27 - rand() % 26;
			diem ++;
		}
		
		XoaXeChuongNgai(x3, y3);
		x3++;
		if(x3 == 31){
			x3 = 3;
			y3 = 3 + rand() % 26;
			diem ++;
		}
		
		XoaXeChuongNgai(x4, y4);
		x4++;
		if(x4 == 31)
		{
			x4 = 4;
			diem ++;
		}
		
		VeHinh(55, 10, "Diem: ", 6);
		InDiem(60, 10, diem/2, 6);
	}
	system("pause");
	return 0;
}
