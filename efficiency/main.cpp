#include <iostream>

int AddUntilN(const int& n)
{
    int out = 0;
    int count = 0;
    for (int i = 1;i <= n;i++)
    {
        out += i;//suma + asignacion= 2 pasos
        count += 2;
    }
    std::cout << "Sumatoria clasica->N=" << n << " Pasos=" << count << std::endl;
    return out;
}
int main()
{
    int n = 100;

    int loop = AddUntilN(n);

    int add = n * (n + 1) / 2;//suma+division+producto+asignacion= 4 pasos

    std::cout << "Sumatoria gauss:" << add << ", Iterativa=" << loop << std::endl;
    return 1;
}