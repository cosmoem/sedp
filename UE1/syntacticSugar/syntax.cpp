
#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <sstream>

// TODO: Start of solution
// You may edit / add anything from here to satisfy the interfaces and behaviors expected by the execution code below

struct Currency
{
    unsigned long long int cents;

    friend Currency operator&&(Currency c1, Currency c2) {
        return Currency { c1.cents + c2.cents };
    }

    friend bool operator==(Currency c1, int c2) {
        return c1.cents == c2;
    }

    friend Currency operator,(Currency c1, Currency c2) {
        return Currency {c1.cents + c2.cents};
    };
};

Currency operator "" _euro(unsigned long long int cents) {
    return Currency {cents*100};
}

Currency operator "" _cents(unsigned long long int cents) {
    return Currency {cents};
}

Currency operator "" _cent(unsigned long long int cents) {
    return Currency {cents};
}

namespace Bills
{
    const auto Five = Currency { 500 };
    const auto Ten = Currency { 1000 };
    const auto Twenty = Currency { 2000 };
    const auto Fifty = Currency { 5000 };
}

struct Account
{
    Currency balance = 0_euro;

    explicit Account(const Currency & balance)
    : balance(balance)
    {
    }

    friend unsigned long long int operator >> (Account & a1, Currency c) {
        a1.balance.cents -= c.cents;
        return c.cents;
    }

    friend void operator >> (unsigned long long int c, Account & a1) {
        a1.balance.cents += c;
    };

    friend unsigned long long int operator << (Account & a1, Currency c) {
        a1.balance.cents += c.cents;
        return c.cents;
    }

    friend void operator << (unsigned long long int c, Account & a1) {
        a1.balance.cents -= c;
    };

    friend std::ostream& operator<<(std::ostream& os, Account a1) {
        os << std::to_string(a1.balance.cents);
        return os;
    }

    friend std::stringstream & operator<<(std::stringstream & os, Account a1) {
        unsigned long long int euroValue = a1.balance.cents/100;
        unsigned long long int centValue = a1.balance.cents - euroValue*100;
        os << "Account with balance " << euroValue << " euro, " << centValue << " cents";
        return os;
    }

};

struct Object
{
public:
    Object(float value, bool count);
    ~Object();
    
    operator float() const { return m_value; }
    
    float m_value;
};

struct Converter
{
    float m_value;

    operator float() const { return float(m_value); }
    operator Object() const { return Object{ m_value, true }; }
};

struct Generator
{
    static size_t objectInstanceCount;

    // return converter instead of object
    // --> implicit conversion happens via conversion functions defined in converter struct
    Converter operator()()
    {
        auto value = (float) rand();
        return Converter {value};
    }
};

struct Matrix
{

    struct ConditionX {
        int x;
    };

    struct ConditionY {
        int y;
    };

    struct Condition {
        int x, y;
    };

    struct Cells {
        Matrix& m;
        int indeces[16] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

        Cells(Matrix &m) : m(m) {};

        Matrix& operator=(float value) {
            for (int i=0; i<16; i++) {
                if(this->indeces[i] >= 0) {
                    m.m_f[indeces[i]] = value;
                }
            }
            return this->m;
        }
    };

    float m_f[16];
    ConditionX x;
    ConditionY y;
    const int SIZE = sizeof(m_f)/sizeof(m_f[0]);

    friend Condition operator==(ConditionY y, ConditionX x) {
        return Condition {0,0};
    }

    friend Condition operator<(ConditionY y, ConditionX x) {
        return Condition {1,0};
    }

    friend Condition operator>(ConditionY y, ConditionX x) {
        return Condition {0,1};
    }

    Cells operator[](Condition a) {
        Cells cells = Cells {*this};
        int counter = 0;
        if(a.y == a.x && a.y >= 0) {
            for (size_t i = 0; i < SIZE; i++)
            {
                int x_pos = (i / 4);
                int y_pos = i - x_pos*4;
                if(x_pos==y_pos) {
                    cells.indeces[counter] = i;
                    counter++;
                }
            }
        }
        else if(a.y < a.x && a.y >= 0) {
            for (size_t i = 0; i < SIZE; i++)
            {
                int x_pos = (i / 4);
                int y_pos = i - x_pos*4;
                if(x_pos<y_pos) {
                    cells.indeces[counter] = i;
                    counter++;
                }
            }
        }
        else {
            for (size_t i = 0; i < SIZE; i++)
            {
                int x_pos = (i / 4);
                int y_pos = i - x_pos*4;
                if(x_pos>y_pos) {
                    cells.indeces[counter] = i;
                    counter++;
                }
            }
        }
        return cells;
    }

public:

    Matrix& operator[](Matrix m1) {

    }

    Matrix()
    {
        for (size_t i = 0; i < SIZE; i++)
        {
            m_f[i] = 0.0f;
        }
        x = ConditionX {-1};
        y = ConditionY {-1};
    }
    
    Matrix(std::initializer_list<float> initializer)
    {
        assert(initializer.size() == SIZE); // sizeof of an array returns total size in bytes --> divide by size of a single element
        size_t i = 0;
        for (auto value : initializer)
        {
            m_f[i] = value;
            i++;
        }
        x = ConditionX {-1};
        y = ConditionY {-1};
    }

    bool operator==(Matrix m1) {
        // when comparing two arrays with == the pointers are compared --> no equality, instead compare each element
        for(int i=0; i< sizeof(m_f)/sizeof(m_f[0]); i++) {
            if(m1.m_f[i] != this->m_f[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(Matrix m1) {
        for(int i=0; i< sizeof(m_f)/sizeof(m_f[0]); i++) {
            if(m1.m_f[i] != this->m_f[i]) {
                return true;
            }
        }
        return false;
    }
};

// End of solution
// Do not edit the source code below!

// Generator::objectInstanceCount must be incremented on object creation and shall never be manipulated otherwise
Object::Object(float value, bool count) : m_value(value) { if (count) Generator::objectInstanceCount++; }
Object::~Object() {}
size_t Generator::objectInstanceCount = 0;

void generator()
{
    Generator gen;
    std::vector<float> floats;
    std::vector<Object> objects;
	
    assert(objects.size() == Generator::objectInstanceCount);

    for (auto i = 0; i < 500; ++i)
    {
        if (i % 7 == 0)
        {
            floats.emplace_back(gen());
        }
        else if (i % 5 == 0)
        {
            objects.emplace_back(gen());
        }
        else
        {
            std::cout << gen() << std::endl;
        }
    }
    
    assert(objects.size() == Generator::objectInstanceCount);
}

void accounting()
{
    Account a { 200_euro and 34_cents };
    Account b { 300_euro and 1_cent };

    b >> (100_euro, 32_cents) >> a;

    assert(a.balance == 30066);
    assert(b.balance == 19969);
    
    b << Bills::Fifty << a;

    assert(a.balance == 25066);
    assert(b.balance == 24969);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    std::stringstream stream_a;
    stream_a << a;
    std::stringstream stream_b;
    stream_b << b;
    std::cout << stream_a.str() << std::endl;
    assert(stream_a.str() == "Account with balance 250 euro, 66 cents");
    assert(stream_b.str() == "Account with balance 249 euro, 69 cents");
}

void matrix()
{
    Matrix m;
    
    Matrix m1 = { 0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0,   0, 0, 0, 0 };
    assert(m == m1);

    m[m.y == m.x] = 1.0f;

    Matrix m2 = { 1, 0, 0, 0,   0, 1, 0, 0,   0, 0, 1, 0,   0, 0, 0, 1 };
    assert(m == m2);
    
    m[m.y > m.x] = 3.0f;
    
    Matrix m3 = { 1, 0, 0, 0,   3, 1, 0, 0,   3, 3, 1, 0,   3, 3, 3, 1 };
    assert(m == m3);
    
    m[m.y < m.x] = 4.0f;
    
    Matrix m4 = { 1, 4, 4, 4,   3, 1, 4, 4,   3, 3, 1, 4,   3, 3, 3, 1 };
    assert(m == m4);
    /*
    m[3_y, 2_x] = 12.0f;
    
    Matrix m5 = { 1, 4, 4, 4,   3, 1, 4, 4,   3, 3, 1, 4,   3, 3, 12, 1 };
    assert(m == m5);
    
    m[3_x, 2_y] = 42.0f;
    
    Matrix m6 = { 1, 4, 4, 4,   3, 1, 4, 4,   3, 3, 1, 42,   3, 3, 12, 1 };
    assert(m == m6);
    
    m[m.y == 0] = 2.0f;
    
    Matrix m7 = { 2, 2, 2, 2,   3, 1, 4, 4,   3, 3, 1, 42,   3, 3, 12, 1 };
    assert(m == m7);*/
}

int main(int argc, char * argv[])
{
    generator();
    accounting();
    matrix();
    
    return 0;
}
