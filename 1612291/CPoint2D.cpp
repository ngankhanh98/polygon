#include "stdafx.h"
#include "CPoint2D.h"
using namespace std;



CPoint2D::CPoint2D(float a, float b)
{
	mX = a;
	mY = b;
}

CPoint2D::CPoint2D()
{
	float x, y;
	cout << "(x;y):";
	cin >> x >> y;
	mX = x;
	mY = y;
}

//Khoảng cách 2 điểm
double CPoint2D::calcDistance(CPoint2D X)
{
	return sqrt((mX - X.mX)*(mX - X.mX) + (mY - X.mY)*(mY - X.mY));
}

//Chu vi tam giác từ 3 điểm
double CPoint2D::calcPerimeter(CPoint2D X, CPoint2D Y)
{
	
	double P = (*this).calcDistance(X) + (*this).calcDistance(Y) + X.calcDistance(Y);
	return P;
}

//Diện tích tam giác bằng herong
double CPoint2D::calcArea(CPoint2D X, CPoint2D Y)
{
	double p = (*this).calcPerimeter(X, Y)/2;	
	double a = (*this).calcDistance(X);
	double b = (*this).calcDistance(Y);
	double c = X.calcDistance(Y);
	return sqrt(p*(p-a)*(p-b)*(p-c));			
}

void CPoint2D::show()
{
	cout << "(" << mX << ";" << mY << ")";
}

float CPoint2D::x()
{
	return (*this).mX;
}

float CPoint2D::y()
{
	return (*this).mY;
}
