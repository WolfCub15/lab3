#pragma once
#include<string>

template<class T>
class Line {
private:
	std::string name;
	T val;
public:
	Line<T>() {
		name = "";
		val = T(0);
	}
	Line<T>(std::string _name, T _val = 0);
	Line<T>(const Line<T> & tmp);
	std::string get_name() const {
		return this->name;
	}
	T get_val() const {
		return this->val;
	}
	void set_val(const T & tmp) {
		this->val = tmp;
	}
	Line<T> &operator=(const Line<T> & tmp);
};

template<class T>
inline Line<T>::Line(std::string _name, T _val) {
	name = _name;
	val = _val;
}

template<class T>
inline Line<T>::Line(const Line<T>& tmp) {
	name = tmp.name;
	val = tmp.val;
}

template<class T>
inline Line<T>& Line<T>::operator=(const Line<T>& tmp) {
	if (this == &tmp) return *this;
	name = tmp.name;
	val = tmp.val;
	return *this;
}
