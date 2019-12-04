#pragma once
#include<iostream>
#include<string>
#include"Stack.h"
#include"Table.h"

class TPolIZ {
private:
	std::string *poliz;
	int size_poliz;
	int cnt_poliz;
	Table<double> *tab;
	Table<int> *priority;
	Stack<Line<int> > stack_prior;
	void make_priority();
	void left_bracket();
	void right_bracket();
	void operand(const std::string & p);
	void operation(const Line<int> &tmp);
	void end_of_string();
	void make_poliz(const std::string & tmp);
public:
	TPolIZ(std::string s = "");
	TPolIZ(const TPolIZ & tmp);
	TPolIZ &operator=(const TPolIZ & tmp);
	int poliz_count()const {
		return this->cnt_poliz;
	}
	std::string operator[] (const int k)const;
	std::string print_poliz() {
		std::string res;
		for (int i = 0; i < cnt_poliz; i++) {
			res += poliz[i] + ' ';
		}
		if (res.size()) res.pop_back();
		return res;
	}
	Table<double>* get_tab() {
		return tab;
	}
	~TPolIZ();
};

