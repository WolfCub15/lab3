#include<iostream>
#include<string>
#include<cstdlib>
#include"TPolIZ.h"
#include"Arithmetic.h"

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	string s = "a + b + 123";
	Arithmetic lol(s);
	//lol.get_poliz().print_poliz();
	for (int i = 0; i < lol.get_poliz()->get_tab()->get_count(); i++) {
		cout << lol.get_poliz()->get_tab()->operator[](i).get_name() << " = ";
		double kek;
		cin >> kek;
		lol.get_poliz()->get_tab()->operator[](i).set_val(kek);
	}
	cout << lol.calc();
	return 0;
}