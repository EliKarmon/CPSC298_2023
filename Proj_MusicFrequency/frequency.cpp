
#include <iostream> 

using namespace std;
int main()
{
    double stfreq = 16.35;
    int soundSpeed = 345;
    double twelfthTwo = 1.059463094359; 

    int k; 
    double finalFreq;
    int octaveNum; 
    double wavelength;
    int nupow;
    double kpow; 

    cout << "reference frequency: " << stfreq << endl;
    cout << "speed of sound: " << soundSpeed << endl;
    //c0
    octaveNum = 0;
    k = 0;
    nupow = pow(2,octaveNum);
    kpow = pow(twelfthTwo,k);
    finalFreq = stfreq * nupow * kpow;
    wavelength = soundSpeed * 100 / finalFreq;
    cout << "c0; nu = " << octaveNum << " frequency = " << finalFreq << "; wavelength = " << wavelength << "cm" << endl;
    //c#0
    octaveNum = 0;
    k = 1;
    nupow = pow(2,octaveNum);
    kpow = pow(twelfthTwo,k);
    finalFreq = stfreq * nupow * kpow;
    wavelength = soundSpeed * 100 / finalFreq;
    cout << "c#0; nu = " << octaveNum << " frequency = " << finalFreq << "; wavelength = " << wavelength << "cm" << endl;
    //D0
    octaveNum = 0;
    k = 2;
    nupow = pow(2,octaveNum);
    kpow = pow(twelfthTwo,k);
    finalFreq = stfreq * nupow * kpow;
    wavelength = soundSpeed * 100 / finalFreq;
    cout << "d0; nu = " << octaveNum << " frequency = " << finalFreq << "; wavelength = " << wavelength << "cm" << endl;
    //c4
    octaveNum = 4;
    k = 0;
    nupow = pow(2,octaveNum);
    kpow = pow(twelfthTwo,k);
    finalFreq = stfreq * nupow * kpow;
    wavelength = soundSpeed * 100 / finalFreq;
    cout << "c4; nu = " << octaveNum << " frequency = " << finalFreq << "; wavelength = " << wavelength << "cm" << endl;
    //d#7
    octaveNum = 7;
    k = 3;
    nupow = pow(2,octaveNum);
    kpow = pow(twelfthTwo,k);
    finalFreq = stfreq * nupow * kpow;
    wavelength = soundSpeed * 100 / finalFreq;
    cout << "d#7; nu = " << octaveNum << " frequency = " << finalFreq << "; wavelength = " << wavelength << "cm" << endl;
    //c8
    octaveNum = 8;
    k = 0;
    nupow = pow(2,octaveNum);
    kpow = pow(twelfthTwo,k);
    finalFreq = stfreq * nupow * kpow;
    wavelength = soundSpeed * 100 / finalFreq;
    cout << "c8; nu = " << octaveNum << " frequency = " << finalFreq << "; wavelength = " << wavelength << "cm" << endl;
}