#include "functions.h"

int main() {
	vector<Complex> conv;
	vector<Complex> fconv;
	vector<Complex> a(16);
	std::vector<Complex> b(16);
	a=read("ex7_1.txt");
	b=read("ex7_2.txt");

	conv = CONV(a, b);

    write(conv,"CppCONV");
	fconv = FCONV(a, b);
    write(fconv,"CppFCONV");
}

