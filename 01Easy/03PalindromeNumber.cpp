#include <iostream>

using std::cout;
using std::cin;

bool isPalindrome(int x)
{
    int number = 0;
    while (x)
    {
        number *= 10 + (x % 10);
        x /= 10;
    }
    if (x == number) return true;
    return false;
}

int main()
{
    cout << isPalindrome(121) << '\n';
    return 0;
}