#include <iostream>
#include <new>
#include "particle.h"

MemoryPool Particle::pool = MemoryPool();

MemoryPool::MemoryPool() noexcept {
    for(bool & i : freeList) {
        i = false;
    }
}
MemoryPool::~MemoryPool() = default;

void* MemoryPool::addToPool(std::size_t sz) {
    for(int i=0; i < freeListSize; ++i) {
        if(!freeList[i]) {
            freeList[i] = true;
            return &buf[sz*i];
        }
    }
    return nullptr;
}

void MemoryPool::deleteFromPool(void* ptr) {
    for(int i=0; i < freeListSize; ++i) {
        if(&buf[sizeof(Particle)*i] == ptr) {
            freeList[i] = false;
            return;
        }
    }
}

void* Particle::operator new(std::size_t sz) noexcept {
    void *ptr = Particle::pool.addToPool(sz);
    if(ptr) {
        std::cout << "Created new particle: " << ptr << std::endl;
    }
    else {
        std::cout << "Insufficient Memory: " << ptr << std::endl;
    }
    return ptr;
}

void Particle::operator delete(void* ptr) noexcept {
    std::cout << "Deleting particle: " << ptr << std::endl;
    Particle::pool.deleteFromPool(ptr);
}