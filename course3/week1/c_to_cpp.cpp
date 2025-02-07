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

// sums the elements of vector d and stores value at p
template <class summable>
inline void sum(const vector<summable> d, summable& acc = 0)
{
    for(int i = 0; i < d.size(); ++i)
        acc += d.at(i);
}

int main()
{
    int accum = 0;
    vector<int> data(N);        // initialize a vector of zeros
    for(int i = 0; i < N; ++i)  // put data in vector
        data.at(i) = i;
    sum(data, accum);
    cout << "sum is " << accum << endl; 
    return 0;
}