#include <iostream>
#include <cmath>
#include <random>
#include <iomanip>

#define E_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062

using namespace std;

const int PRECISION_THRESHOLD = 10000;

int monteCarlo_float() {
	int tries = 0;
    int insideCircleCounter = 0;
    float approximatedPi;

    std::random_device r;
    std::default_random_engine randomGenerator(r());
	uniform_real_distribution<float> distribution(0.0f, 1.0f);

    vector<float> piVector(100000);
    bool notYetDone = true;
    while(notYetDone) {
        float randomX = distribution(randomGenerator);
        float randomY = distribution(randomGenerator);
        float distanceToCenter = sqrt(randomX*randomX + randomY*randomY);

        if(distanceToCenter <= 1.0f) {
            insideCircleCounter++;
        }
        tries++;

        approximatedPi = ((float)insideCircleCounter/(float)tries)*4.0f;
        auto iterator = piVector.end();
        piVector.insert(iterator, approximatedPi);

        if(tries >= PRECISION_THRESHOLD) {
            float sum = 0.0f;
            for (int i = (int)piVector.size() - PRECISION_THRESHOLD; i < piVector.size(); i++) {
                sum+=piVector.at(i);
            }
            float averagePi = sum / (float)PRECISION_THRESHOLD;
            if(averagePi >= 3.1413f && averagePi <= 3.1419f) {
                notYetDone = false;
            }
        }
    }
	return tries;
}

int monteCarlo_double() {
    int tries = 0;
    int insideCircleCounter = 0;
    double approximatedPi;

    std::random_device r;
    std::default_random_engine randomGenerator(r());
    uniform_real_distribution<double> distribution(0.0, 1.0);

    vector<double> piVector(100000);
    bool notYetDone = true;
    while(notYetDone) {
        double randomX = distribution(randomGenerator);
        double randomY = distribution(randomGenerator);
        double distanceToCenter = sqrt(randomX*randomX + randomY*randomY);

        if(distanceToCenter <= 1.0) {
            insideCircleCounter++;
        }
        tries++;

        approximatedPi = ((double)insideCircleCounter/(double)tries)*4.0;
        auto iterator = piVector.end();
        piVector.insert(iterator, approximatedPi);

        if(tries >= PRECISION_THRESHOLD) {
            double sum = 0.0;
            for (int i = (int)piVector.size() - PRECISION_THRESHOLD; i < piVector.size(); i++) {
                sum+=piVector.at(i);
            }
            double averagePi = sum / (double)PRECISION_THRESHOLD;
            if(averagePi >= 3.1413 && averagePi <= 3.1419) {
                notYetDone = false;
            }
        }
    }
    return tries;
}

int monteCarlo_long_double() {
    int tries = 0;
    int insideCircleCounter = 0;
    long double approximatedPi;

    std::random_device r;
    std::default_random_engine randomGenerator(r());
    uniform_real_distribution<long double> distribution(0.0L, 1.0L);

    vector<long double> piVector(100000);
    bool notYetDone = true;
    while(notYetDone) {
        long double randomX = distribution(randomGenerator);
        long double randomY = distribution(randomGenerator);
        long double distanceToCenter = sqrt(randomX*randomX + randomY*randomY);

        if(distanceToCenter <= 1.0L) {
            insideCircleCounter++;
        }
        tries++;

        approximatedPi = ((long double)insideCircleCounter/(long double)tries)*4.0L;
        auto iterator = piVector.end();
        piVector.insert(iterator, approximatedPi);

        if(tries >= PRECISION_THRESHOLD) {
            long double sum = 0.0L;
            for (int i = (int)piVector.size() - PRECISION_THRESHOLD; i < piVector.size(); i++) {
                sum+=piVector.at(i);
            }
            long double averagePi = sum / (long double)PRECISION_THRESHOLD;
            if(averagePi >= 3.1413L && averagePi <= 3.1419L) {
                notYetDone = false;
            }
        }
    }
}

int main(int argc, char * argv[])
{
    // tries to get to a medium error of < 0.01% for the last 10000 iterations
    cout << "Float Tries: " <<  monteCarlo_float() << endl;
	cout << "Double Tries: " << monteCarlo_double() << endl;
	cout << "Long Double Tries: " << monteCarlo_long_double() << endl;

    cout << "-----------------------------------------" << endl;
	
	// most exact output for the three data types
	cout << "(in-) Exact Output of float Pi: " << fixed << setprecision(65) << E_PI << endl;
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
