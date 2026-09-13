#include <iostream>
#include <chrono>
using namespace std;
int abs(int a)
{
    if (a < 0)
    {
        a *= -1;
    }
    return a;
}
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
bool validate(int& a, int& b)
{
    a = abs(a);
    b = abs(b);
    if (b > a)//Asegurar que a>b por comodidad
    {
        swap(a, b);
    }
    if (a == b&&a==0) return false;//fallo-ambos cero
    
    return true;
}
int EuclidesMCD(int a, int b)
{
    if (!validate(a, b))
        return -1;
    if (b == 0) return a;
    int count = 0;
    int r= a % b;//primera division
    count++;
    while(r>0)
    {
        a = b;
        b = r;
        r = a % b;//una division
        count++;
    }
    return b;
}
int LoopMCD(int a, int b)
{
    if (!validate(a, b))
        return -1;
    if (b == 0) return a;
    int d = b;//la validacion hace que b sea el menor
    int count = 0;
    while(d>1)
    {
        bool condition1 = a % d == 0;//obligatorio 
        bool condition2 = b % d == 0;//si el primero es true
        count++;
        if (condition1) 
            count++; 
        if (condition1 && condition2)//2 divisiones
            return d;
        else
            d = d - 1;
    }
    return 1;
}
int main()
{
    int a[] = { 144,102334155,1048576,16,9,0,4 };
    int b[] = { 12,165580141,2097152,7,48,0,0 };
    int size = 7;
    //chrono::steady_clock::time_point start;
    //chrono::steady_clock::time_point end;
    //chrono::duration<double, milli> time;

    for (int i = 0;i < size;i++)
    {
        cout << "a:" << a[i] << ",b:" << b[i] << std::endl;
        auto start = chrono::high_resolution_clock::now();
        EuclidesMCD(a[i], b[i]);
        auto end = chrono::high_resolution_clock::now();
        auto time = end - start;
        cout << "Euclides: " << time.count() << "ms "<< std::endl;

        start = chrono::high_resolution_clock::now();
        LoopMCD(a[i], b[i]);
        end = chrono::high_resolution_clock::now();
        time = end - start;
        cout << "Loop: " << time.count() << "ms" << std::endl;

        cout << "Resultado: " << EuclidesMCD(a[i], b[i]) << std::endl;

        cout << "=====================================" << std::endl;
    }
    
    

    return 1;
}