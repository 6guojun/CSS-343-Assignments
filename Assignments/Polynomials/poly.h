// ------------------------------------------------ Polynomials Header File -------------------------------------------
// Cameron Padua CSS343 C
// Jan 8, 2016
// Jan 11, 2016
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This program is used for storing a polynomial equations in an array. It has the option use arithmetic
//  operators to add, subtract, multiply, or assign. It also has functions to test equality and assign specific
//  coefficients to power. The final method is to get a coefficient of a power.
// --------------------------------------------------------------------------------------------------------------------
//  Specification: In the array, the subscript corresponds to the power of the coefficient stored in that array location.
//  This program can add, subtract, and multiply equations. This is broken down into a series of methods that can do
//  each arithmetic function. There is also equality methods, clear method, and assignment methods. The final set of
//  methods can set and get powers in the polynomial.
//  Special Algorithms: N/A
//  Assumptions: No bad lines of input will be inserted. This means that the user will only insert pairs of number for
//  storage in the polynomial.
//  The program will be run on c++11
// --------------------------------------------------------------------------------------------------------------------

#ifndef ASSIGNMENTONE_POLY_H
#define ASSIGNMENTONE_POLY_H

#include <iostream>
using namespace std;

class Poly
{
public:
    friend ostream& operator<< (ostream& out, const Poly&); //Friend operator to print a polynomial
    friend istream& operator>> (istream& input, Poly&);     //Friend operator to take numbers into a polynomial

    Poly();                                                 //Default Constructor
    Poly(const Poly&);                                      //Copy Constructor
    Poly(int, int =0);                                      //Constructor with initial starting coefficient or power
    ~Poly();                                                //Deconstructor

    Poly operator+(const Poly&) const;                      //Arithmetic Operator +
    Poly operator-(const Poly&) const;                      //Arithmetic Operator -
    Poly operator*(const Poly&) const;                      //Arithmetic Operator *
    Poly operator=(const Poly&);                            //Assignment Operator

    Poly& operator+=(const Poly&);                          //Arithmetic Operator + and Assignment
    Poly& operator-=(const Poly&);                          //Arithmetic Operator - and Assignment
    Poly& operator*=(const Poly&);                          //Arithmetic Operator * and Assignment

    bool operator==(const Poly&) const;                     //Equal Operator
    bool operator!=(const Poly&) const;                     //Not Equal Operator

    int getCoeff(int) const;                                //Get Coefficeint using power integer
    bool setCoeff(int, int);                                //Set Coefficient using power and operator integers

private:
    void clear();                                           //Clear array method
    void resize(int);                                       //Resize the array to bigger array
    int* pointerToPolynomial;                               //Pointer to array of Coefficients
    int arraySize;                                          //Largest Power in array

};
#endif //ASSIGNMENTONE_POLY_H
