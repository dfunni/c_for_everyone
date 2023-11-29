#include <iostream>
using namespace::std;

long long fact(int n) // long long is an extension to ANSI C
{
    long long f = 1;
    for(int i = 1; i <= n; i++) { // since i is decleared here it is scoped only for the for loop
        f *= i;
    }
    return f;
}

int main(void)
{
    cout << "This program uses some features not in C89\n";
    for (auto i = 0; i < 16; i++) {
        cout << "factorial of " << i << " is " << fact(i) << endl;
    }
    cout << "That's all folks!" << endl;
}