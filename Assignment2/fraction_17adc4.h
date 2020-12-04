//Declaration file fot the Fraction Class
// Adam Cooke - 10/16/2020

#pragma once

using namespace std;

class Fraction{
    public:
        Fraction(); //default constructor; creates a "zero" fraction. 0/1
        Fraction(int value); //sets fraction to value/1
        Fraction(int topVal, int botVal); //takes num and demon and makes lowest fraction using gcd
        Fraction& operator++(); //pre increment overload
        Fraction operator++(int unused); //post increment overload, uses clone
        Fraction& operator+=(const Fraction& value); //+= overload
        int numerator() const;  //numerator accessor
        int denominator() const;//denominator accessor
    private:
        int getGCD(int n, int m);  //takes numerator and denominator and returns gcd              
        int num;    //numerator of fraction
        int denom;  //denominator of fraction

    friend istream& operator>> (istream &in, Fraction &value); //istream overload. Is a friend as it changes the value of the fraction argument
};

class FractionException{
    public:
        FractionException(const string& problem); //takes in a string of what the problem is and sets it to the error message
        string what(); //getter method for error message, returns the errorMessage
    private:
        string errorMessage; //what the error is
};

ostream& operator<< (ostream &out, const Fraction &value); //ostream overload, outputs num/denom

Fraction operator+ (const Fraction& a, const Fraction& b);  //addition overload
Fraction operator- (const Fraction& a, const Fraction& b);  //subtraction overload
Fraction operator* (const Fraction& a, const Fraction& b);  //multiplication overload
Fraction operator/ (const Fraction& a, const Fraction& b);  //division overload
Fraction operator- (const Fraction& value);                 //negation overload

bool operator== (const Fraction& a, const Fraction& b);     //equivalence overload
bool operator!= (const Fraction& a, const Fraction& b);     //non equivalence overload
bool operator> (const Fraction& a, const Fraction& b);      //greater than overload
bool operator>= (const Fraction& a, const Fraction& b);     //greater than or equal overload
bool operator< (const Fraction& a, const Fraction& b);      //less than overload
bool operator<= (const Fraction& a, const Fraction& b);     //less than or equal overload

int compare(const Fraction& a, const Fraction& b);          //compare method that enables the equialence overloaded methods to have modularity