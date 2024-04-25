#include "functions.h"

int main() {
    int N = 20;
    vector<Complex> time_conv1(N);
    vector<Complex> time_fconv1(N);
    vector<Complex> time_conv2(N);
    vector<Complex> time_fconv2(N);
    vector<Complex> a;
    vector<Complex> b;
    vector<Complex> c1;
    a.resize(256, 1);

    for (int i = 0; i < N; i++) {
        b.resize(pow(2, i), 1);

        auto start = chrono::steady_clock::now();
        c1 = CONV(a, b);
        auto end = chrono::steady_clock::now();
        time_conv1[i] = Complex(i, chrono::duration<double, nano>(end - start).count());

        start = chrono::steady_clock::now();
        c1 = FCONV(a, b);
        end = chrono::steady_clock::now();
        time_fconv1[i] = Complex(i, chrono::duration<double, nano>(end - start).count());
    }

    for (int i = 0; i < N; i++) {
        a.resize(pow(2, i), 1);
        b.resize(pow(2, i), 1);

        auto start = chrono::steady_clock::now();
        c1 = CONV(a, b);
        auto end = chrono::steady_clock::now();
        time_conv2[i] = Complex(i, chrono::duration<double, nano>(end - start).count());

        start = chrono::steady_clock::now();
        c1 = FCONV(a, b);
        end = chrono::steady_clock::now();
        time_fconv2[i] = Complex(i, chrono::duration<double, nano>(end - start).count());
    }

    write(time_conv1, "time_conv1");
    write(time_conv2, "time_conv2");
    write(time_fconv1, "time_fconv1");
    write(time_fconv2, "time_fconv2");

}