
#pragma once


#include <string>

namespace MI {
    class Transaction {
    public:
        explicit Transaction(const std::string &name);

        virtual ~Transaction() = default;

        [[nodiscard]] const std::string &name() const;

        void process(const std::string &operation);


    protected:
        virtual void onBeforeProcess(const std::string &operation);

        virtual void onAfterProcess(const std::string &operation);


    private:
        std::string m_name;
    };
}

namespace NonMI {
    class Transaction {
    public:
        explicit Transaction(const std::string &name);

        virtual ~Transaction() = default;

        [[nodiscard]] const std::string &name() const;

        void process(const std::string &operation);


    protected:
        virtual void onBeforeProcess(const std::string &operation);

        virtual void onAfterProcess(const std::string &operation);


    private:
        std::string m_name;
    };
}