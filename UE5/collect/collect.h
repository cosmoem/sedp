
#pragma once

template <typename R>
R collect(auto input, auto function) {
    auto output = R();
    for (auto &element : input) {
        output.insert(output.end(), function(element));
    }
    return output;
}
