#include<iostream>
#include<string>
#include<cstdlib>
#include"TPolIZ.h"

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	string s;
	getline(cin, s);
	TPolIZ lol(s);
	lol.print_poliz();
	cout << '\n';
	cout << lol.get_tab() << '\n';
	cout << lol.poliz_count() << '\n';
	TPolIZ kek = lol;
	kek.print_poliz();
	cout << '\n';
	cout << kek.get_tab();
	return 0;
}