// 1612291.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"CPoint2D.h"
#include"CPolygon.h"
using namespace std;


int main()
{
	int n;
	cout << "So luong diem cua da giac: ";
	CPolygon Polygon(n);					//khởi tạo polygon n điểm

	Polygon.show();							//in ra màn hình n điểm đa giác
	cout << endl;
	cout << "Chu vi da giac: " << Polygon.calcPerimeter() << endl;


#pragma region NângCao
	char k;
	do {
		cout << "\nBan muon tiep tuc?" << endl;
		cout << "1. Kiem tra da giac loi" << endl;
		cout << "2. Dien tich da giac" << endl;
		cout << "3. Kiem tra diem thuoc da giac" << endl;
		cout << "0. Thoat" << endl;


		do
		{
			cin >> k;
			if (k != '1'&&k != '2'&&k != '3'&&k != '0')
				cout << "Nhap sai, vui long nhap lai! ";
		} while (k != '1'&&k != '2'&&k != '3'&&k != '0');

		if (k == '1')
		{
			cout << "Da giac";
			{
				if (Polygon.isConvexPolygon())
					cout << " ";
				else cout << " khong ";
				cout << "la da giac loi";
			}
		}
	
		if (k == '2')
			cout << "Dien tich da giac: " << Polygon.calcArea() << endl;
		if (k == '3')
		{
			cout << "Diem can kiem tra ";
			CPoint2D Point;
			Point.show();
			cout << (Polygon.isPointInPolygon(Point) ? " " : " khong ") << "thuoc da giac" << endl;
		}
	} while (k != '0');
#pragma endregion

	return 0;
}

