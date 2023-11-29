// This program is converted to C++
//  - changed to C++ io
//  - changed to one line comments
//  - changed defines of constants to const
//  - changed array to vector<>
//  - inline the sum function

#include <iostream>
#include <vector>

using namespace std;

const int N = 40;

// sums the n elements of vector d and stores value at p
template <class summable>
inline void sum(int n, vector<summable> d, summable& p = 0)
{
    for(int i = 0; i < n; ++i)
        p = p + d.at(i);
}

int main()
{
    double accum = 0.0;
    vector<double> data(N);     // initialize a vector of zeros
    for(int i = 0; i < N; ++i)  // put data in vector
        data.at(i) = i * 1.01;
    sum(N, data, accum);
    cout << "sum is " << accum << endl; 
    return 0;
}