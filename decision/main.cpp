#include <iostream>
using namespace std;

int Digits(int n)
{
    int digits=0;
    while (n > 9)//extraer cantidad de cifras -1
    {
        n /= 10;
        digits++;
    }
    
    return digits + 1;
}
int pow(int base, int exp)
{
    int out = 1;
    for (int i = 0;i < exp;i++)
    {
        out *= base;
    }
    return out;
}
bool IsPalindrome(int num)
{
    int pow10 = Digits(num)-1;
    int count = 0;
    while (pow10 > 0)
    {
        int num1 = num / pow(10, pow10);
        int num2 = num % 10;
        if (num1 != num2)   return false;
        num = (num - num1 * pow(10, pow10)) / 10;
        pow10 -= 2;
    }
    return true;
}
int main()
{
    
    int num = 2314132;
   
    //std::cout << "pow: " << pow(5, 2) << std::endl;
    if (IsPalindrome(num))
    {
        std::cout <<num<< " es Palindromo"  << std::endl;
    }
    else
    {
        std::cout << num << " no es Palindromo" << std::endl;
    }
    

    return 1;
}