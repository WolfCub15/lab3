#pragma once
template<class T>
class Stack {
private:
	int size;
	int last;
	T *mem;
public:
	Stack<T>(int _size = 0);
	Stack<T>(const Stack<T> & tmp);
	Stack<T> &operator=(const Stack<T> & tmp);
	void push(const T & k);
	T pop();
	T front();
	bool empty();
	bool full();
};

template<class T>
inline Stack<T>::Stack(int _size) {
	if (_size < 0) throw 1;
	size = _size;
	last = 0;
	mem = new T[size];
	for (int i = 0; i < size; i++) mem[i] = T();
}

template<class T>
inline Stack<T>::Stack(const Stack<T>& tmp) {
	size = tmp.size;
	last = tmp.last;
	mem = new T[size];
	for (int i = 0; i < size; i++) {
		mem[i] = tmp.mem[i];
	}
}

template<class T>
inline Stack<T>& Stack<T>::operator=(const Stack<T>& tmp) {
	if (this == &tmp) return *this;
	if (size != tmp.size) {
		if (size) {
			delete[] mem;
		}
		size = tmp.size;
		mem = new T[size];
	}
	last = tmp.last;
	for (int i = 0; i < size; i++) {
		mem[i] = tmp.mem[i];
	}
	return *this;
}

template<class T>
inline void Stack<T>::push(const T & k) {
	if (last == size) throw 1;
	this->mem[last++] = k;
}

template<class T>
inline T Stack<T>::pop() {
	if (last == 0) throw 1;
	return this->mem[--last];
}

template<class T>
inline T Stack<T>::front() {
	if (last == 0) throw 1;
	return this->mem[last - 1];
}

template<class T>
inline bool Stack<T>::empty() {
	return last == 0;
}

template<class T>
inline bool Stack<T>::full() {
	return last == size;
}
