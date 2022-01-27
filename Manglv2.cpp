// LÝ THUYẾT
/*
C1: Mảng không thêm được khi nào?
-Mảng không thêm được khi số lượng phần tử trong mảng đã đạt đến giới hạn.
//
C2:  Mảng không xóa được khi nào?
-Mảng không xóa được khi số lượng phần tử trong mảng nhỏ hơn 1.
//
C3 : Trình bày lần lượt hướng duyệt của thuật toán thêm, thuật toán xóa.
-Thuật toán thêm: hướng duyệt là tịnh tiến từ phải sang trái.
-Thuật toán xóa: hướng duyệt là tịnh tiến từ trái sang phải.
//
C4: Trình bày code thuật toán thêm - thuật toán xóa(chọn 1 trong 2 cách).
-Thuật toán thêm:
void them_pt(int a[], int& n, int k, int x) {
	for (int i = n - 1; i >= k; i--) {
		a[i + 1] = a[i];
	}
	a[k] = x;
	n++;
}

-Thuật toán xóa:
void xoa_pt(int a[], int& n, int k) {

	for (int i = k; i < n; i++) {
		a[i] = a[i + 1];
	}
	n--;
}

*/
// BÀI TẬP 
#include <iostream>
using namespace std;
#define max 100

void nhap_mang(int a[], int n);
void xuat_mang(int a[], int n);
void them_pt(int a[], int& n, int k, int x);
void xoa_pt(int a[], int& n, int k);
int dao_nguoc(int n);
void bai1(int a[], int n);
void bai2(int a[], int n);
void bai3(int a[], int n);
void bai4(int a[], int n);

int main()
{

	int a[max], n;
	do {
		cout << "Nhap n : ";
		cin >> n; cout << endl;
		if (n <= 0 || n > 100) {
			cout << "Vui long nhap lai n.\n";
			system("pause");
		}
	} while (n <= 0 || n > 100);

	nhap_mang(a, n);
	return 0;
	//bai1(a, n);
	//bai2(a, n);
	//bai3(a, n);
	//bai4(a, n);

}

void bai1 (int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (dao_nguoc(a[i]) == a[i])
		{
			xoa_pt(a, n, i);
		}
	}
	xuat_mang(a, n);
}

	void bai2(int a[], int n)
	{
		int count = 0;
		int count2 = 0;
		for (int i = n - 1; i > 0; i--) 
		{  
			for (int j = 1; j < a[i]; j++) 
			{   
				if (a[i] % j == 0) 
				{
					count += j;
				}
			}
				if (count == a[i] && a[i] != 0)
				{
					them_pt(a, n, i,0);
				}
				count = 0;
		}

		
		for (int j = 1; j < a[0]; j++)
		{
			if (a[0] % j == 0) 
			{
				count += j;
			}
		}
		if (count == a[0] && a[0] != 0) 
		{
			them_pt(a, n,0, 0);
		}
		xuat_mang(a, n);
	}

	void bai3(int a[], int n)
	{
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i] == a[j]) {
					xoa_pt(a, n, j);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i] == a[j]) {
					xoa_pt(a, n, j);
				}
			}
		}
		xuat_mang(a, n);
	}

	void bai4(int a[], int n)
	{
		int dem = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1; j > i; j--)
			{
				if (a[i] == a[j])
				{
					dem++;
					xoa_pt(a, n, j);
				}
			}
			cout << a[i] << "   " << dem << endl;
			dem = 1;
		}
	}



void nhap_mang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Nhap gia tri thu " << i << " : ";
		cin >> a[i];
	}
	cout << endl;
}

void xuat_mang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void them_pt(int a[], int& n, int k, int x) {
	for (int i = n - 1; i >= k; i--) {
		a[i + 1] = a[i];
	}
	a[k] = x;
	n++;
}

void xoa_pt(int a[], int& n, int k) {

	for (int i = k; i < n; i++) {
		a[i] = a[i + 1];
	}
	n--;
}

int dao_nguoc(int n) {
	int nguoc = 0;
	while (n > 0) {
		nguoc = nguoc * 10 + n % 10;
		n /= 10;
	}
	return nguoc;
}