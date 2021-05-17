#include <iostream>
#include <new>
#include <vector>
#include "particle.h"

// ToDo: define memory management here


struct MemoryPool {
    Particle* particle;
    std::vector<Particle*> freeList;
    int counter;
public:
    explicit MemoryPool(std::size_t initial = sizeof(Particle)*10000) : particle(nullptr) {
        freeList = {};
        counter = 0;
        particle = (Particle*)std::malloc(initial);
    }
    ~MemoryPool() { std::free(particle); }

    void* addToPool() {
        if(!freeList.empty()) {
            Particle* freeSpace = freeList.back();
            freeList.pop_back();
            *freeSpace = Particle();
        }
        else {
            particle[counter] = Particle();
            counter += (sizeof(Particle)+1);
        }
    }

    void deleteFromPool(void* ptr) {
        freeList.push_back((Particle*)ptr);
    }

    Particle& operator[](size_t n) { return particle[n]; }
    Particle operator[](size_t n) const { return particle[n]; }
};

void* Particle::operator new(std::size_t sz) {
    std::cout << "Created new particle" << std::endl;
    return Particle::pool.addToPool();
}

void Particle::operator delete(void* ptr) noexcept {
    std::cout << "Deleting particle" << std::endl;
    Particle::pool.deleteFromPool(ptr);
}


/*
// TODO Signal insufficient memory by returning a nullptr; the particle system handles this case properly
void insufficientMemoryHandler() {
    std::cout << "Memory allocation failed due to insufficient memory." << std::endl;
    set_new_handler(nullptr);
}
 */