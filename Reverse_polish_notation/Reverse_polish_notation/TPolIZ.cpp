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
	tab->push_back(Line<double>(p));
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
	get_words_diff_razdel(tmp, zn, lex, cnt_lex);
	//cnt_lex--;
	for (int i = 0; i < cnt_lex;i++) {
		if (lex[i].size() == 1 && lex[i] == "(") {
			left_bracket();
		}
		else if (lex[i].size() == 1 && lex[i] == ")") {
			right_bracket();
		}
		else if (lex[i].size() == 1 && (lex[i] == "+" || lex[i] == "-" || lex[i] == "*" || lex[i] == "/" || lex[i] == "^")) {
			operation(Line<int>(lex[i], priority->search(lex[i])));
		}
		else {
			operand(lex[i]);
		}
	}
	end_of_string();
}

TPolIZ::TPolIZ(string s) {
	make_priority();
	if (s.back() != ' ') s.push_back(' ');
	size_lex = size_poliz = (int)s.size() + 1;
	stack_prior = Stack<Line<int> >(size_lex);
	lex = new string[size_lex];
	cnt_lex = 0;
	poliz = new string[size_poliz];
	cnt_poliz = 0;
	tab = new Table<double>(100);
	make_poliz(s);
}

TPolIZ::TPolIZ(const TPolIZ & tmp) {
	lex = new string[tmp.size_lex];
	size_lex = tmp.size_lex;
	cnt_lex = tmp.cnt_lex;
	for (int i = 0; i < size_lex; i++) {
		lex[i] = tmp.lex[i];
	}
	poliz = new string[tmp.size_poliz];
	size_poliz = tmp.size_poliz;
	cnt_poliz = tmp.cnt_poliz;
	for (int i = 0; i < size_poliz; i++) {
		poliz[i] = tmp.poliz[i];
	}
	tab = tmp.tab;
	priority = tmp.priority;
	stack_prior = tmp.stack_prior;
}

TPolIZ & TPolIZ::operator=(const TPolIZ & tmp) {
	if (this == &tmp) return *this;
	if (size_lex != tmp.size_lex) {
		if (size_lex) delete[] lex;
		size_lex = tmp.size_lex;
		lex = new string[size_lex];
	}
	cnt_lex = tmp.cnt_lex;
	for (int i = 0; i < size_lex; i++) {
		lex[i] = tmp.lex[i];
	}
	if (size_poliz != tmp.size_poliz) {
		if (size_poliz) delete[] poliz;
		size_poliz = tmp.size_poliz;
		poliz = new string[size_poliz];
	}
	cnt_poliz = tmp.cnt_poliz;
	tab = tmp.tab;
	priority = tmp.priority;
	stack_prior = tmp.stack_prior;
	return *this;
}

TPolIZ::~TPolIZ() {
	delete[] poliz;
	delete[] lex;
	delete tab;
	delete priority;
}
