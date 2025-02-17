#include <iostream>
using namespace std;

int Binarytodecimal(int BinaryNumber)
{
    int rem;
    int ans = 0; // deimal Number
    int pos = 1; // 2^0 to print backwords

    while (BinaryNumber > 0)
    {
        rem = BinaryNumber % 10; // 110
        BinaryNumber /= 10;
        ans = ans + (rem * pos);
        pos *= 2;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter a Number: ";
    cin >> n;

    cout << n << " in Deimal number is " << Binarytodecimal(n) << endl;

    return 0;
}