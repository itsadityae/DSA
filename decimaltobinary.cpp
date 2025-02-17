#include <iostream>
using namespace std;

int decimal_binary(int decimalnumber)
{
    int rem;
    int ans = 0; // Binary Number 
    int pos = 1; // 10^0 to print backwords

    while (decimalnumber > 0)
    {
        rem = decimalnumber % 2;
        decimalnumber /= 2;

        ans = ans + (rem * pos);
        pos *= 10;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter a Number: ";
    cin >> n;

    cout << n << "in binary number is " << decimal_binary(n) << endl;

    return 0;
}