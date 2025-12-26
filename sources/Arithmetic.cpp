#include "Arithmetic.hpp"

#include <gmp.h>  // Include the GMP library

#include <stdexcept>  // For exceptions

// Constructor - Initialize the result
Arithmetic::Arithmetic() {
    mpz_init(m_result);  // Initialize m_result
}

// Destructor - Clean up GMP variables
Arithmetic::~Arithmetic() {
    mpz_clear(m_result);  // Clear the result
}

void Arithmetic::add(std::string a, std::string b) {
    // Convert the std::string to a GMP mpz_t
    mpz_t gmpA;
    mpz_init(gmpA);
    mpz_set_str(gmpA, a.c_str( ), 10);  // Base 10 for decimal string to mpz_t
    mpz_t gmpB;
    mpz_init(gmpB);
    mpz_set_str(gmpB, b.c_str( ), 10);  // Base 10 for decimal string to mpz_t

    mpz_add(m_result, gmpA, gmpB);  // Perform addition

    mpz_clear(gmpB);
}

void Arithmetic::subtract(std::string a, std::string b) {
    mpz_t gmpA;
    mpz_init(gmpA);
    mpz_set_str(gmpA, a.c_str( ), 10);  // Base 10 for decimal string to mpz_t
    mpz_t gmpB;
    mpz_init(gmpB);
    mpz_set_str(gmpB, b.c_str( ), 10);  // Base 10 for decimal string to mpz_t

    mpz_sub(m_result, gmpA, gmpB);  // Perform subtraction

    mpz_clear(gmpB);
}

void Arithmetic::multiply(std::string a, std::string b) {
    mpz_t gmpA;
    mpz_init(gmpA);
    mpz_set_str(gmpA, a.c_str( ), 10);  // Base 10 for decimal string to mpz_t
    mpz_t gmpB;
    mpz_init(gmpB);
    mpz_set_str(gmpB, b.c_str( ), 10);  // Base 10 for decimal string to mpz_t

    mpz_mul(m_result, gmpA, gmpB);  // Perform multiplication

    mpz_clear(gmpB);
}

void Arithmetic::divide(std::string a, std::string b) {
    mpz_t gmpA;
    mpz_init(gmpA);
    mpz_set_str(gmpA, a.c_str( ), 10);  // Base 10 for decimal string to mpz_t
    mpz_t gmpB;
    mpz_init(gmpB);
    mpz_set_str(gmpB, b.c_str( ), 10);  // Base 10 for decimal string to mpz_t

    if (mpz_sgn(gmpB) == 0) {  // Check for division by zero
        mpz_clear(gmpB);
        throw std::invalid_argument("Division by zero");
    }

    mpz_tdiv_q(m_result, gmpA, gmpB);  // Perform division

    mpz_clear(gmpB);
}

// Getter for the result
std::string Arithmetic::getResult() const {
    std::string str;

    // Convert mpz_t to std::string (base 10 by default)
    std::string char_str = mpz_get_str(NULL, 10, m_result);

    // Convert to std::string
    str = std::string(char_str);

    return str;
}
