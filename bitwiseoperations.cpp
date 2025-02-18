#include <iostream>
using namespace std;

int main()
{
    int a = 4, b = 8;
    
    cout << "The Bitwise AND operation of 4 and 8 is" << (a & b) << endl; // 0
    cout << "The Bitwise OR operation of 4 and 8 is" << (a | b) << endl;  // 12
    cout << "The Bitwise XOR operation of 4 and 8 is" << (a ^ b) << endl; // 12

    return 0;
}