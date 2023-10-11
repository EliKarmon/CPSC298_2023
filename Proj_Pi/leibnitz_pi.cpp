
#include <cmath> 
#include <iostream>
#include <iomanip>
#include <cfloat>

using namespace std;

int main()
{
    double piOver4 = 0.0;
    double pi = 0;
    int n;
    double kpow;
    double denom;
    cout << "Enter a value for n " << endl;
    cin >> n;
    for(int k = 0; k < n; k++)
    {
        kpow = pow(-1.0,k);
        denom = 2 * k + 1;
        piOver4 += kpow / denom;
        pi = piOver4 * 4;     
    }
    cout << "Pi (approx): " << setprecision(DBL_DIG) << pi << "; n: " << setw(7) << n << endl;
    cout << "Pi (actual): " << "3.141592653589793" << std::endl;

}
