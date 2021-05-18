#include <iostream>
#include <new>
#include <vector>
#include "particle.h"

// ToDo: define memory management here

MemoryPool Particle::pool = MemoryPool();

MemoryPool::MemoryPool(std::size_t initial) {
    /*int oneParticle = sizeof(Particle);
    if(initial == 10000) {
        initial = 10000;
    }*/
    this->initial = initial;
    for(int i=0; i < initial; ++i) {
        freeList[i] = false;
    }
}
MemoryPool::~MemoryPool() {}

void* MemoryPool::addToPool(std::size_t sz) {
    for(int i=0; i < initial; ++i) {
        if(!freeList[i]) {
            freeList[i] = true;
            return &buf[sz*i];
        }
    }
    return nullptr_t();
}

void MemoryPool::deleteFromPool(void* ptr) {
    for(int i=0; i < initial; ++i) {
        if(&buf[sizeof(Particle)*i] == ptr) {
            freeList[i] = false;
            return;
        }
    }
}

void* Particle::operator new(std::size_t sz) noexcept {
    std::cout << "Created new particle" << std::endl;
    return Particle::pool.addToPool(sz);
}

void Particle::operator delete(void* ptr) noexcept {
    std::cout << "Deleting particle" << std::endl;
    Particle::pool.deleteFromPool(ptr);
}