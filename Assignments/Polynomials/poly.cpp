// ------------------------------------------------ Polynomials Implementation File ------------------------------------
// Cameron Padua CSS343 C
// Jan 8, 2016
// Jan 11, 2016
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This program is used for storing a polynomial equations in an array. It has the option use arithmetic
//  operators to add, subtract, multiply, or assign. It also has functions to test equality and assign specific
//  coefficients to power. The final method is to get a coefficient of a power.
// --------------------------------------------------------------------------------------------------------------------
// Specification: In the array, the subscript corresponds to the power of the coefficient stored in that array location.
//  This program can add, subtract, and multiply equations. This is broken down into a series of methods that can do
//  each arithmetic function. There is also equality methods, clear method, and assignment methods. The final set of
//  methods can set and get powers in the polynomial.
//  Special Algorithms: N/A
//  Assumptions: No bad lines of input will be inserted. This means that the user will only insert pairs of number for
//  storage in the polynomial.
//  The program will be run on c++11
// --------------------------------------------------------------------------------------------------------------------

#include "poly.h"
// ------------------------------------Default Constructor--------------------------------------------------------------
// Description: This Constructor is used when the user creates a instance of the Polynomial class, but set no parameters
//  are given. In this situation, the largest power is 1 and the pointer is assigned a new Integer array. The value for
//  the power of one is zero.
// ---------------------------------------------------------------------------------------------------------------------
Poly::Poly()
{                                                //constructor open brace
    arraySize = 1;                               //Setting the arraySize to 1
    pointerToPolynomial = new int[arraySize];    //Setting the pointer a new Array of integers
    clear();                                     //clearing the memory of the array.
}                                                //constructor close brace
// ------------------------------------Constructor with Default Parameters----------------------------------------------
// Description: This constructor is used when the user has a coefficient that they want to use when creating an instance
// of this class. They also have a option to choose a power for which the coefficient will be set, if they do not choose
//  a power, the default will be zero. The arraySize must be one larger than the power they want to insert in order to
//  fit all the coefficients inside the array.
// ---------------------------------------------------------------------------------------------------------------------
Poly::Poly(int coefficent, int power)
{                                               //constructor open brace
    arraySize = power + 1;                      //set the array size to one larger than the desired power
    pointerToPolynomial = new int[arraySize];   //set the pointer to a new array in dynamic memory with array size
    clear();                                    //clear the memory of the array
    pointerToPolynomial[power] = coefficent;      //set the desired power, or default power, to the desired coefficient
}                                               //constructor close brace
// ------------------------------------Copy Constructor--------------------------------------------------------------
// Description: This constructor is used when the user is making a deep copy of another polynomial instance at the
//  creation of this polynomial. It retrieves each value from the copyPolynomial, and set the current polynomial to that
//  value.
// ---------------------------------------------------------------------------------------------------------------------
Poly::Poly(const Poly& copyPolynomial)
{                                               //constructor open brace
    arraySize = copyPolynomial.arraySize;       //set the arraySize to the copyPolynimial's arraySize
    pointerToPolynomial = new int[arraySize];   //set the pointer to a new array with copiedSize
   for(int currentPower = 0; currentPower <
           copyPolynomial.arraySize; currentPower++)   //loop for every value
   {                                                   //for loop open brace
        pointerToPolynomial[currentPower] =
                copyPolynomial.pointerToPolynomial[currentPower];//set the current Polynomial tothe copyPolynomial value
   }                                            //for loop close brace
}                                               //constructor close brace
// ------------------------------------DeConstructor--------------------------------------------------------------
// Description: This is used at the end of the program when it automatically calls the class deconstructors. These are
//  used to deallocate dynamic memory and set their pointers to an nullptrs
// ---------------------------------------------------------------------------------------------------------------------
Poly::~Poly()
{                                   //constructor open brace
    delete[] pointerToPolynomial;   //delete/deallocate the dynamic array memory
    pointerToPolynomial = nullptr;  //set the pointer to a nullptr
}                                   //constructor close brace
// ------------------------------------clear--------------------------------------------------------------
// Description: this is a private method that will clear the memory of the dynamic array allocations. It will set all
// values in the array from garbage values to zero.
// ---------------------------------------------------------------------------------------------------------------------

void Poly::clear()
{                                                                           //method open brace
    for(int currentPower = 0; currentPower < arraySize; currentPower++){    //loop for every value in the array
        pointerToPolynomial[currentPower] = 0;                              //set the current value to zero
    }                                                                       //method close brace
}
// ------------------------------------resize--------------------------------------------------------------
// Description: This method is used when the array needs to be resized to be larger. It takes in the new size that the
//  array need to accommodate and makes the array one size bigger. This is so that we create an array that is big enough
//  to hold all coefficients in the array.
// ---------------------------------------------------------------------------------------------------------------------
void Poly::resize(int newSize)
{                                                                               //method open brace
    int* newPolynomialEquation =  new int[newSize+1];                           //create a array of coefficients for the
                                                                                //one larger than the current largest
    for(int currentPower = 0; currentPower < arraySize; currentPower++)         //loop for all values in the initial
                                                                                // polynomial
    {                                                                           //for loop open brace
        newPolynomialEquation[currentPower] = getCoeff(currentPower);           //get the coefficient of the initial
                                                                                //polynomial and set the new array
    }                                                                           //for loop close brace

    for(int currentPower = arraySize; currentPower < newSize+1; currentPower++) //loop for all uninitialized values in
                                                                                //the new polynomial
    {                                                                           //for loop open brace
        newPolynomialEquation[currentPower] = 0;                                //set the current value to zero
    }                                                                           //for loop close brace

    delete[] pointerToPolynomial;                                               //deallocate the old array memory
    arraySize = newSize + 1;                                                    //set the arraySize to the new size
    pointerToPolynomial = newPolynomialEquation;                                //set the pointer to the new array
}                                                                               //close method brace
// ------------------------------------setCoeff--------------------------------------------------------------
// Description: This method is used to set a coefficient of a given power. Powers that are lower than zero are ignored,
//  powers larger than or equal to the arraySize make the array resize, and powers within the array set the coefficient.
// ---------------------------------------------------------------------------------------------------------------------
bool Poly::setCoeff(int coefficent, int power)
{                                                   //method open brace
    if(power<0)                                     //base case fail, power is below zero
    {                                               //if open brace
        return false;                               //break out of method and return false
    }                                               //end of initial brace
    if(power>=arraySize)                            //case: power is greater than or equal to the arraySize
    {                                               //else if open brace
        resize(power);                              //call the resize method with the larger power
        pointerToPolynomial[power] = coefficent;    //with the new resized array, set the coefficient of the power
        return true;                                //break out of method and return true
    }                                               //else if end brace
    else                                            //case: the power falls within the current array
    {                                               //else open brace
        pointerToPolynomial[power] = coefficent;    //set the array location to the coefficient
        return true;                                //break out of method and return true
    }                                               //else close brace
}                                                   //method close brace
// ------------------------------------getCoeff--------------------------------------------------------------
// Description: This method is used to get the coefficient at a specified power. If that power is negative or that power
//  is larger than or equal to the array size, it will return zero.
// ---------------------------------------------------------------------------------------------------------------------
int Poly::getCoeff(int power) const
{                                           //method open brace
    if(power>=arraySize||power<0)           //base case: power is outside the array
    {                                       //if open brace
        return 0;                           //return zero, coefficient is false
    }                                       //if close brace
    else                                    //case: power is within range
    {                                       //else open brace
        return pointerToPolynomial[power];  //return the value of the power array location
    }                                       //else close brace
}                                           //method close brace
// ------------------------------------operator>>--------------------------------------------------------------
// Description: This method overload is used when the user wishes to input values from the console into a polynomial
//  class. This method assumes that the user will give value in pairs of coefficients and powers with an exit case of
//  -1 -1. This method will continue to run until the exit case has been satisfied.
// ---------------------------------------------------------------------------------------------------------------------
istream& operator>>(istream &input, Poly& targetPolynomial)
{                                                               //method open brace
    int tempCoefficient = 0;                                    //temporary storage for coefficient value passed in
    int tempPower = 0;                                          //temporary storage for power value passed in
    input >> tempCoefficient;                                   //take user input and put into tempCoefficient
    input >> tempPower;                                         //takes user inpit and stored it in tempPower
    while (tempPower != -1 || tempCoefficient != -1)            //loop until base case fail of -1 -1
    {                                                           //while loop open brace
        targetPolynomial.setCoeff(tempCoefficient, tempPower);  //set the coefficients of the given power using setCoeff
        input >> tempCoefficient;                               //get next user input and store it
        input >> tempPower;                                     //get next user input and store it
    }                                                           //while loop close brace
    return input;                                               //returns input stream
}
// ------------------------------------operator<<--------------------------------------------------------------
// Description: This method overload is used when the user want to print a polynomial or want to store a polynomial to a
// file. It overloads the << method provided. For powers greater than one, it will print in this format:
// (NUMBER)x^(Power). For powers equal to one, it will print (NUMBER)x. For powers/constants, it will print (NUMBER).
//  If the polynomial is empty, it will print 0.
// ---------------------------------------------------------------------------------------------------------------------
ostream& operator<<(ostream &out, const Poly& targetPolynomial)
{                                                               //method open brace
    int coefficient;                                            //temporary storage for coefficients pulled from array
    if(targetPolynomial.arraySize == 1)                           //if the array is a constant
    {                                                           //if open brace
        return out << targetPolynomial.pointerToPolynomial[0];  //return the constant value
    }                                                           //if close brace
    else                                                        //else case: polynomial is larger than constant
    {                                                           //else open brace
        for (int currentPower = targetPolynomial.arraySize - 1; //for all value in the polynomial, decreasing values
             currentPower >= 0; currentPower--)
        {                                                       //for loop open brace
            coefficient = targetPolynomial.pointerToPolynomial[currentPower]; //store the value in the coefficient value
            if (coefficient > 0)                                //case:coefficient is positive
            {                                                   //if 1 open brace
                if (currentPower == 1)                          //case: power is one
                {                                               //if 2 open brace
                    cout << " +" << coefficient << "x";         //print special format (NUMBER)x
                }                                               //if 2 close brace
                else if (currentPower == 0)                     //case: power is zero
                {                                               //else if open brace
                    cout <<" +" << coefficient;                  //print special format +(NUMBER)
                }                                               //close else if
                else if(coefficient != 0)                         //case: not zero or one
                {                                               //else if open brace
                    cout << " +" << coefficient << "x^" << currentPower;    //print special format +(NUMBER)x^(POWER)
                }                                               //else if close brace
            }                                                   //close if 1 brace
            else                                                //case: coefficent is less than or equal to zero
            {                                                   //else open brace
                if (currentPower == 1 && coefficient != 0)      //current power is one and coeffcient is not zero
                {                                               //open if brace
                    cout << " " << coefficient << "x";          //print special format (NUMBER)x
                }                                               //close if brace
                else if (currentPower == 0 && coefficient != 0) //case: power is zero and coeffcient is not zero
                {                                               //open else if brace
                    cout << " " << coefficient;                   //print special case: (NUMBER)
                }                                               //close else if brace
                else if(coefficient != 0)                       //case: coefficent is not zero and power is greater than
                                                                //one
                {                                               //else if open brace
                    cout << " " << coefficient << "x^" << currentPower; //print special format
                }                                               //else if close brace
            }                                                   //else close brace
        }                                                       // for loop close brace
        return out;                                             //and return retVal
    }                                                           //else close brace
}                                                               //method close brace
// ------------------------------------operator==--------------------------------------------------------------
// Description: This overloaded method is used for checking equality between two polynomials. This methods first
//  compares the size of each polynomials, if they are not the same, it will return false. If they are, it then
//  walks though the length of both arrays comparing coefficients of each power; if those are the same, it will return
//  true. However, if any time they are not the same, it will return false;
// ---------------------------------------------------------------------------------------------------------------------
bool Poly::operator==(const Poly& otherPolynomial) const
{                                                                           //method open brace
    if(arraySize==otherPolynomial.arraySize)                                //case: compare equality of the sizes of
                                                                            // each array
    {                                                                       //if open brace
        for(int currentPower = 0; currentPower < arraySize; currentPower++) //loop until the end of the array
        {                                                                   //for lopp open brace
            if(pointerToPolynomial[currentPower] !=                         //case: check the value at a power is the
                    otherPolynomial.pointerToPolynomial[currentPower])      //the same for both polynomials
            {                                                               //if open brace
                return false;                                               //they are not the same coefficient
            }                                                               //if close brace
        }                                                                   //for loop close brace
        return true;                                                        //all the coefficients are the same
    }                                                                       //close if
    else                                                                    //the array sizes are not the same
    {                                                                       //open else brace
        return false;                                                       //not the same
    }                                                                       //close else brace
}                                                                           //close method brace
// ------------------------------------operator!=--------------------------------------------------------------
// Description: This overloaded method compares if two polynomials are not the same. THis method accomplishes this by
//  comparing if they are equal and then negating that boolean.
// ---------------------------------------------------------------------------------------------------------------------
bool Poly::operator!=(const Poly& otherPolynomial) const
{                                                                           //open method brace
    return !(pointerToPolynomial == otherPolynomial.pointerToPolynomial);   //negate the equal method comparison
}                                                                           //close method brace
// ------------------------------------operator=--------------------------------------------------------------
// Description: This overloaded assigns a polynomial instance to a polynomial object. This methods compares the two
//  addresses of each polynomial, if they are not the same, it will delete the old array (if there is one). Next it
//  set the size of this to the copy
// ---------------------------------------------------------------------------------------------------------------------
Poly Poly::operator=(const Poly& otherPolynomial)
{                                                                       //method open brace
    if (this != &otherPolynomial)                                       //make sure they are not at the same address
    {                                                                   //if open braces
        delete[] pointerToPolynomial;                                   //deallocate old array memory
        arraySize = otherPolynomial.arraySize;                          //set old arraySize to copy arraySize
        pointerToPolynomial = new int[arraySize];                       //set pointer to a new array with new arraySize
        for(int currentPower = 0; currentPower <                        //for loop for all values in copy array
                otherPolynomial.arraySize; currentPower++)
        {                                                               //for loop open brace
            setCoeff(otherPolynomial.pointerToPolynomial[currentPower], //access the other Polynomial value and set the
                     currentPower);                                     //new value
        }                                                               //for loop close brace
    }                                                                   //if close brace
    return *this;                                                       //return a pointer for the new array pointer
}                                                                       //close method brace
// ------------------------------------operator+--------------------------------------------------------------
// Description: This method is used to add two different polynomials together into one polynomial. THis method will
//  choose the biggest polynomial and make a copy using the assignment operator. Next it will add the smaller array to
// the new copy of the other polynomial. Finally it will return a copy of this polynomial to the orginal location
// ---------------------------------------------------------------------------------------------------------------------
Poly Poly::operator+(const Poly& otherPolynomial) const
{                                                               //method open brace
    Poly sumPolynomial;                                         //the sum of the two polynomials storage instance
    if(arraySize>=otherPolynomial.arraySize)                    //case:This polynomial is larger then the other
    {
       sumPolynomial = *this;                                   //make a copy of this polynomial
        for(int currentPower = 0; currentPower <
                otherPolynomial.arraySize; currentPower++)      //loop through the length of the other polynomial
        {                                                       //for loop open brace
            sumPolynomial.pointerToPolynomial[currentPower] +=   //set this polynomial plus the other polynomial
                            otherPolynomial.pointerToPolynomial[currentPower];
        }                                                       //close for loop brace
    }
    else                                                        //case: other Polynomial is larger
    {
        sumPolynomial = otherPolynomial;                        //make a copy of the otherPolynomial
        for(int currentPower = 0; currentPower <
                arraySize; currentPower++)                      //Add contents of RHS to LHS
        {                                                       //for loop open brace
            sumPolynomial.pointerToPolynomial[currentPower] +=
                    pointerToPolynomial[currentPower];          //set sum Polynomial to other plus this
        }                                                       //close for loop brace
    }                                                           //close else brace
    return sumPolynomial;                                       //return the sumPolynomial
}
// ------------------------------------operator---------------------------------------------------------------
// Description: This overloaded method will return the difference between two polynomials. This methods does this by
//  finding the larger between the two polynomials. If this is larger, it makes a copy of this and subtracts the other
//  polynomial. If the other polynomial is larger, it creates a new Polynomial larger enough for the otherPolynomial
//  and clears the values. Next it will set the first values to the this Polynomial and subtract the otherPolynomial
// ---------------------------------------------------------------------------------------------------------------------
Poly Poly::operator-(const Poly& otherPolynomial) const
{                                                                       //method open brace
    if(arraySize>=otherPolynomial.arraySize)
    {
        Poly differencePolynomial(*this);                               //make a copy of this Polynomial
        for(int currentPower = 0; currentPower <
                otherPolynomial.arraySize; currentPower++)              //loop for the length of the otherPolynomial
        {                                                               //for loop open brace
            differencePolynomial.pointerToPolynomial[currentPower] -=
                    otherPolynomial.pointerToPolynomial[currentPower];  //set the difference to the subtraction of the
                                                                        //current value and the other Polynomial value
        }                                                               //close for loop brace
        return differencePolynomial;                                    //return the difference Polynomial
    }
    else                                                                //case: otherPolynomial is larger than this Poly
    {                                                                   //else open brace
        Poly differencePolynomial(0, otherPolynomial.arraySize-1);      //create a Polynomial with the size of the other
                                                                        //Polynomial
        for(int currentPower = 0; currentPower < arraySize; currentPower++)//loop for the size of this Polynomial
        {                                                               //for loop open brace
            differencePolynomial.pointerToPolynomial[currentPower] =
                    pointerToPolynomial[currentPower];                  //set the differencePolynomial to this Poly
        }                                                               //close for loop brace
        for(int currentPower = 0; currentPower <
                otherPolynomial.arraySize; currentPower++)              //loop for the length of the other Poly
        {                                                               //for loop open brace
            differencePolynomial.pointerToPolynomial[currentPower] -=
                    otherPolynomial.pointerToPolynomial[currentPower];  //set the differencePolynomial to the
                                                                        //subtraction of this and otherPolynomial
        }                                                               //close for loop brace
        return differencePolynomial;                                    //return this polynomial
    }
}
// ------------------------------------operator*--------------------------------------------------------------
// Description: This overloaded method will return the product of the two polynomials. This methods does this by
//  first getting the largest array needed for the product of the two. Next it creates the Polynomial for the product.
// Lastly, in nested for loops it will multiply the first by each of the coefficients in the second poly and store it in
//  the sum of the two powers. Repeat for all coefficients in the this Polynomial. Then return the product Polynomial.
// ---------------------------------------------------------------------------------------------------------------------

Poly Poly::operator*(const Poly& otherPolynomial) const
{                                                               //method open brace
    int newArraySize = (arraySize +
            otherPolynomial.arraySize - 2);                     //create a new size to the arraySize -2
    Poly productPolynomial(0,newArraySize);                     //create a new Polynomial to the new array size
    for(int thisCurrentPower = 0;thisCurrentPower
                                 < arraySize;thisCurrentPower++)//loop for the length of the this Polynomial
    {                                                           //outer for loop brace
        for(int otherCurrentPower = 0; otherCurrentPower
                                       < otherPolynomial.arraySize;
                                            otherCurrentPower++)//loop for the length of the otherPolynomial
        {                                                       //inner for loop open brace
            productPolynomial.pointerToPolynomial[thisCurrentPower +
                    otherCurrentPower] += (pointerToPolynomial[thisCurrentPower] *
                    otherPolynomial.pointerToPolynomial[otherCurrentPower]);//at the array location that is equal to the
                                                                            //sum of the two powers, find the product of
                                                                            //the two coefficients and add it the array
                                                                            //location
        }                                                                   //close innerfor loop brace
    }                                                                       //close outer for loop brace
    return productPolynomial;
}
// ------------------------------------operator+=--------------------------------------------------------------
// Description: This overloaded method will add the two Polynomials to find a sum and then set the this Polynomial two
// the sum. It does this be using the operator+ to find the sum and the operator= to assign this to the sum.
// ---------------------------------------------------------------------------------------------------------------------
Poly& Poly::operator+=(const Poly& otherPolynomial)
{                                           //method open brace
    *this = (*this + otherPolynomial);      //the addition and assignment
    return* this;                           //return the polynomial
}                                           //method close brace
// ------------------------------------operator-=--------------------------------------------------------------
// Description: This overloaded method will subtract the two Polynomials to find the difference and then set the this
// Polynomial to the difference. It does this be using the operator- to find the difference and the operator= to assign
// this to the difference.
// ---------------------------------------------------------------------------------------------------------------------
Poly& Poly::operator-=(const Poly& otherPolynomial)
{                                       //method open brace
    *this = (*this - otherPolynomial);  //subtract the this and otherPolynomial and assign this to the difference
    return *this;                       //return differencePolynomial
}                                       //close method brace
// ------------------------------------operator*=--------------------------------------------------------------
// Description: This overloaded method will find the product of the two Polynomials and then set the this Polynomial to
// the product. It does this be using the operator* to find the product and the operator= to assign this to the product.
// ---------------------------------------------------------------------------------------------------------------------
Poly& Poly::operator*=(const Poly& otherPolynomial)
{                                       //method open brace
    *this = (*this * otherPolynomial);  //find the product of the two polynomials and assign this to that product
    return *this;                       //return the new this product
}                                       //close method brace