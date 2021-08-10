#include<iostream>
using namespace std;
bool check_integer(float n) {
	if (n == int(n)) return true;
	else return false;
}
long factorial(float n) {
	if (n == 0) return 1;
	return n * factorial(n - 1);
}
int main() {
	float n;
	re_input:
	cout << "input integer n: ";
	cin >> n;
	if (n < 0) {
		cout << "you entered n < 0; please enter integer 0 < n <= 20\n" << endl;
		goto re_input;
	}
	else if (!check_integer(n)) {
		cout << "you entered n not an integer; please enter integer 0 < n <= 20\n" << endl;
		goto re_input;
	}
	else if (n > 20) {
		cout << "you entered n over limit, please enter integer 0 < n <= 20\n" << endl;
		goto re_input;
	}
	else {
		cout << "you have entered n satisfying the requirements" << endl;
		cout << n << "! = " << factorial(n) << endl;
	}
	return 0;
}