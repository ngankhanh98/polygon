========================================================================
		LỚP BIỂU DIỄN ĐA GIÁC TRONG KHÔNG GIAN 2 CHIỀU
========================================================================

1. Thông tin cá nhân:

MSSV: ---------
Họ tên: -----------------------


2. Những file này giải quyết yêu cầu:

    Nhập đa giác, xuất ra đa giác. Cho biết chu vi của đa giác (giả định đa giác đã là đa giác lồi)

    Một phần nâng cao, cho phép người dùng lựa chọn tiếp tục:
	1. Kiểm tra đa giác lồi
	2. Tính diện tích đa giác
	3. Nhập vào một điểm, kiểm tra điểm đó thuộc đa giác hay không


3. Thiết kế lớp:

	CPoint2D:
	- mX, mY: float
	+ CPoint2D()											//khởi tạo 1 điểm
	+ calcDistance(X: CPoint2D): double						//tính khoảng cách của 2 điểm
	+ calcPerimeter(X: CPoint2D, Y: CPoint2D): double		//tính chu vi của 3 điểm
	+ calcArea(X: CPoint2D, Y: CPoint2D): double			//tính diện tích khu vực 3 điểm
	+ show(): void											//in ra màn hình tọa độ điểm

	CPolygon:
	+ CPolygon(index: int)									//khởi tạo [index] điểm của đa giác (điểm này có tọa độ xác định)
	+ ~CPolygon()											//hủy 
	+ show(): void											//in ra màn hình tọa độ các điểm của đa giác
	+ calcPerimeter(): double								//tính chu vi đa giác
	+ calcArea(): double									//tính diện tích đa giác
	+ isConvexPolygon(): bool								//kiểm tra đa giác lồi hay không
	+ isPointInPolygon(X: CPoint): bool;					//kiểm tra điểm X có thuộc đa giác 


/////////////////////////////////////////////////////////////////////////////

Những file hệ thống khác được tạo do bỏ chọn Empty project

/////////////////////////////////////////////////////////////////////////////

