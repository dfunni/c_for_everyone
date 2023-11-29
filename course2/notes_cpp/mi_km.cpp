// could use stdio.h instead but not usually used in C++
#include <iostream> 

// can subsequently omit std:: from lib functinos like cout and cin
using namespace::std;

// const means identifier cannot have its value changed in this program
const double m_to_k = 1.609;

// inline keyword tells compiler to optimize the function by inserting code segment into places it is used to save on function call
// intended to replace macros with optimized functions
// compilers usually optimize this anyway so it is usually unnecessary
inline double convert(int mi) {return (mi * m_to_k);} 


int main(void)
{
    int miles = 1;

    while (miles != 0) {
        cout << "Input distance in miles or 0 to terminate: ";
        cin >> miles;
        cout << "\nDistance is " << convert(miles) << " km." << endl;
    }
    cout << endl;
}