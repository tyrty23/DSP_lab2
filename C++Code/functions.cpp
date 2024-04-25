#include "functions.h"

vector<Complex> read(string filename) {
    vector<Complex> y;
    filename ="..\\TextFiles\\"+filename;
    std::ifstream in(filename); 
    if (in.is_open()){
        double a, b;
        while (in >> a >> b)
            y.push_back((a + b * i));
    }
    else{cout<<"Error while reading"<<endl;}
    in.close();
    return y;
}

void write(vector<Complex> x,string filename){
    ofstream out;
    string name="..\\TextFiles\\"+filename+".txt";
	out.open(name);
	if (out.is_open()) {
		for (int i = 0; i < x.size(); i++)
			out << setprecision(20) << x[i].real() << " " << setprecision(20) << x[i].imag() << endl;
	}
	else {cout<<"Error while writing"<<endl;}
	out.close();
}

void DFT(vector<Complex> &x,bool reverse) {
    int N = x.size();
    double s = 1.0 / sqrt(N);
    int rev = reverse ? -1 : 1;
    vector<Complex> y(x);
    Complex sum1;
    for (int k = 0; k < N; k++) {
        double support1 =  - 2 * PI / N * k*rev;
        sum1 = 0;
        for (int j = 0; j < N; j++) {
            sum1 += y[j] * exp(j * support1 * i);
        }
        x[k] = s * sum1;
    }
}

void FFT(vector<Complex> &x, bool reverse) {
    int N = x.size();
    int n = log2(N);
    if (reverse) {
        for (auto iter = x.begin(); iter < x.end(); iter++)
            *iter = conj(*iter);
    }

    vector<Complex> y = x;
    for (int k = 1; k < n + 1; k++) {
        vector<Complex> x = y;
        for (int j = 0; j < pow(2, n - k); j++) {
            Complex omega = exp(-2* PI / pow(2, n-k+1) * j * i);
            for (int l = 0; l < (pow(2, k - 1)); l++) {
                Complex x1 = x[j * pow(2, k - 1) + l];
                Complex x2 = x[j * pow(2, k - 1) + l + pow(2, n - 1)];
                y[j * pow(2, k) + l] = x1 + x2;
                y[j * pow(2, k) + l + pow(2, k - 1)] = (x1 - x2) * omega;
            }
        }
    }
    double s = 1 / sqrt(N);
    for (auto iter = y.begin(); iter < y.end(); iter++)
        *iter *= s;
    if (reverse) {
        for (auto iter = y.begin(); iter < y.end(); iter++)
            *iter = conj(*iter);
    }
    x=y;
}

vector<Complex> CONV(vector<Complex> x, vector<Complex> y) {
    if (x.size() > y.size()) x.swap(y);
    int M = x.size();
    int L = y.size();
    int N = M + L;
    vector<Complex> c(N);
    Complex sum;

    for (int n = 0; n < N; n++) {
        sum = 0;
        for (int k = 0; k < M; k++) {
            if (n-k>=L||k>n) {
                continue;
            }
            else{ sum += x[k] * y[n - k]; }
        }
        c[n] = sum;
    }
    return c;
}

vector<Complex> FCONV(vector<Complex> x, vector<Complex> y) {
    Complex zero = (0, 0);
    int M = x.size();
    int L = y.size();
    int N2 = M > L ? 2 * M : 2 * L;
    int N = pow(2, ceil(log2(N2)));

    vector<Complex> c(N);
    x.resize(N , zero);
    y.resize(N, zero);
    FFT(x,0);
    FFT(y, 0);
    double s = sqrt(N);
    for (int i = 0; i <  N; i++) {
        c[i] = s * x[i] * y[i];
    }
    FFT(c, 1);
    return c;
}

double error(vector<Complex> x,vector<Complex> y){
    double err=0;
    for(int i=0;i<x.size();i++)
        err+=abs(pow(x[i]-y[i],2));
    return err;
}