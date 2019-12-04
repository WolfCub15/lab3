#include "Arithmetic.h"
#include<vector>
Arithmetic::Arithmetic(std::string kek) {
	str = kek;
	poliz = new TPolIZ(kek);
}

Arithmetic::Arithmetic(const Arithmetic & tmp) {
	str = tmp.str;
	poliz = tmp.poliz;
}

Arithmetic & Arithmetic::operator=(const Arithmetic & tmp) {
	if (&tmp == this) return *this;
	this->str = tmp.str;
	this->poliz = tmp.poliz;
	return *this;
}
#include<ostream>
#include<iterator>
#include<algorithm>
double Arithmetic::calc() {
	//for (int i = 0; i < poliz.get_tab()->get_count(); i++) {
	//	if (poliz.get_tab()->operator[](i).get_val() == 0) {
	//		cout << poliz.get_tab()->operator[](i).get_name() << " = ";
	//		double qwe;
	//		cin >> qwe;
	//		poliz.get_tab()->operator[](i).set_val(qwe);
	//	}
	//	//cout << poliz.get_tab()->operator[](i).get_name() << ' ' << poliz.get_tab()->operator[](i).get_value() << '\n';
	//}

	Stack<double> s(poliz->get_tab()->get_count()), out;

	double left, right;
	double res = 0;

	for (int i = 0; i < poliz->poliz_count(); i++) {
		int k = poliz->get_tab()->search_line(poliz->operator[](i));
		if (k != -1) {
			//cout << poliz.get_tabl_variable().operator[](k).get_value() << '\n';
			s.push(poliz->get_tab()->operator[](k).get_val());
			//cout << "I AM DONE\n";
		}
		else {
			right = s.pop();
			left = s.pop();
			//must make beautiful like Denis, but we making stupid realisation
			if (poliz->operator[](i) == "+") {
				s.push(left + right);
			}
			else if (poliz->operator[](i) == "-") {
				s.push(left - right);
			}
			else if (poliz->operator[](i) == "^") {
				s.push(pow(left, right));//can write binary pow for int degree
			}
			else if (poliz->operator[](i) == "*") {
				s.push(left * right);
			}
			else if (poliz->operator[](i) == "/") {
				s.push(left / right);
			}
		}
	}
	return s.pop();
}

TPolIZ* Arithmetic::get_poliz() {
	return poliz;
}
