#include <iostream>
#include <string>
#include <vector>

int shorterWordLenght(const std::string& word1, const std::string& word2)
{
    int lenght1 = word1.length(), lenght2 = word2.length();
    if (lenght1 < lenght2)
    {
        return lenght1;
    }
    else
    {
        return lenght2;
    }
}
void swap(std::string& nombre1, std::string& nombre2)
{
    std::string aux = nombre1;
    nombre1 = nombre2;
    nombre2 = aux;
}
bool compare(std::string& nombre1, std::string& nombre2)
{
    for (int i = 0;i < shorterWordLenght(nombre1, nombre2);i++)
    {
        if (nombre1.at(i) > nombre2.at(i))
        {
            swap(nombre1, nombre2);
            return false;
        }
    }
    return true;
}
void sort(std::vector<std::string>& list)
{
    for (int i = 0;i < list.size();i++)
    {
        
    }
}
int main()
{
    std::vector<std::string> nombres={
        "Mateo", "Lucas", "Leo", "Hugo", "Alejandro", "Daniel", "Manuel", "Pablo", "Álvaro", "Adrián"
    };
    
    //for(int i=0;i<nombres->capacity(), i++)
    std::cout << nombres.size() << std::endl;

    return 1;
}