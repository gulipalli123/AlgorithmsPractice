// AmazonPractice.cpp : Defines the entry point for the application.
//

#include "MinStack.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    SpecialStack s;
    /*
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.getMin() << endl;
    s.push(5);
    cout << s.getMin();*/

    std::vector<int> arr{ 3, 2, 6, 1, 8, 5, 5, 5, 5 };

    for (const auto& a : arr) {
        s.push(a);
        std::cout << "pushed element: " << a << "\n";
        std::cout << "min element: " << s.getMin() << "\n";
    }

    std::cout << "----------------------------" << "\n";

    for (int i = 0; i < arr.size(); i++) {
        std::cout << "poped element: " << s.pop() << "\n";
        std::cout << "min element: " << s.getMin() << "\n";
    }
    return 0;
}
