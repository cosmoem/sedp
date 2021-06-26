#pragma once

#include <vector>
#include <iostream>
#include <functional>
#include <iostream>

template<typename... T>
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
        auto x = [&object, mf](auto... args) { return (object.*mf)(args...); };
        this->callbacks_.push_back(x);
    };

    void emit(T... values) {
        for (auto callback : callbacks_) {
            callback(values...);
        }
    };

private:
    std::vector<std::function<void(T...)>> callbacks_;
};
