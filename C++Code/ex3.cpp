#include "functions.h"

int main() {
    vector<Complex> test = read("ex3.txt");
    vector<Complex> test_dpf(test);
    vector<Complex> test_fpf(test);

    cout<<"A)"<<endl;
    DFT(test_dpf,0);
    DFT(test_dpf,1);
    cout<<"MSE between original and RDFT(DFT(X)) = "<<error(test,test_dpf)<<endl;

    cout<<"\nB)"<<endl;
    FFT(test_fpf,0);
    FFT(test_fpf,1);
    cout<<"MSE between original and RFFT(FFT(X)) = "<<error(test,test_fpf)<<endl;

    cout<<"\nC)"<<endl;
    FFT(test,0);
    write(test,"CppFFT");
    return 0;
}

