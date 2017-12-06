/** Jennifer Byrne
    27/09/2017
    Lab 15
    Sinewave Calculations */

/** Preprocessor directives */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
using namespace std;


/** Class */
class Waveform
{
    private:
                double amplitude, frequency, phase, dcOff, instantVol, time, period, vrms, radPhase;

    public:
                /** Overloaded constructor */
                Waveform(void)
                {
                    amplitude = 1;
                    frequency = 1000;
                    phase = 0;
                    dcOff = 0;
                }

                /** Function member to read in values */
                void getValues (void)
                {
                    cout << "Amplitude :\t" ;
                    cin >> amplitude;
                    cout << "\nFrequency :\t" ;
                    cin >> frequency;
                    cout << "\nPhase angle :\t" ;
                    cin >> phase;
                    cout << "\nDC offset :\t" ;
                    cin >> dcOff;
                    cout << "\nTime :\t" ;
                    cin >> time;
                }

                /** Instantaneous voltage member function */
                double Vinst(void)
                {
                    radPhase = phase * (M_PI / 180);
                    instantVol = amplitude * sin((2 * M_PI * frequency * time) + radPhase) + dcOff;
                    cout << "\nInstantaneous Voltage of Sinewave : \t" << instantVol << endl;
                    return instantVol;
                }

                /** Period member function */
                double periodCal (void)
                {
                    period = 1.0 / frequency;
                    cout << "\nPeriod :\t" << period << endl;
                    return period;
                }

                /** Vrms member function */
                double vrmsCal (void)
                {
                    vrms = amplitude / sqrt(2.0);
                    cout << "\nVrms :\t" << vrms << endl << endl;
                    return vrms;
                }

};

/** Main function */
int main()
{
    /** object instantiation */
    Waveform sinewave;
    /** heading displayed on console */
    cout << "Sinewave Calculations\n\n";

    /** Call classes to calculate waveform parameters */
    sinewave.getValues();
    sinewave.Vinst();
    sinewave.periodCal();
    sinewave.vrmsCal();

    /** Terminate main function */
    return 0;
}
