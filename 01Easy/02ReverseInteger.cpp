#include <iostream>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using namespace std::chrono;


int reverse(int x)
{
    /*
        Let x = 123
            123 > 0 - true
                number = 0 * 10 + 123 % 10 = 0 + 3 = 3
                x = 12
            23 > 0 - true
                number = 3 * 10 + 12 % 10 = 30 + 2 = 32
                x = 1
            1 > 0 - true
                number = 32 * 10 + 1 % 10 = 320 + 1 = 321
                x = 0
            0 > 0 - false
    */
    int number = 0;
    while (x) // while (x != 0)
    {
        number = number * 10 + x % 10;
        x /= 10;
    }
    
    return number > INT_MAX || number < INT_MIN ? 0 : number;
} // 32 bytes

int main()
{
    int number = -123;
    
    auto start = high_resolution_clock::now();
    int reverseNumber = reverse(number);
    auto end = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Number: " << number << "\tReversed Number: " << reverseNumber << '\n';
    cout << "Time taken: " << duration.count() << "ms" << endl;
    return 0;
}