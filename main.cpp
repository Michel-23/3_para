#include <iostream>
#include "class.h"

int main(){

    Fraction fract = Fraction(1,2); // создание объекта fract
    
    Fraction fract_copy = Fraction(fract); // создание объекта fract_copy 
    std::cout << fract_copy << std::endl;

    Fraction result1; 
    result1= fract + fract_copy;
    std::cout << result1;

    return 0;
}