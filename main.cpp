#include "DynamicArray.h"
#include <iostream>
using namespace std;

int main() {
    cout << "===== TASK 1 =====\n";
    DynamicArray a(5);
    a.set(0, 10); a.set(1, -20); a.set(2, 30); a.set(3, 40); a.set(4, 50);
    cout << "a = "; a.print();
    cout << "a.get(2) = " << a.get(2) << endl;
    a.set(10, 5);
    a.set(0, 200);

    cout << "\n===== TASK 2 =====\n";
    DynamicArray b = a;
    b.set(0, 99);
    cout << "a = "; a.print();
    cout << "b = "; b.print();

    cout << "\n===== TASK 3 =====\n";
    a.append(60);
    a.append(70);
    a.append(200);
    cout << "a sau append = "; a.print();

    cout << "\n===== TASK 4 =====\n";
    DynamicArray x(3), y(2);
    x.set(0, 1); x.set(1, 2); x.set(2, 3);
    y.set(0, 10); y.set(1, 20);
    cout << "x = "; x.print();
    cout << "y = "; y.print();
    x.add(y);
    cout << "x.add(y) = "; x.print();
    x.subtract(y);
    cout << "x.subtract(y) = "; x.print();

    return 0;
}