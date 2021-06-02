#include <string>
#include <map>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <new>
#include <cassert>


//
// Note: the memory measurement is preliminary, we may use a different approach depending on the creativity of the implementations
//
auto memory = std::size_t{0};

[[nodiscard]] void *operator new(std::size_t size) {
    const auto ptr = std::malloc(size);
    if (!ptr) {
        throw std::bad_alloc{};
    }
    memory += size;
    return ptr;
}

void operator delete(void *ptr, std::size_t size) {
    std::free(ptr);
    memory -= size;
}


// Add any required definitions and implementations for Address
class Address {
private:
    std::string street_;
    int number_;
    int postalCode_;
    std::string town_;

public:
    Address(const std::string &street, int number, int postalCode, const std::string &town) : street_(street),
                                                                                              number_(number),
                                                                                              postalCode_(postalCode),
                                                                                              town_(town) {}

    Address() {};

    const std::string &street() const {
        return street_;
    }

    int number() const {
        return number_;
    }

    int postalCode() const {
        return postalCode_;
    }

    const std::string &town() const {
        return town_;
    }

    void setStreet(const std::string &street) {
        street_ = street;
    }

    void setNumber(int number) {
        number_ = number;
    }

    void setPostalCode(int postalCode) {
        postalCode_ = postalCode;
    }

    void setTown(const std::string &town) {
        town_ = town;
    }

    operator bool() const {
        return !this->street_.empty() && number_ && postalCode_ && !this->town_.empty();
    }

    bool operator==(const Address &address) const {
        return this->street_ == address.street() &&
               this->number_ == address.number() &&
               this->postalCode_ == address.postalCode() &&
               this->town_ == address.town();
    }

    bool operator<(const Address &address) const {
        if (this->street_ == address.street()) {
            if (this->number_ == address.number()) {
                if (this->postalCode_ == address.postalCode()) {
                    if (this->town_ == address.town()) {
                        return false;
                    }
                    return this->town_ < address.town();
                }
                return this->postalCode_ < address.postalCode();
            }
            return this->number_ < address.number();
        }
        return this->street_ < address.street();
    }

    friend bool operator>(const Address &address1, const Address &address2) {
        return !(address1 < address2);
    }

    friend bool operator!=(const Address &address1, const Address &address2) {
        return !(address1 == address2);
    }

    friend std::stringstream &operator<<(std::stringstream &ss, const Address &address) {
        auto delimiter = ' ';
        ss << address.street() << delimiter << address.number() << delimiter << address.postalCode() << delimiter
           << address.town();
        return ss;
    }

    friend std::stringstream &operator>>(std::stringstream &ss, Address &address) {
        std::string street, town;
        int number, postalCode;

        ss >> street >> number >> postalCode >> town;

        address.setStreet(street);
        address.setNumber(number);
        address.setPostalCode(postalCode);
        address.setTown(town);

        return ss;
    }

    explicit operator std::tuple<std::string, int, int, std::string>() const {
        return std::make_tuple(this->street_, this->number_, this->postalCode_, this->town_);
    }

};

template<>
struct std::hash<Address> {
    std::size_t operator()(const Address &address) const {
        auto ss = std::stringstream{};
        ss << address.street() << address.number() << address.postalCode() << address.town() << std::endl;
        return std::hash<std::string>()(ss.str());
    }
};

//
// Do not change the code below
//


int main(int argc, char *argv[]) {
    {
        auto vec = std::vector<std::pair<std::string, Address>>{};

//        auto file = std::ifstream{"../integration/addresses.txt"}; // for cmake clion
        auto file = std::ifstream{"addresses.txt"};
        if (!file) {
            std::cerr << "Failed to open file addresses.txt" << std::endl;
            return EXIT_FAILURE;
        }
        while (file) {
            std::string firstName, lastName;
            auto fields = std::tuple<std::string, int, int, std::string>{};
            if (file >> firstName >> lastName >> std::get<0>(fields) >> std::get<1>(fields) >> std::get<2>(fields)
                     >> std::get<3>(fields)) {
                const auto address = std::make_from_tuple<Address>(fields);
                assert(address.street() != "" && address.number() > 0 && address.postalCode() > 0 &&
                       address.town() != "");
                vec.emplace_back(firstName + " " + lastName, address);
            }
        }

        std::cout << "Memory: " << memory << std::endl;

        std::map<Address, std::vector<std::string>> treemap;
        for (const auto &item : vec) {
            if (item.second) {
                treemap[item.second].push_back(item.first);
            }
        }

        std::unordered_map<Address, std::size_t> hashmap;
        for (const auto &item : treemap) {
            // serialize it
            std::stringstream data;
            data << item.first;
            // deserialize it
            Address address;
            data >> address;
            auto value = size(item.second);

            hashmap[address] = value;
        }

        for (const auto &item : hashmap) {
            // Extra challenge (for fun): make the line below work instead
            const auto&[street, number, postalCode, town] = static_cast<std::tuple<std::string, int, int, std::string>>(item.first);
            // const auto& [street, number, postalCode, town] = item.first;

            // DISCLAIMER: We changed the output to match the screenshot in the exercise sheet.
            std::cout << street << " " << number << " " << postalCode << " " << town << ": " << item.second
                      << std::endl;
        }
    }

    std::cout << "Memory: " << memory << std::endl;
}
