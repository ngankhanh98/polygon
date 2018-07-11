#pragma once
#include<cmath>
#include<iostream>

class CPoint2D
{
	float mX;
	float mY;

public:
	CPoint2D(float a, float b);
	CPoint2D();

	double calcDistance(CPoint2D X);					//Khoảng cách 2 điểm
	double calcPerimeter(CPoint2D X, CPoint2D Y);		//Chu vi tam giác từ 3 điểm
	double calcArea(CPoint2D X, CPoint2D Y);			//Diện tích tam giác
	void show();
	float x();
	float y();
};

