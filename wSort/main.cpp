#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
void Sort(vector<string>& words)
{
    int n = words.size();

    for (int i = 1; i < n; i++) {
        string actual = words[i];
        int j = i - 1;
        while (j >= 0 && words[j] > actual) {
            words[j + 1] = words[j];
            j--;
        }
        words[j + 1] = actual;
    }
}

int main()
{
    std::vector<std::string> list1={
        "Maria","Juan","Jose","Francisco","Pedro","Francisca","Antonio","Manuel","Ana","Joseph","Juana","Miguel","Josefa","Antonia","Joan","Catalina","Martin","Teresa","Rosa","Manuela","Domingo","Isabel","Josepha","Ramon","Diego","Andres","Magdalena","Pere","Anna","Ysabel","Luis","Margarita","Theresa","Margarida","Joaquin","Josef","Vicente","Angela","Jaume","Alonso","Salvador","Fernando","Dolores","Jaime","Agustin","Tomas","Sebastian","Carmen","Antoni","Gregorio","Miquel","Mariana","Cathalina","Lorenzo","Luisa","Mariano","Joana","Santiago","Paula","Gabriel","Nicolas","Bartolome","Rafael","Bernardo","Esteban","Pablo","Felipe","Carlos","Julian","Lucia","Vicenta","Alfonso","Ramona","Angel","Agustina","Thomas","Josep","Joaquina","Benito","Juliana","Petra","Leonor","Clara","Blas","Catharina","Madalena","Narciso","Felix","Simon","Gaspar","Agueda","Francesch","Gregoria","Pau","Marianna","Isidro","Beatriz","Micaela","Rita","Geronimo"
    };
    std::vector<std::string> list2 = {
        "Maria","Juan","Jose","Francisco","Pedro","Francisca","Antonio","Manuel","Ana","Joseph","Juana","Miguel","Josefa","Antonia","Joan","Catalina","Martin","Teresa","Rosa","Manuela","Domingo","Isabel","Josepha","Ramon","Diego","Andres","Magdalena","Pere","Anna","Ysabel","Luis","Margarita","Theresa","Margarida","Joaquin","Josef","Vicente","Angela","Jaume","Alonso","Salvador","Fernando","Dolores","Jaime","Agustin","Tomas","Sebastian","Carmen","Antoni","Gregorio","Miquel","Mariana","Cathalina","Lorenzo","Luisa","Mariano","Joana","Santiago","Paula","Gabriel","Nicolas","Bartolome","Rafael","Bernardo","Esteban","Pablo","Felipe","Carlos","Julian","Lucia","Vicenta","Alfonso","Ramona","Angel","Agustina","Thomas","Josep","Joaquina","Benito","Juliana","Petra","Leonor","Clara","Blas","Catharina","Madalena","Narciso","Felix","Simon","Gaspar","Agueda","Francesch","Gregoria","Pau","Marianna","Isidro","Beatriz","Micaela","Rita","Geronimo"
    };
   
    
    //chrono::steady_clock::time_point start;
    //chrono::steady_clock::time_point end;
    //chrono::duration<double, milli> time;

    auto start = chrono::high_resolution_clock::now();
    Sort(list1);
    auto end = chrono::high_resolution_clock::now();
    auto time = end - start;
    cout << "Insertion Sort: " << time.count() << "ms" << std::endl;
    cout << "=====================================" << std::endl;
    start = chrono::high_resolution_clock::now();
    sort(list2.begin(), list2.end());
    end = chrono::high_resolution_clock::now();
    time = end - start;
    cout << "Sort STD: " << time.count() << "ms" << std::endl;
    cout << "=====================================" << std::endl;


    /*for (int i = 0;i < nombres.size();i++)
    {
        cout << nombres[i]<<", ";
    }*/
    //for(int i=0;i<nombres->capacity(), i++)
    //std::cout << nombres.size() << std::endl;

    return 1;
}