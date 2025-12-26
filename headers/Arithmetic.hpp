#ifndef ARITHMETIC_HPP
#define ARITHMETIC_HPP

#include <gmp.h>
#include <memory>
#include <string>

class Arithmetic {
public:
    Arithmetic();   // Constructor
    ~Arithmetic();  // Destructor

    // Arithmetic operations
    void add(std::string a, std::string b);
    void subtract(std::string a, std::string b);
    void multiply(std::string a, std::string b);
    void divide(std::string a, std::string b);

    // Get result as a string
    std::string getResult() const;

private:
    mpz_t m_result;  // GMP big integer result
};

#endif  // ARITHMETIC_HPP
