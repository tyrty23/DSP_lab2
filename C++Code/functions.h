#include <vector>
#include <iostream>
#include <complex>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <chrono>
#define PI 3.14159265
using namespace std;
using namespace std::complex_literals;
typedef complex<double> Complex;
const std::complex<double> i(0.0, 1.0);

vector<Complex> read(string);
void write(vector<Complex>,string);
void DFT(vector<Complex> &, bool);
void FFT(vector<Complex> &, bool);
vector<Complex> CONV(vector<Complex>, vector<Complex>);
vector<Complex> FCONV(vector<Complex>, vector<Complex>);
double error(vector<Complex>,vector<Complex>);