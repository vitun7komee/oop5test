#include "Choice.h"

Choice::Choice(size_t s) : Container(s) {}
Choice::Choice(size_t s, double* a) : Container(s, a) {}
Choice::Choice(Choice& ch) : Container(ch) {}
Choice::~Choice() {}
void Choice::sort() {

	for (int startIndex = 0; startIndex < size - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
		{
			if (arr[currentIndex] < arr[smallestIndex])
				smallestIndex = currentIndex;
		}
		std::swap(arr[startIndex], arr[smallestIndex]);
	}
}
Choice& Choice::operator=(Choice& c) {
	if (&c != this)
	{
		size = c.size;
		for (size_t i = 0; i < size; i++) {
			arr[i] = c.arr[i];
		}
	}
	else
		return *this;
}
double* Choice::foreach() {
	double* arr1 = new double[size];
	for (size_t i = 0; i < size; i++) {
		if (arr[i] > 0) {
			arr1[i] = log(arr[i]);
		}
		else { arr1[i] = log(abs(arr[i])); }
	}
	return arr1;
}
void Choice::randomfill() {
	Container::randomfill();
}
std::istream& operator>>(std::istream& in, Choice& c) {
	std::cout << "array elements :\n";
	for (size_t i = 0; i < c.size; i++) {
		in >> c.arr[i];
		std::cin.ignore();
	}
	return in;
}
std::ostream& operator<<(std::ostream& out, Choice& c) {
	out << "ARR \n ";
	for (size_t i = 0; i < c.size; i++) {
		out  << c.arr[i] << "  ";
	}
	return out;
}