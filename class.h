#include <iostream>
#include <cmath>
#include <cstdint>

class Fraction{
private:
    int32_t _num;
    int32_t _denom;

public:
    Fraction();
    Fraction(int32_t num, uint32_t denom);

    void SetDenom(uint32_t newDenom);
    void SetNum(int32_t newNum);

    Fraction(double n);
    void Print();
    int nod(int32_t first, int32_t second); // методы класса
    int CelCh();

    //конструктор копирования
    Fraction(const Fraction& fract /*передаем ссылку чтобы не тратить память*/);

    // Перегрузка операции сложения 
    Fraction operator+ (const Fraction& fraction) const /*нельзя изменять поля*/{
        int32_t new_num = _num * fraction._denom + fraction._num * _denom;
        uint32_t new_denom = _denom * fraction._denom;
        Fraction res = Fraction(new_num, new_denom);
        return res;
    }

    // Перегрузка операции разности
    Fraction operator- (const Fraction& fraction) const{
        int32_t new_num = _num * fraction._denom - fraction._num * _denom;
        uint32_t new_denom = _denom * fraction._denom;
        Fraction res = Fraction(new_num, new_denom);
        return res;
    }

    // Перегрузка операции умножения
    Fraction operator* (const Fraction& fraction) const{
        int32_t new_num = _num * fraction._num;
        uint32_t new_denom = _denom * fraction._denom;
        Fraction res = Fraction(new_num, new_denom);
        return res;
    }

    // Перегрузка операции деления
    Fraction operator/ (const Fraction& fraction) const{
        int32_t new_num = _num * fraction._denom;
        uint32_t new_denom = _denom * fraction._num;
        Fraction res = Fraction(new_num, new_denom);
        return res;
    }

    // Перегрузка операции больше
    bool operator> (const /*объект типа Fraction не будет изменен при обращении к нему через ссылку*/ Fraction& fraction) const /*мы НЕ меняем объект класса*/{
        int32_t new_num = _num * fraction._denom;
        int32_t new_num1 = fraction._num * _denom;
        return !(new_num <= new_num1);
    }

    // Перегрузка операции меньше
    bool operator< (const Fraction& fraction) const{
        int32_t new_num = _num * fraction._denom;
        int32_t new_num1 = fraction._num * _denom;
        if (new_num >= new_num1){
            return false;
        }
        else{
            return true;
        }
    }

    bool operator<= (const Fraction& fraction) const{
        int32_t new_num = _num * fraction._denom;
        int32_t new_num1 = fraction._num * _denom;
        if (new_num > new_num1){
            return false;
        }
        else{
            return true;
        }
    }

    bool operator>= (const Fraction& fraction) const{
        int32_t new_num = _num * fraction._denom;
        int32_t new_num1 = fraction._num * _denom;
        if (new_num < new_num1){
            return false;
        }
        else{
            return true;
        }
    }

    bool operator!= (const Fraction& fraction) const{
        int32_t new_num = _num * fraction._denom;
        int32_t new_num1 = fraction._num * _denom;
        if (new_num == new_num1){
            return false;
        }
        else{
            return true;
        }
    }

    bool operator== (const Fraction& fraction) const{
        int32_t new_num = _num * fraction._denom;
        int32_t new_num1 = fraction._num * _denom;
        if (new_num == new_num1){
            return true;
        }
        else{
            return false;
        }
    }

    // Перегрузка операции смена знака
    Fraction& operator~() {
        _num = -_num;
        return *this;
    }

    Fraction operator^ (const double st) const{
        int32_t new_num = pow(_num, st);
        int32_t new_denom = pow(_denom, st);
        Fraction res = Fraction(new_num, new_denom);
        return res;
    }

    Fraction& operator++ (){
        _num = _num + _denom;
        return *this;
    }

    Fraction& operator-- (){
        _num = _num - _denom;
        return *this;
    }

    Fraction operator++ (int32_t){
        Fraction res = Fraction(_num, _denom);
        _num = _num + _denom;
        return res;
    }

    Fraction operator-- (int32_t){
        Fraction res = Fraction(_num, _denom);
        _num = _num - _denom;
        return res;
    }

    // Перегрузка операции равно
    Fraction& operator= (const Fraction& fraction){
        _num = fraction._num;
        _denom = fraction._denom;
        std::cout << "Operator ravno -> " << *this << std::endl;
        return *this;
    }

    // Перегрузка операции вывода в консоль
    inline void PrintDouble(){
        std::cout << static_cast<double> (_num) / _denom << std:: endl;
    }

    friend std::ostream& operator<< (std::ostream& os, const Fraction& tmp){
        os << tmp._num << "/" << tmp._denom << std:: endl;
        return os;
    }
};