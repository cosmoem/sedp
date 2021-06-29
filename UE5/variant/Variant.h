
#pragma once

#include <typeindex>
#include <stdexcept>
#include <memory>

class Variant {
private:
    struct AbstractTypeContainer {
        virtual ~AbstractTypeContainer() = default;
    };

    template <typename InnerType>
    struct TypeContainer : AbstractTypeContainer {
        TypeContainer() = default;

        ~TypeContainer() override = default;

        explicit TypeContainer(InnerType value) : type(value) {}
        InnerType type;
        InnerType& getValue() {
            return type;
        }
    };

    std::shared_ptr<AbstractTypeContainer> typeContainer;
    size_t typeHashCode{};
public:
    Variant() = default;

    ~Variant() = default;

    template <typename Type>
    explicit Variant(Type value) {
        typeContainer = std::make_shared<TypeContainer<Type>>(std::move(value));
        typeHashCode = typeid(Type).hash_code();
    }

    Variant(Variant && other) noexcept;

    Variant(Variant const & other) = default;

    template <typename InputType>
    bool hasType() {
        auto test = typeid(InputType).hash_code();
        if (typeHashCode == test) {
            return true;
        }
        return false;
    }

    template <typename InputType>
    InputType get() {
        if (hasType<InputType>()) {
            return static_cast<TypeContainer<InputType>*>(typeContainer.get())->getValue();
        }
        throw std::logic_error("Types don't match!");
    }
};
