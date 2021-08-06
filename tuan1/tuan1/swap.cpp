#include<iostream>
using namespace std;
void swap_tham_chieu(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void swap_con_tro(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main() {
	int a, b;
	cout << "Nhap vao so a: ";
	cin >> a;
	cout << "Nhap vao so b: ";
	cin >> b;
	cout << "Truoc khi hoan vi:" << endl;
	cout << "a = " << a << " ;b = " << b << endl;
	// chọn một trong 2 hàm swap để thực thi.
	swap_tham_chieu(a, b);
	//swap_con_tro(&a, &b);
	cout << "Sau khi hoan vi:" << endl;
	cout << "a = " << a << " ;b = " << b << endl;
	return 0;
}