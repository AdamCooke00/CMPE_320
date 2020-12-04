//The implementation of the Fraction Class
// Adam Cooke - 10/16/2020

#include <iostream>
#include <string>

#include "fraction_17adc4.h"

using namespace std;

Fraction::Fraction() : num(0), denom(1) {
}

Fraction::Fraction(int value) : num(value), denom(1) {
}

Fraction::Fraction(int topVal, int botVal){
    if(botVal == 0){
        throw FractionException("Can not divide by 0");
    }
    //for every negative number flip the sign of an int than use this int to set negation of fraction
    int numOfNeg(1);
    if(topVal < 0){
        numOfNeg*= -1;
        topVal*= -1;
    }
    if(botVal < 0){
        numOfNeg*= -1;
        botVal*= -1;
    }

    int gcd = getGCD(topVal, botVal);
    num = numOfNeg*topVal/gcd;
    denom = botVal/gcd;
}

Fraction& Fraction::operator++(){
    num+= denom;
    return *this;
}

Fraction Fraction::operator++(int unused){
    Fraction clone(num, denom);
    num+= denom;
    return clone;
}

Fraction& Fraction::operator+=(const Fraction& value){
    *this = *this + value;
    return *this;
}

int Fraction::denominator() const{
    return denom;
}

int Fraction::numerator() const{
    return num;
}

int Fraction::getGCD(int n, int m){
    if(m <= n && n%m == 0){
        return m;
    }
    if (n<m){
        getGCD(m, n);
    } else{
        getGCD(m, n%m);
    }
}

FractionException::FractionException(const string& problem) : errorMessage(problem){
}

string FractionException::what(){
    return errorMessage;
}

ostream& operator<< (ostream &out, const Fraction &value){
    out << value.numerator() << "/" << value.denominator();
    return out;
}

istream& operator>> (istream &in, Fraction &value){
    string unChangedInput;
    in >> unChangedInput;
    int index = unChangedInput.find('/');
    //if there is no '/' then set fraction to val/1
    if(index == -1){
        value.num = stoi(unChangedInput);
        value.denom = 1;
        return in;
    }
    //else cast the num string to numerator and denom string to denominator
    value.num = stoi(unChangedInput.substr(0,index));
    value.denom = stoi(unChangedInput.substr(index+1));
    return in;
}

//
// overloaded methods
//

Fraction operator+ (const Fraction& a, const Fraction& b){
    return Fraction(a.numerator()*b.denominator() + b.numerator()*a.denominator(), a.denominator()*b.denominator());
}

Fraction operator- (const Fraction& a, const Fraction& b){
    return Fraction(a.numerator()*b.denominator() - b.numerator()*a.denominator(), a.denominator()*b.denominator());
}

Fraction operator* (const Fraction& a, const Fraction& b){
    return Fraction(a.numerator()*b.numerator(), a.denominator()*b.denominator());
}

Fraction operator/ (const Fraction& a, const Fraction& b){
    return Fraction(a.numerator()*b.denominator(), a.denominator()*b.numerator());
}

Fraction operator- (const Fraction& value){
    return Fraction(-1 * value.numerator(), value.denominator());
}

bool operator== (const Fraction& a, const Fraction& b){
    return !compare(a, b);
};

bool operator!= (const Fraction& a, const Fraction& b){
    return (compare(a, b));
};

bool operator> (const Fraction& a, const Fraction& b){
    return (compare(a, b) == 1);
};

bool operator>= (const Fraction& a, const Fraction& b){
    return (compare(a, b) != -1);
};

bool operator< (const Fraction& a, const Fraction& b){
    return (compare(a, b) == -1);
    // return true;
};

bool operator<= (const Fraction& a, const Fraction& b){
    return (compare(a, b) != 1);
    // return true;
};


//compare method that takes 2 fractions
//returns 1  : if the first is larger than the second
//returns 0  : if both are equal
//returns -1 : if first is less than second
int compare(const Fraction& a, const Fraction& b){
    double aDoub = static_cast<double>(a.numerator()) / static_cast<double>(a.denominator());
    double bDoub = static_cast<double>(b.numerator()) / static_cast<double>(b.denominator());
    if(aDoub > bDoub){
        return 1;
    } else if(aDoub == bDoub){
        return 0;
    } else{
        return -1;
    }
}