
#include <cassert>
#include <iostream>
#include <string>

#include "Variant.h"


using namespace std::string_literals;


int main(int argc, char * argv[])
{
    auto v0 = Variant();
    assert(!v0.hasType<int>());
    assert(!v0.hasType<float>());
    assert(!v0.hasType<std::string>());

    auto v10 = Variant(std::move(v0));
    assert(!v10.hasType<int>());

    auto v1 = Variant(4);
    auto b1 = v1.hasType<int>();
    auto i1 = v1.get<int>();
    assert(b1);
    assert(i1 == 4);

    auto v11 = Variant(v1);
    assert(v11.hasType<int>());
    auto v12 = Variant(std::move(v1));
    assert(v12.hasType<int>());


    auto v2 = Variant(3.14f);
    auto b2 = v2.hasType<float>();
    auto f2 = v2.get<float>();
    assert(b2);
    assert(f2 == 3.14f);

    auto v3 = Variant(std::string{"barfoo"});
    auto b3 = v3.hasType<std::string>();
    auto s3 = v3.get<std::string>();
    assert(b3);
    assert(s3 == "barfoo");

    assert(!v1.hasType<float>());
    assert(!v1.hasType<std::string>());
    assert(!v2.hasType<int>());
    assert(!v2.hasType<std::string>());
    assert(!v3.hasType<int>());
    assert(!v3.hasType<float>());

    std::cout << "success" << std::endl;
}
