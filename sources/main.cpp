#include <iostream>
#include <memory>

#include "Arithmetic.hpp"

int main() {
    // Create a unique pointer to Arithmetic
    std::unique_ptr<Arithmetic> arithmetic = std::make_unique<Arithmetic>();

    // Perform operations
    arithmetic->add("12345678901234567890", "98765432109876543210");
    std::cout << "Addition Result: " << arithmetic->getResult() << std::endl;

    arithmetic->subtract("98765432109876543210", "12345678901234567890");
    std::cout << "Subtraction Result: " << arithmetic->getResult() << std::endl;

    arithmetic->multiply("12345678901234567890", "98765432109876543210");
    std::cout << "Multiplication Result: " << arithmetic->getResult() << std::endl;

    arithmetic->divide("98765432109876543210", "12345678901234567890");
    std::cout << "Division Result: " << arithmetic->getResult() << std::endl;

    return 0;
}
