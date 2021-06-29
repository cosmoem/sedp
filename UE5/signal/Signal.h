#pragma once

#include <vector>
#include <iostream>
#include <functional>

template <typename... T>
class Signal {
public:
    Signal() {
        callbacks_ = {};
    };

    void connect(std::function<void(T...)> callback) {
        this->callbacks_.push_back(callback);
    };

    template<typename Z>
    void connect(Z object, void (Z::* const mf)(T...)) {
        this->callbacks_.push_back([&object, mf](auto... args) { return (object.*mf)(args...); });
    };

    void emit(T... values) {
        for (auto callback : callbacks_) {
            callback(values...);
        }
    };

private:
    std::vector<std::function<void(T...)>> callbacks_;
};
