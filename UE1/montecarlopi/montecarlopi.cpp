#include <iostream>
#include <cmath>
#include <random>
#include <iomanip>

#define E_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062

using namespace std;

float float_pi = 0.0f;
double double_pi = 0.0;
long double long_double_pi = 0.0L;

int monteCarlo_float() {
	int tries = 0;
    int insideCircleCounter = 0;
    int exactnessCounter = 0;
    float approximatedPi;

    // TODO use random device or not ?
    std::random_device r;
    std::default_random_engine randomGenerator(r());
	uniform_real_distribution<float> distribution(0.0f, 1.0f);

    // TODO: siehe frage in mooodle --> so lassen oder average error für 10k iterations berechnen?
    while(exactnessCounter<10000) {
        float randomX = distribution(randomGenerator);
        float randomY = distribution(randomGenerator);
        float distanceToCenter = sqrt(randomX*randomX + randomY*randomY);

        if(distanceToCenter <= 1.0f) {
            insideCircleCounter++;
        }
        tries++;

        approximatedPi = ((float)insideCircleCounter/(float)tries)*4.0f;

        if(approximatedPi >= 3.1413f && approximatedPi <= 3.1419f) {
            exactnessCounter++;
        }
        else {
            exactnessCounter = 0;
        }
    }
    float_pi = approximatedPi;
	return tries;
}

int monteCarlo_double() {
    int tries = 0;
    int insideCircleCounter = 0;
    int exactnessCounter = 0;
    double approximatedPi;

    std::default_random_engine randomGenerator; // TODO use random engine ?
    uniform_real_distribution<double> distribution(0.0, 1.0);

    while(exactnessCounter<10000) {
        double randomX = distribution(randomGenerator);
        double randomY = distribution(randomGenerator);
        double distanceToCenter = sqrt(randomX*randomX + randomY*randomY);

        if(distanceToCenter <= 1.0) {
            insideCircleCounter++;
        }
        tries++;

        approximatedPi = ((double)insideCircleCounter/(double)tries)*4.0;

        if(approximatedPi >= 3.1413 && approximatedPi <= 3.1419) {
            exactnessCounter++;
        }
        else {
            exactnessCounter = 0;
        }
    }
    double_pi = approximatedPi;
    return tries;
}

int monteCarlo_long_double() {
    int tries = 0;
    int insideCircleCounter = 0;
    int exactnessCounter = 0;
    long double approximatedPi;

    std::default_random_engine randomGenerator; // TODO use random engine ?
    uniform_real_distribution<long double> distribution(0.0L, 1.0L);

    while(exactnessCounter<10000) {
        long double randomX = distribution(randomGenerator);
        long double randomY = distribution(randomGenerator);
        long double distanceToCenter = sqrt(randomX*randomX + randomY*randomY);

        if(distanceToCenter <= 1.0L) {
            insideCircleCounter++;
        }
        tries++;

        approximatedPi = ((long double)insideCircleCounter/(long double)tries)*4.0L;

        if(approximatedPi >= 3.1413L && approximatedPi <= 3.1419L) {
            exactnessCounter++;
        }
        else {
            exactnessCounter = 0;
        }
    }
    long_double_pi = approximatedPi;
    return tries;
}

int main(int argc, char * argv[])
{
    // tries to get to a medium error of < 0.01% for the last 10000 iterations
	cout << "Float Tries: " <<  monteCarlo_float() << endl;
	cout << "Double Tries: " << monteCarlo_double() << endl;
	cout << "Long Double Tries: " << monteCarlo_long_double() << endl;

    cout << "-----------------------------------------" << endl;

    // approximated pi values
    cout << "Approximated float Pi: " << fixed << setprecision(8) << float_pi << endl;
    cout << "Approximated double Pi: " << double_pi << endl;
    cout << "Approximated long double Pi: " << long_double_pi << endl;

    cout << "-----------------------------------------" << endl;
	
	// most exact output for the three data types
	cout << "(in-) Exact Output of float Pi: " << setprecision(65) << E_PI << endl;
    cout << "Storage for float Pi: " << sizeof(E_PI) << " bytes" << endl << endl;

	float fPi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062f;
    cout << "Most Exact Output of float Pi: " << fPi << endl;
	cout << "Storage for float Pi: " << sizeof(fPi) << " bytes" << endl << endl;

	double dPi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062;
    cout << "Most Exact Output of double Pi: " << dPi << endl;
    cout << "Storage for double Pi: " << sizeof(dPi) << " bytes" << endl << endl;

    long double ldPi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062L;
    cout << "Most Exact Output of long double Pi: " << ldPi << endl;
    cout << "Storage for long double Pi: " << sizeof(ldPi) << " bytes" << endl << endl;

    return 0;
}
