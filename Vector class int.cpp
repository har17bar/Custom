#include <iostream>

using namespace std;

class Vector {
public:
	Vector() {
		_size = 0;
	};
	~Vector() {
		delete[] _arr;
		_arr = nullptr;
	}
	Vector(const Vector & src);
	void copyfrom(const Vector &src);
	Vector& operator=(const Vector &src);
	void push_back(const int elem);
	void insert_at(const int index, const int elem);
	int get_at(const int index);
	int get_size();
	void print();
private:
	int* _arr;
	int _size;
};

int main()
{
	{
		Vector obj2;
		obj2.push_back(17);
		obj2.push_back(19);
		obj2.push_back(8);
		obj2.insert_at(1, 41);
		obj2.insert_at(0, 6);
		Vector taza(obj2);
		taza.push_back(100);
		taza.push_back(110);
		taza.insert_at(1, 999);
		obj2.push_back(9999999);
		Vector obj4;
		obj4 = taza;
		obj4.push_back(123456789);
		cout << "obj4________" << endl;
		obj4.print();
		cout << "taza__________" << endl;
		taza.print();
	}
}
Vector& Vector::operator=(const Vector &src) {
	if (this->_arr == src._arr) {
		return *this;
	}
	copyfrom(src);
	return *this;
};
void Vector::copyfrom(const Vector &src) {
	this->_arr = new int[src._size];
	for (int i = 0; i < src._size; i++)
	{
		this->_arr[i] = src._arr[i];
	}
	this->_size = src._size;
}
Vector::Vector(const Vector & src) {
	copyfrom(src);
}

void Vector::push_back(const int elem) {
	int *tmp = new int[_size + 1];
	for (int i = 0; i<_size; i++) {
		tmp[i] = _arr[i];
	}
	tmp[_size] = elem;
	delete[] _arr;
	_size = _size + 1;
	_arr = tmp;
	tmp = nullptr;

}

void Vector::insert_at(const int index, int elem) {
	int *tmp = new int[_size + 1];
	for (int i = 0, j = 0; j <_size + 1; i++, j++) {
		if (j == index) {
			tmp[i] = elem;
			--i;
			continue;
		}
		tmp[j] = _arr[i];
	}
	delete[] _arr;
	_arr = tmp;
	_size++;
	tmp = nullptr;
}

int Vector::get_at(const int index) {
	return _arr[index];
}

int Vector::get_size() {
	return _size;
}

void Vector::print() {
	for (int i = 0; i < _size; ++i) {
		cout << _arr[i] << endl;
	}
}