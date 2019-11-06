#pragma once
#include"Line.h"

using namespace std;

template<class T>
class Table {
private:
	Line<T> *mem;
	int size;
	int cnt;
public:
	Table<T>(int _size = 0);
	~Table<T>();
	Table<T>(const Table<T> & tmp);
	Table<T> &operator=(const Table<T> & tmp);
	void push_back(Line<T> tmp);
	void erase(const string & name);
	T search(const string & name);
	int search_line(const string & name);
	Line<T> &operator[](const int k);
	bool empty();
	bool full();
	int get_count() {
		return this->cnt;
	}
	int get_size() {
		return this->size;
	}
	friend ostream &operator<<(ostream & out, Table<T> tmp) {
		for (int i = 0; i < tmp.cnt; i++) {
			out << "[ " << tmp[i].get_name() << ' ' << tmp[i].get_val() << " ]\n";
		}
		return out;
	}
};

template<class T>
inline Table<T>::Table(int _size) {
	size = _size;
	mem = new Line<T>[size];
	for (int i = 0; i < size; i++) {
		mem[i] = Line<T>();
	}
	cnt = 0;
}

template<class T>
inline Table<T>::~Table() {
	delete[] mem;
}

template<class T>
inline Table<T>::Table(const Table<T>& tmp) {
	size = tmp.size;
	mem = new Line<T>[size];
	cnt = tmp.cnt;
	for (int i = 0; i < size; i++) {
		mem[i] = tmp.mem[i];
	}
}

template<class T>
inline Table<T>& Table<T>::operator=(const Table<T>& tmp) {
	if (this == &tmp) return *this;
	if (size != tmp.size) {
		if (size) {
			delete[] mem;
		}
		size = tmp.size;
	}
	cnt = tmp.cnt;
	mem = new Line<T>[size];
	for (int i = 0; i < size; i++) {
		mem[i] = tmp.mem[i];
	}
	return *this;
}

template<class T>
inline void Table<T>::push_back(Line<T> tmp) {
	string fi = tmp.get_name();
	int pos = search_line(fi);
	if (pos == -1) {
		if (cnt == size) throw 1;
		mem[cnt++] = tmp;
	}
	else {
		mem[pos] = tmp;
	}
}

template<class T>
inline void Table<T>::erase(const string & name) {
	int pos = search_line(name);
	if (pos == -1) throw 1;
	mem[pos] = mem[--cnt];
}

template<class T>
inline T Table<T>::search(const string & name) {
	int pos = search_line(name);
	if (pos == -1) throw - 1;
	return mem[pos].get_val();
}

template<class T>
inline int Table<T>::search_line(const string & name) {
	int pos = -1;
	int i = 0;
	while (i < cnt && pos == -1) {
		if (name == mem[i].get_name()) pos = i;
		++i;
	}
	return pos;
}

template<class T>
inline Line<T>& Table<T>::operator[](const int k) {
	if (k < 0 || k >= size) throw 1;
	return mem[k];
}

template<class T>
inline bool Table<T>::empty() {
	return cnt == 0;
}

template<class T>
inline bool Table<T>::full() {
	return cnt == size;
}
