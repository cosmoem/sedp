
#include <iostream>

// include appropriate header file
#include "modcounter.h"

int main(int argc, char * argv[])
{
    // create ModuloCounter m1 with the interval [0, 10)
    ModuloCounter m1 = ModuloCounter(0, 10);
    // print m1
    std::cout << "m1: " << m1;

    // add 23 to m1
    m1 = m1 + 23;
    // print m1
    std::cout << "m1: " << m1;

    // increment m1 and create ModuloCounter m2 with the new value
    m1++;
    ModuloCounter m2 = ModuloCounter(m1);
    // print m1
    std::cout << "m1: " << m1;
    // print m2
    std::cout << "m2: " << m2;

    // decrement m2 and create ModuloCounter m3 with the old value
    ModuloCounter m3 = ModuloCounter(m2);
    --m2;
    // print m2
    std::cout << "m2: "  << m2;
    // print m3
    std::cout << "m3: "  << m3;

    // create ModuloCounter m4 with the interval [-7, 18)
    ModuloCounter m4 = ModuloCounter(-7, 18);
    // print m4
    std::cout << "m4: "  << m4;

    // set m4 to 267
    m4 = 267;
    // print m4
    std::cout << "m4: "  << m4;

    // create ModuloCounter m5 with the result of multiplying m4 and m3
    ModuloCounter m5 = ModuloCounter(m4*m3);
    // print m5
    std::cout << "m5: "  << m5;

    // set m5 to m2
    m5 = m2;
    // print m2
    std::cout << "m2: "  << m2;

    // create ModuloCounter m6 with the interval [-11, -3) and initial value of m5
    int m5initialValue = (ModuloCounter(m4*m3)).getValue();
    ModuloCounter m6 = ModuloCounter(m5initialValue, -11, -3);
    // print m6
    std::cout << "m6: "  << m6;

    // create int i1 with the value of m6
    int i1 = m6.getValue();
    // print i1
    std::cout << "i1: "  << i1 << std::endl;

    // create ModuloCounter m7 with the result of subtracting 7 from m6
    ModuloCounter m7 = m6-7;
    // print m7
    std::cout << "m7: "  << m7;

    // create int i2 with the value of multiplying 5 with m7
    int i2 = 5*m7;
    // print i2
    std::cout << "i2: "  << i2 << std::endl;
}
