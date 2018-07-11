#include "stdafx.h"
#include "CPolygon.h"
using namespace std;

CPolygon::CPolygon(int &index)
{
	cin >> index;

	mpPoint = new CPoint2D[index];		//khởi tạo mảng gồm index đối tượng
										//mỗi đối tượng khởi tạo bởi constructor CPoint2D
	mCurrentSize = index;
}

CPolygon::~CPolygon()
{
	if (mpPoint != NULL)
		delete[]mpPoint;
}

void CPolygon::show()
{
	for (int i = 0; i < mCurrentSize; i++)
	{
		mpPoint[i].show();
		cout << "\t";
	}
}

double CPolygon::calcPerimeter()
{
	int i;
	double P = 0;
	//tính tổng các cạnh 
	for (i = 0; i < mCurrentSize - 1; i++)
		P += mpPoint[i].calcDistance(mpPoint[i + 1]);

	//tính cạnh cuối cùng (nối điểm cuối với điểm đầu)
	P += mpPoint[i].calcDistance(mpPoint[0]);

	return P;
}

double CPolygon::calcArea()
{
	double S = 0;
	//tính tổng diện tích tam giác được tạo bởi 3 điểm, lấy điểm đầu làm gốc
	for (int i = 1; i < mCurrentSize - 1; i++)
		S += mpPoint[0].calcArea(mpPoint[i], mpPoint[i + 1]);

	return S;
}

bool CPolygon::isConvexPolygon()
{
	//Viết phương trình đường thẳng
	//Kiểm tra lần lượt cùng hay khác phía

	CPoint2D x(0,0);					
	float a, b;							//hệ số đường thẳng: y=ax+b
	for (int i = 0; i < mCurrentSize; i++)
	{
		//Tìm phương trình đường thẳng của từng cặp điểm (thứ i và i+1)
		a = (float)(mpPoint[i].y() - mpPoint[i + 1].y()) / (mpPoint[i].x() - mpPoint[i + 1].x());
		b = mpPoint[i].y() - a*mpPoint[i].x();
		
		
		CPoint2D x0 = mpPoint[i + 2];
		//Bắt đầu xét cùng hay khác phía từng cặp (i+2,i+3), (i+2, i+4)...
		//Lặp (mCurrentSize-3) lần do trừ 3 điểm: 2 điểm tạo đường thẳng và 1 điểm gốc 
		for (int j = 0; j < mCurrentSize - 3; j++)
		{
			x = (i + 3 + j < mCurrentSize) ? mpPoint[i + 3 + j] : mpPoint[i + 3 + j - mCurrentSize];		//khi i+3+j>mCurrentSize ~ điểm đạt tới điểm cuối mảng, phải trừ mCurrentSize để quay lại điểm đầu
			if ((a*x0.x() - x0.y() + b)*(a*x.x() - x.y() + b) < 0)											//tồn tại 1 cặp ngược phía
				return false;																				//---> kết luận đa giác không lồi
		}
	}
	return true;
}

bool CPolygon::isPointInPolygon(CPoint2D X)
{
	//tính tổng diện tích của các tam giác tạo bởi điểm X và lần lượt 2 điểm của đa giác
	double p = X.calcArea(mpPoint[0], mpPoint[mCurrentSize - 1]);	//diện tích tam giác của X, điểm đầu đa giác, điểm cuối đa giác
	for (int i = 0; i < mCurrentSize - 1; i++)						//diện tích các tam giác còn lại		
		p += X.calcArea(mpPoint[i], mpPoint[i + 1]);

	//tính diện tích đa giác
	double P = (*this).calcArea();

	
	if (p==P)			//nếu tổng diện tích của các tam giác tạo bởi điểm X == diện tích đa giác
		return true;	//--->X thuộc đa giác
	return false;
}

