#include<iostream>
#include<string>
#include"TPolIZ.h"

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	string s;
	getline(cin, s);
	TPolIZ lol(s);
	lol.print_poliz();

	return 0;
}