#include <iostream>

int AddUntilN(const int& n)
{
    int out = 0;
    int count = 0;
    for (int i = 1;i <= n;i++)
    {
        out += i;//suma + asignacion= 2 pasos
        count += 1;//no contaremos la asignación
    }
    std::cout << "Sumatoria clasica->N=" << n << " Pasos=" << count << std::endl;
    return out;
}
int main()
{
    int n[] = {100,450,1000,50000,2500000};
    int size = 5;

    //int n = 100;
    for (int i = 0;i < size;i++)
    {
        int loop = AddUntilN(n[i]);

        int add = n[i] * (n[i] + 1) / 2;//suma+division+producto+asignacion= 4 pasos
        std::cout << "Sumatoria Gauss->N=" << n[i] << " Pasos=" << 3 << std::endl;
        std::cout << "Resultado-> gauss:" << add << ", Iterativa=" << loop << std::endl;

        std::cout << "======================================================" << std::endl;
    }
    
    return 1;
}