#include <conio.h>
#include <iostream>
#include "pyramid_4.h"
#include "pyramid.h"

using namespace::std;

void cur();
void mainmu();

int q = 1,p=0;
int main() {
	setlocale(0, "Russian");
	mainmu();
	if (p == 1) {
		cur();
	}
	return 0;
}
void mainmu() {
	int c, tr = 1;
	while (tr)
	{
	cout << "\t\t\t\t\t\tКурсовая_работа№20" << endl;
	cout << "1)New Game" << endl;
	cout << "2)Help" << endl;
	cout << "3)Exid" << endl;
	c = _getch();
		switch (c) {
		case 49:
			system("cls");
			p = 1; tr = 0;
			break;
		case 50:
			system("cls");
			cout << "Управление:" << endl;
			cout << "(+-)-Перемещение по оси Z" << endl;
			cout << "(Стрелка вверх/вниз)-Перемещение по оси Y" << endl;
			cout << "(Стрелка вправо/влево)-Перемещение по оси X" << endl;
			cout << "(Цифра 1/2)-Выбор перемещаемого объекта" << endl;
			cout << "Пробел-Инвертированный поворот" << endl;
			cout << "X,Y,Z-поворот по соответствующим осям" << endl;
			cout << "(crtl+стрелка влево)-Маштабирование со знаком -" << endl;
			cout << "(crtl+стрелка вправо)-Маштабирование со знаком +" << endl;
			_getch();
			system("cls");
			break;
		case 51:
			system("cls");
			cout << "Выход из программы" << endl;
			_getch();
			tr = 0;
			break;
		}
	}
	
}
void cur() {

	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, nullptr);

	int c;
	char flag = '+';
	BitMap bmp1(
		(int)DIM_BMP_ONE::width, 
		(int)DIM_BMP_ONE::height, 
		(int)DIM_BMP_ONE::left_margin, 
		(int)DIM_BMP_ONE::top_margin,
		(COLORREF)COL_BMP::clear
	);
	BitMap bmp2(
		(int)DIM_BMP_TWO::width,
		(int)DIM_BMP_TWO::height,
		(int)DIM_BMP_TWO::left_margin,
		(int)DIM_BMP_TWO::top_margin,
		(COLORREF)COL_BMP::clear
	);
	pyramid_4 b1(
		&bmp1, 
		(size_t)NUM_VER::pyr_4,
		(size_t)NUM_FACE::pyr_4
		);
	pyramid b2(
		&bmp2,
		(size_t)NUM_VER::pyr,
		(size_t)NUM_FACE::pyr
	);
	figure *ptr = &b1;
	bmp1.DrawBitmap();
	bmp2.DrawBitmap();
	while (q) {
		c = _getch();
		switch (c) {
		case 43://+
			ptr->move('z', '+');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 45://-
			ptr->move('z', '-');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 72://Стрелка вверх
			ptr->move('y', '-');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 77://Стрелка вправо
			ptr->move('x', '+');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 80://стрелка вниз
			ptr->move('y', '+');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 75://Стрелка влево
			ptr->move('x', '-');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 49://1
			ptr = &b1;
			break;
		case 50://2
			ptr = &b2;
			break;
		case 32:
			(flag == '+') ? flag = '-' : flag = '+';
			break;
		case 120://x поворт
			ptr->rotate('x', flag);
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 121://y поворот
			ptr->rotate('y', flag);
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 122://z поворот
			ptr->rotate('z', flag);
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 115://cntrl+стрелка влево
			ptr->zoom('-');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 116://cntrl+стрелка вправо
			ptr->zoom('+');
			b1.SetBitMap();
			b2.SetBitMap();
			bmp1.DrawBitmap();
			bmp2.DrawBitmap();
			break;
		case 27://esc
			q = 0;
			break;
		}
	}

}