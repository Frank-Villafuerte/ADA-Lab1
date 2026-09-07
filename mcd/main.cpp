#include <iostream>
int min(const int& a, const int& b)
{
    if (a < b) return a;
    else return b;
}
void swap(int& a, int& b)
{
    int aux = a;
    a = b;
    b = aux;
}
int EuclidesMCD(int a, int b)
{
    if (b > a)
    {
        swap(a, b);
    }
    int count = 0;
    int r= a % b;
    while(r>0)
    {
        a = b;
        b = r;
        r = a % b;//una division
        count++;
    }
    std::cout << "Divisiones Euclides: " << count<<std::endl;
    return b;
}
int LoopMCD(int a, int b)
{
    int d = min(a, b);
    int count = 0;
    while(d>1)
    {
        bool condition1 = a % d == 0;//obligatorio 
        bool condition2 = b % d == 0;//si el primero es true

        count++;
        if (condition1)
        {
            count++;
        }
        if (condition1 && condition2)//2 divisiones
        {
            std::cout << "Divisiones Loop:" <<count<< std::endl;
            return d;
        }
        else
        {
            d = d - 1;
        }
    }
    std::cout << "Divisiones Loop:" << count << std::endl;
    return 1;
}
int main()
{
    int a = 1134903170, b = 1836311903;
    std::cout << a << "," << b << std::endl;
    std::cout << EuclidesMCD(a, b) << std::endl;
    std::cout << LoopMCD(a, b) << std::endl;
  
    

    return 1;
}