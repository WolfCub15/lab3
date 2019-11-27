#pragma once
#include<iostream>
#include<string>
#include"Stack.h"
#include"Table.h"

using namespace std;

class TPolIZ {
private:
	string *poliz;
	int size_poliz;
	int cnt_poliz;
	Table<double> *tab;
	Table<int> *priority;
	Stack<Line<int> > stack_prior;
	void make_priority();
	void left_bracket();
	void right_bracket();
	void operand(const string & p);
	void operation(const Line<int> &tmp);
	void end_of_string();
	void make_poliz(const string & tmp);
public:
	TPolIZ(string s = "");
	TPolIZ(const TPolIZ & tmp);
	TPolIZ &operator=(const TPolIZ & tmp);
	int poliz_count()const {
		return this->cnt_poliz;
	}
	string operator[] (const int k)const;
	void print_poliz() {
		for (int i = 0; i < cnt_poliz; i++) {
			cout << poliz[i] << ' ';
		}
	}
	Table<double>* get_tab() {
		return tab;
	}
	~TPolIZ();
};

