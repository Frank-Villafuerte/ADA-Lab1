#include <iostream>
#include <string>
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
    int pow10 = 0;
    int copy = num;
    while (copy > 9)//extraer cantidad de cifras -1
    {
        copy /= 10;
        pow10++;
    }
    int count = 0;
    while (pow10 > 0)
    {
        int num1 = num / pow(10, pow10);
        int num2 = num % 10;
        //std::cout << "Potencia: " << pow10 << std::endl;
        //std::cout << "Num1: " << num1 << "Num2: " << num2 << std::endl;
        if (num1 != num2)
        {
            count++;//comparacion desfavorable
            std::cout << "Comparaciones: " << count << std::endl;
            return false;
        }
        else
        {
            count++;//comparacion exitosa
        }
        num = (num - num1 * pow(10, pow10)) / 10;
        pow10 -= 2;
    }
   
    std::cout << "Comparaciones: " << count << std::endl;
    return true;
}
int main()
{
    
    int num = 12384321;
   
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