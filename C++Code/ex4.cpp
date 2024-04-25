#include "functions.h"

int main() {
    int N=10;
	vector<Complex> time_dft(N);
	vector<Complex> time_fft(N);
	vector<Complex> dft;
	vector<Complex> fft;

	for (int k = 0; k < N; k++) {
		dft.resize(pow(2, k), 1);
        fft.resize(pow(2, k), 1);

		auto start = chrono::steady_clock::now();
		DFT(dft, 0);
		auto end = chrono::steady_clock::now();
		time_dft[k] = Complex(k,chrono::duration<double, std::nano>(end - start).count());

		start = std::chrono::steady_clock::now();
		FFT(fft, 0);
		end = std::chrono::steady_clock::now();
		time_fft[k] =Complex(k,std::chrono::duration<double, std::nano>(end - start).count());
	}
    write(time_dft,"time_dft");
    write(time_fft,"time_fft");
}

