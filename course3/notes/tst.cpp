#include <iostream>
using namespace std;

int main()
{
    int i = 3; int j = 5;
    double x = 3.4; double y = 5.5;
    cout << i << " " << j << "\n";
    swap(i, j);
    cout << i << " " << j << "\n";
    cout << x << " " << y << "\n";  
    swap(x, y);
    cout << x << " " << y << "\n";
}

inline void swap(int& i, int& j)
{
    int temp = i;
    i = j;
    j = temp;
}

inline void swap(double& i, double& j)
{
    double temp = i;
    i = j;
    j = temp;
}