#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <ctime>


class Container {
protected:
	double* arr;
	size_t size;
public:
	Container();
	Container(size_t s);
	Container(size_t s, double* a);
	Container(Container& ch);

	virtual void sort() = 0;
	virtual double* foreach() = 0;
	virtual void randomfill();
	virtual Container& operator=(Container& c);
	double* getarr();
	size_t getsize();
	void print() {
		for (size_t i = 0; i < size; i++) {
			std::cout << arr[i] << "  ";
		}
	}
	virtual ~Container(){
		delete[] arr;
		arr = nullptr;
		size = 0;
	}

	friend std::ostream& operator<<(std::ostream& out, Container& c);
};
