#include <iostream>
#include <cmath>
#include "class.h"

int main(){

    Fraction fract = Fraction(1,2); // создание объекта fract
    
    Fraction fract_copy = Fraction(fract); // создание объекта fract_copy 
    std::cout << fract_copy << std::endl;

    Fraction result1 = fract + fract_copy;
    std::cout << result1;

    Fraction result2 = fract - fract_copy;
    std::cout << result2;

    Fraction result3 = fract * fract_copy;
    std::cout << result3;

    Fraction result4 = fract / fract_copy;
    std::cout << result4 << std:: endl;

    Fraction result5 = fract > fract_copy;
    std::cout << result5;

    return 0;
}