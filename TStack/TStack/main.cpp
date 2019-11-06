#include<iostream>
#include"Stack.h"

using namespace std;

int main() {
	int n;
	cin >> n;
	Stack<int> a(n);
	for (int i = 0; !a.full(); i++) {
		a.push(i + 1);
	}
	cout << a.front() << '\n';
	cout << (a.full() ? "FULL\n" : "NOT FULL\n");
	while (!a.empty()) {
		cout << a.pop() << ' ';
	}
	cout << (a.empty() ? "EMPTY\n" : "EMPTY\n");
	return 0;
}