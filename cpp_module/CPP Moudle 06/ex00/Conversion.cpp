#include "Conversion.hpp"

// ANCHOR canonical form
Conversion::Conversion() {
    input = "";
    type = ERROR;
}

Conversion::~Conversion() {}

Conversion::Conversion(const Conversion &conv) { *this = conv; }

Conversion &Conversion::operator=(const Conversion &conv) {
    if (this != &conv) {
        this->input = conv.getInput();
        this->type = conv.getType();
    }
    return (*this);
}

// ANCHOR getter
std::string Conversion::getInput() const { return (input); }
Types Conversion::getType() const { return (type); }

// ANCHOR print type
void Conversion::printType(char *str) {

    input = str;
    // check char
    if (input.length() == 1 && std::isdigit(input[0]) == 0 &&
        std::isprint(input[0]) != 0) {
        type = CHAR;
        fromChar(input[0]);
        return;
    }
    // strtod 먼저
    char *ptr;
    double tmp = strtod(input.c_str(), &ptr);
    if (*ptr != '\0' && *ptr != 'f') {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        std::cout << "float : impossible" << std::endl;
        std::cout << "double : impossible" << std::endl;
        return;
    } else if (*ptr != '\0' && *(ptr + 1) != '\0') // xxfg
    {
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        std::cout << "float : impossible" << std::endl;
        std::cout << "double : impossible" << std::endl;
        return;
    }
    // type int
    if ((input.find('.') == std::string::npos) &&
        (tmp >= INT_MIN && tmp <= INT_MAX)) {
        type = INT;
        fromInt(static_cast<int>(tmp));
        return;
    }
    // type float
    if ((input.find('.') != std::string::npos && *ptr == 'f') ||
        input == "-inff" || input == "inff" || input == "nanf") {
        type = FLOAT;
        fromFloat(static_cast<float>(tmp));
        return;

    } // type double
    else if ((input.find('.') != std::string::npos) || input == "-inf" ||
             input == "inf" || input == "nan") {
        type = DOUBLE;
        fromDouble(tmp);
        return;
    }
    std::cout << "wrong input" << std::endl;
    return;
}

void Conversion::fromChar(char c) {
    std::cout << "type : char" << std::endl;
    std::cout << "char : "
              << "\'" << c << "\'" << std::endl;
    std::cout << "int : " << static_cast<int>(c) << std::endl;
    std::cout << "float : " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(c) << std::endl;
}

void Conversion::fromInt(int i) {
    std::cout << "type : int" << std::endl;
    if (std::isprint(i) == false)
        std::cout << "char : non displayable" << std::endl;
    else
        std::cout << "char : "
                  << "\'" << static_cast<char>(i) << "\'" << std::endl;
    std::cout << "int : " << i << std::endl;
    std::cout << "float : " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(i) << std::endl;
}

void Conversion::fromFloat(float f) {
    std::cout << "type : float" << std::endl;
    char tmp = static_cast<char>(f);
    if (isnan(f) || isinf(f))
        std::cout << "char : impossible" << std::endl;
    else if (std::isprint(tmp) == false)
        std::cout << "char : non displayable" << std::endl;
    else
        std::cout << "char : "
                  << "\'" << tmp << "\'" << std::endl;
    if (isnan(f) || isinf(f))
        std::cout << "int : impossible" << std::endl;
    else
        std::cout << "int : " << static_cast<int>(f) << std::endl;
    std::cout << "float : " << f << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(f) << std::endl;
}

void Conversion::fromDouble(double d) {
    std::cout << "type : double" << std::endl;
    char tmp = static_cast<char>(d);
    if (isnan(d) || isinf(d))
        std::cout << "char : impossible" << std::endl;
    else if (std::isprint(tmp) == false)
        std::cout << "char : non displayable" << std::endl;
    else
        std::cout << "char : "
                  << "\'" << tmp << "\'" << std::endl;
    if (isnan(d) || isinf(d))
        std::cout << "int : impossible" << std::endl;
    else
        std::cout << "int : " << static_cast<int>(d) << std::endl;
    std::cout << "float : " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double : " << d << std::endl;
}