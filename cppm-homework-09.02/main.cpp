//
//  main.cpp
//  cppm-homework-09.02
//
//  Created by a1ex on 12/7/23.
//

#include <iostream>
#include <math.h>

class Fraction
{
private:
    int numerator_;
    int denominator_;
    
public:
    // Конструктор по умолчанию инициализирует дробь 0/1
    Fraction() : numerator_(0), denominator_(1) {}
 
    // Конструктор, принимающий числитель и знаменатель
    Fraction(int x, int y) : numerator_(x), denominator_(y) {}
 
    // Оператор перегрузки сложения
    Fraction operator+(const Fraction& other) const {
        int commonDenominator = denominator_ * other.denominator_;
        int numerator = numerator_ * other.denominator_ + other.numerator_ * denominator_;
        return Fraction(numerator, commonDenominator);
    }
 
    // Оператор перегрузки вычитания
    Fraction operator-(const Fraction& other) const {
        int commonDenominator = denominator_ * other.denominator_;
        int numerator = numerator_ * other.denominator_ - other.numerator_ * denominator_;
        return Fraction(numerator, commonDenominator);
    }
 
    // Оператор перегрузки умножения
    Fraction operator*(const Fraction& other) const {
        int numerator = numerator_ * other.numerator_;
        int denominator = denominator_ * other.denominator_;
        return Fraction(numerator, denominator);
    }
 
    // Оператор перегрузки деления
    Fraction operator/(const Fraction& other) const {
        int numerator = numerator_ * other.denominator_;
        int denominator = denominator_ * other.numerator_;
        return Fraction(numerator, denominator);
    }
    
    Fraction operator++()
    {
        numerator_++;
        return *this;
    }
    
    Fraction operator++(int)
        {
            Fraction temp = *this;
            ++(*this);
            return temp;
    }
 
    Fraction operator--()
    {
        numerator_--; return *this;
    }
    
    Fraction operator--(int)
        {
            Fraction temp = *this;
            --(*this);
            return temp;
    }
    
    // Метод печати в консоль
    void Print() const {
        std::cout << numerator_ << "/" << denominator_ << std::endl;
    }
};
 
int main()
{
    int a;
    int b;
    int c;
    int d;
    
    std::cout << "Введите числитель первой дроби: ";
    std::cin >> a;
    std::cout << '\n' << "Введите знаминатель первой дроби: ";
    std::cin >> b;
    std::cout << '\n' << "Введите числитель второй дроби: ";
    std::cin >> c;
    std::cout << '\n' << "Введите знаминатель второй дроби: ";
    std::cin >> d;
    std::cout << std::endl;
    
    Fraction f1(a, b);
    Fraction f2(c, d);
    
  
    Fraction sum = f1 + f2;
    std::cout << a << "/" << b << " + " << c << "/" << d << " = ";
    sum.Print();
    std::cout << std::endl;
    Fraction difference = f1 - f2;
    std::cout << a << "/" << b << " - " << c << "/" << d << " = ";
    difference.Print();
    std::cout << std::endl;
    Fraction product = f1 * f2;
    std::cout << a << "/" << b << " * " << c << "/" << d << " = ";
    product.Print();
    std::cout << std::endl;
    Fraction quotient = f1 / f2;
    std::cout << a << "/" << b << " / " << c << "/" << d << " = ";
    quotient.Print();
    std::cout << std::endl;
    Fraction inc = ++f1 * f2;
    std::cout << "++" << a << "/" << b << " * " << c << "/" << d << " = ";
    inc.Print();
    std::cout << "Значение дроби 1 = ";
    f1.Print();
    std::cout << std::endl;
    Fraction dec = f1-- * f2;
    std::cout << a << "/" << b << "--" << " * " << c << "/" << d << " = ";
    dec.Print();
    std::cout << "Значение дроби 1 = ";
    f1.Print();
    std::cout << std::endl;

    
    
    return 0;
};

