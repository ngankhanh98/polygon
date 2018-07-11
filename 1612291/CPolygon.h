#pragma once
#include"CPoint2D.h"

class CPolygon
{

	CPoint2D *mpPoint;
	int mCurrentSize;

public:
	CPolygon(int &index);			//khởi tạo[index] điểm của đa giác
	~CPolygon();					//hủy	

	void show();						//in ra màn hình mảng điểm của đa giác
	double calcPerimeter();				//tính chu vi đa giác	
	double calcArea();					//tính diện tích đa giác
	bool isConvexPolygon();				//kiểm tra đa giác lồi
	bool isPointInPolygon(CPoint2D X);	//kiểm tra điểm X thuộc đa giác
};

