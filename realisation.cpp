#include "class.h"

void Fraction::SetDenom(uint32_t newDenom){
    if (newDenom == 0)
        throw "Divide by zero!";
    _denom = newDenom;
}

void Fraction::SetNum(int32_t newNum){
    _num = newNum;
}

Fraction:: Fraction(double n){
    int32_t num = (int)(round(n * 10000000));
    int32_t denom = 10000000;
    int temp = nod(fabs(num), fabs(denom)); // Нод
    if (temp > 1){ // сокращение
        num /= temp;
        denom /= temp;
    }
    _num = num;
    _denom = denom;
}

int Fraction::nod(int32_t first, int32_t second){
    if ((first<=0) || (second<=0))
        return -1;
    else if (first==second) 
        return first;
    else{  
        int maxx=fmax(first,second);
        int minn=fmin(first,second);
        return nod(minn,maxx-minn);
    }
}

void Fraction::Print(){
    int cel = CelCh();
    if (cel == 0){
        if (_num == 0){
            std::cout << 0 << std::endl;
        }    
        else{
            std::cout << _num << "/" << _denom << std::endl;
        }
    }
    else{
        std::cout << cel << " ";
        if (_num - cel*_denom !=0)
            std::cout << _num - cel*_denom  << "/" << _denom;
        std::cout << std::endl;
    }

}

int Fraction::CelCh(){
    int temp;
    if (_num > _denom){
        temp = floor(_num / _denom);
    }
    else{
        temp = 0;
    }
    return temp;
}

Fraction::Fraction(){
    std::cout << "Default constructor -> " << this << std::endl;
    _num = 0;
    _denom = 1;
}

Fraction::Fraction(int32_t num, uint32_t denom){
    _num = num; // присвоение вводимых значений полям класса
    SetDenom(denom);
    //this == fract == объект типа Fraction
    std:: cout << "Parametr constructor -> " << this << std:: endl;
}

Fraction::Fraction(const Fraction& fract){
    _denom = fract._denom;
    _num = fract._num;
    std::cout << "Copy constructor -> " << this /*указатель на себя (fract)*/<< std::endl;
}