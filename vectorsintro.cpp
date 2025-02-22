#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> vec;
    // In this code we will see how the capacity of vector is increased when we add elements to it.
    vec.push_back(10);
    cout << "size of the vector: " << vec.size() << endl;
    cout << "Capacity of vector: " << vec.capacity() << "\n"
         << endl;

    vec.push_back(20);
    cout << "size of the vector: " << vec.size() << endl;
    cout << "Capacity of vector: " << vec.capacity() << "\n"
         << endl;

    vec.push_back(30);
    cout << "size of the vector: " << vec.size() << endl;
    cout << "Capacity of vector: " << vec.capacity() << "\n"
         << endl;

    vec.push_back(40);
    cout << "size of the vector: " << vec.size() << endl;
    cout << "Capacity of vector: " << vec.capacity() << "\n"
         << endl;

    vec.push_back(50);
    cout << "size of the vector: " << vec.size() << endl;
    cout << "Capacity of vector: " << vec.capacity() << "\n"
         << endl;

    vec.push_back(60);
    cout << "size of the vector: " << vec.size() << endl;
    cout << "Capacity of vector: " << vec.capacity() << "\n"
         << endl;

    for (int val : vec)
    {

        cout << val << endl;
    }

    return 0;
}