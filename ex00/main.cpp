#include "ScalarConverter.hpp"

int main() {
    // Test with integer literal
    std::cout << "Test with 42:" << std::endl;
    ScalarConverter::convert("42");
    std::cout << std::endl;

    // Test with float literal
    std::cout << "Test with 42.0f:" << std::endl;
    ScalarConverter::convert("42.0f");
    std::cout << std::endl;

    // Test with double literal
    std::cout << "Test with 42.0:" << std::endl;
    ScalarConverter::convert("42.0");
    std::cout << std::endl;

    // Test with char literal
    std::cout << "Test with 'a':" << std::endl;
    ScalarConverter::convert("a");
    std::cout << std::endl;

    // Test with special float literal
    std::cout << "Test with nanf:" << std::endl;
    ScalarConverter::convert("nanf");
    std::cout << std::endl;

    // Test with special double literal
    std::cout << "Test with +inf:" << std::endl;
    ScalarConverter::convert("+inf");
    std::cout << std::endl;

    return 0;
}
