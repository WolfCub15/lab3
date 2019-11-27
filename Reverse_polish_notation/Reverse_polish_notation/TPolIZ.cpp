#include"TPolIZ.h"

void get_words_diff_razdel(string st, string zn, string *w, int &k) {
	for (int i = 0; i < st.size(); i++) {
		
		int gg = (int)zn.find(st[i]);
		if (gg < 0 || gg >= zn.size()) {
			w[k].push_back(st[i]);
		}
		else {
			if (w[k].size()) {
				k++;
			}
			if (st[i] != ' ') w[k++] = st[i];
		}
	}
}

void TPolIZ::make_priority() {
	priority = new Table<int>(5);
	priority->push_back(Line<int>("+", 1));
	priority->push_back(Line<int>("-", 1));
	priority->push_back(Line<int>("*", 2));
	priority->push_back(Line<int>("/", 2));
	priority->push_back(Line<int>("^", 3));
}

void TPolIZ::left_bracket() {
	stack_prior.push(Line<int>("(", 0));
}

void TPolIZ::right_bracket() {
	while (!stack_prior.empty() && stack_prior.front().get_name() != "(") {
		poliz[cnt_poliz++] = stack_prior.pop().get_name();
	}
	stack_prior.pop();
}

void TPolIZ::operand(const string & p) {
	if (p[0] >= '0' && p[0] <= '9') {//number
		double number = stod(p.c_str());
		tab->push_back(Line<double>(p, number));
	}
	else { //not a number
		tab->push_back(Line<double>(p));
	}
	poliz[cnt_poliz++] = p;
}

void TPolIZ::operation(const Line<int> &tmp) {
	while (!stack_prior.empty() && stack_prior.front().get_val() >= tmp.get_val()) {
		poliz[cnt_poliz++] = stack_prior.pop().get_name();
	}
	stack_prior.push(tmp);
}

void TPolIZ::end_of_string() {
	while (!stack_prior.empty()) {
		poliz[cnt_poliz++] = stack_prior.pop().get_name();
	}
}

void TPolIZ::make_poliz(const string & tmp) {
	string zn = "()+-*/^ ";
	string * lex = new string[tmp.size() + 1];
	int cnt_lex = 0;
	int size_lex = (int)tmp.size() + 1;
	get_words_diff_razdel(tmp, zn, lex, cnt_lex);
	for (int i = 0; i < cnt_lex;i++) {
		if (lex[i].size() == 1 && lex[i] == "(") {
			left_bracket();
		}
		else if (lex[i].size() == 1 && lex[i] == ")") {
			right_bracket();
		}
		else {
			int l = priority->search_line(lex[i]);
			if (l != -1) {
				operation(Line<int>(lex[i], priority->operator[](l).get_val()));
			}
			else {
				operand(lex[i]);
			}
		}
	}
	end_of_string();
}

TPolIZ::TPolIZ(string s) {
	make_priority();
	if (s.size() && s.back() != ' ') s.push_back(' ');
	size_poliz = (int)s.size() + 1;
	stack_prior = Stack<Line<int> >(size_poliz);
	poliz = new string[size_poliz];
	cnt_poliz = 0;
	tab = new Table<double>(size_poliz / 2);
	make_poliz(s);
}

TPolIZ::TPolIZ(const TPolIZ & tmp) {
	poliz = new string[tmp.size_poliz];
	size_poliz = tmp.size_poliz;
	cnt_poliz = tmp.cnt_poliz;
	for (int i = 0; i < size_poliz; i++) {
		poliz[i] = tmp.poliz[i];
	}
	tab = new Table<double>(size_poliz / 2);
	*tab = *tmp.tab;
	make_priority();
	stack_prior = tmp.stack_prior;
}

TPolIZ & TPolIZ::operator=(const TPolIZ & tmp) {
	if (this == &tmp) return *this;
	if (size_poliz != tmp.size_poliz) {
		if (size_poliz) delete[] poliz;
		size_poliz = tmp.size_poliz;
		poliz = new string[size_poliz];
	}
	cnt_poliz = tmp.cnt_poliz;
	for (int i = 0; i < size_poliz; i++) {
		poliz[i] = tmp.poliz[i];
	}
	make_priority();
	delete tab;
	tab = new Table<double>(size_poliz / 2);
	*tab = *tmp.tab;
	stack_prior = tmp.stack_prior;
	return *this;
}

string TPolIZ::operator[](const int k) const {
	if (k >= 0 && k < cnt_poliz) return poliz[k];
	throw 1;
}

TPolIZ::~TPolIZ() {
	delete[] poliz;
	delete tab;
	delete priority;
}
