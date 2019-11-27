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
	lol.get_poliz().print_poliz();
	cout << lol.calc();
	return 0;
}