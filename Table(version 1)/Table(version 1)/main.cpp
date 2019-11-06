#include<iostream>
#include<string>
#include"Line.h"
#include"Table.h"

using namespace std;

int main() {
	Table<int> a(10);
	for (int i = 0; i < a.get_size(); i++) {
		cout << a[i].get_name() << ' ' << a[i].get_val() << '\n';
	}
	string kek = "d";
	for (int i = 0; i < 10; i++) {
		a.push_back(Line<int>( kek, i + 1 ));
		cout << a.get_count() << ' ' << a.get_size() << '\n';
		kek += 'a' + i;
	}
	for (int i = 0; i < a.get_size(); i++) {
		cout << a[i].get_name() << ' ' << a[i].get_val() << '\n';
	}
	a.erase("da");
	a.erase("d");

	cout << a.get_count() << ' ' << a.get_size() << '\n';
	for (int i = 0; i < a.get_size(); i++) {
		cout << a[i].get_name() << ' ' << a[i].get_val() << '\n';
	}
	cout << a.search("dab") << '\n';
	a.push_back(Line<int>("denis", 200));
	cout << a.get_count() << ' ' << a.get_size() << '\n';
	for (int i = 0; i < a.get_size(); i++) {
		cout << a[i].get_name() << ' ' << a[i].get_val() << '\n';
	}
	cout << a.get_count() << ' ' << a.get_size() << '\n';
	return 0;
}