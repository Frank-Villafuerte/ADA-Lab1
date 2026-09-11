#include <iostream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;
bool isAlphabetic(char character)
{
    if (!(character >= 65 && character <= 122) || (character >= 91 && character <= 96))
        return false;
    return true;
}
void Sort(vector<string>& words)
{
    int n = words.size();

    for (int i = 1; i < n; i++) {
        string actual= words[i];
        int j = i - 1;
        while (j >= 0 && words[j] > actual) {
            words[j + 1] = words[j]; 
            j--;
        }
        words[j + 1] = actual;
    }
}
void Split(vector<string>& words, string text)
{
    bool wordFinded=false;
    int beginIdx=0;
    for (int i = 0;i < text.length();i++)
    {
        if (wordFinded && !isAlphabetic(text.at(i)))
        {
            words.push_back(text.substr(beginIdx, i-beginIdx));
            wordFinded = false;
            //cout << beginIdx << "," << i << endl;
        }
        if (!wordFinded&&isAlphabetic(text.at(i)))
        {
            wordFinded = true;
            beginIdx = i;
        }
        

    }
}
bool SearchBrute(const std::string& text, const std::string& word)
{
    int m = word.length();
    int n = text.length();
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
            if (text.at(i + j) != word.at(j))
                break;
        if (j == m) return true; // encontrado
    }
    return false;
}
bool SearchList(vector<string> text,string word)
{
    int left = 0, right = text.size() - 1;
    while (left <= right)
    { // Key is in a[lo..hi] or not present.
        int mid = left + (right - left) / 2;
        if (word < text[mid]) right = mid - 1;
        else if (word > text[mid]) left = mid + 1;
        else return true;
    }
    return false;
}
int main()
{
    ///*
    string text = R"(Lorem ipsum dolor sit amet, consectetur adipiscing elit.Morbi id est vitae enim euismod mollis a et dolor.Nam at elit in risus ultricies facilisis quis eu lacus.Pellentesque sollicitudin libero ut tortor pharetra tincidunt.Etiam dolor ipsum, laoreet eu consequat eget, aliquet eget dolor.Vestibulum sed ex mollis sem imperdiet vestibulum sed eget diam.Praesent justo lectus, vulputate in mollis in, vehicula vestibulum nisl.In commodo sapien ut velit tincidunt, at rutrum ligula commodo.Pellentesque mollis enim tellus, a fermentum velit bibendum non.
        Sed mi dolor, ornare ac consectetur a, porttitor sed diam.Maecenas id dui nisl.Maecenas cursus porttitor orci, sed dignissim urna rhoncus sit amet.Donec at magna tellus.Etiam nec semper ex, vitae fermentum lorem.Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.Suspendisse ut cursus quam, et fringilla orci.Morbi laoreet velit sit amet ligula venenatis, sed vulputate orci suscipit.Donec et commodo sapien.Ut sed porta eros.Nulla facilisi.Nunc lacinia iaculis risus vitae viverra.Sed eget metus sem.In fringilla, sem vitae suscipit suscipit, purus ex efficitur diam, vel molestie libero enim ac ipsum.Mauris tincidunt nec neque non lacinia.Phasellus rhoncus consequat gravida.
        Fusce ut posuere lorem, eu dictum nisl.Nulla viverra quis enim id elementum.Aenean ut est in orci venenatis rhoncus.Donec posuere turpis sed neque auctor, id consequat ex congue.Sed venenatis placerat augue eu tincidunt.Integer feugiat ut dolor a condimentum.Maecenas venenatis fringilla tellus, id egestas nisi rhoncus quis.Nunc at dolor vel nulla viverra pellentesque quis quis sem.
        In maximus magna augue, vel ultrices velit ornare sit amet.Pellentesque placerat tincidunt nibh, eu vestibulum lorem.Mauris molestie convallis nibh.Curabitur sit amet justo risus.Etiam vel tortor in purus auctor facilisis eu eu neque.Duis mattis ex mollis dui egestas rutrum.Etiam tempus augue elit, a vehicula velit tincidunt vitae.Nulla porttitor leo lectus, at vehicula enim mattis non.Nullam feugiat odio id quam ultricies suscipit.Duis pharetra pretium tellus quis consequat.Pellentesque id ipsum imperdiet, euismod nunc eu, efficitur sem.Nullam lacinia sapien in molestie finibus.Quisque ut leo pulvinar, lacinia nulla et, placerat felis.Nam leo mi, hendrerit id imperdiet ut, ultricies hendrerit purus.Cras congue tellus viverra sagittis scelerisque.
        Proin pretium tellus sed ligula lobortis, at pharetra arcu dictum.Phasellus varius justo ut massa molestie interdum.Nunc dapibus mi sem, et maximus ligula rutrum eu.Curabitur odio diam, cursus vel molestie at, pellentesque id nibh.In pulvinar sem lectus, eu blandit ante dapibus et.Suspendisse ut rutrum purus.Suspendisse eu elementum augue.Sed porttitor consectetur est ac accumsan.Vivamus facilisis, nunc vitae dapibus dictum, est ante pretium tortor, et condimentum sem quam commodo est.Donec eget eros consequat dui aliquam interdum.Nunc aliquet fermentum urna vel aliquam.Fusce bibendum a neque in dapibus.Donec pharetra odio eget dui consectetur congue.Donec et est dapibus, placerat magna ut, malesuada est.In lobortis, ante vitae facilisis convallis, arcu erat euismod orci, ac vestibulum eros lorem non lectus.Maecenas eu turpis eu velit fringilla consectetur.)";

    //*/
 
    string word1 = "Lorem";
    string word2 = "elementum";
    string word3 = "dictum";
    vector<string> wordList;
    Split(wordList, text);//almacenar las palabras en lista
    Sort(wordList);//ordenar palabras

    chrono::steady_clock::time_point start;
    chrono::steady_clock::time_point end;
    chrono::duration<double, milli> time;
    cout << "Palabra:" << word1 << endl;
    start = chrono::high_resolution_clock::now();
    SearchList(wordList, word1);
    end = chrono::high_resolution_clock::now();
    time = end - start;
    cout << "List: " << time.count() << "ms " << std::endl;

    start = chrono::high_resolution_clock::now();
    SearchBrute(text, word1);
    end = chrono::high_resolution_clock::now();
    time = end - start;
    cout << "Brute: " << time.count() << "ms" << std::endl;
    cout << "=====================================" << std::endl;
    cout << "Palabra:" << word2 << endl;
    start = chrono::high_resolution_clock::now();
    SearchList(wordList, word2);
    end = chrono::high_resolution_clock::now();
    time = end - start;
    cout << "List: " << time.count() << "ms " << std::endl;

    start = chrono::high_resolution_clock::now();
    SearchBrute(text, word2);
    end = chrono::high_resolution_clock::now();
    time = end - start;
    cout << "Brute: " << time.count() << "ms" << std::endl;
    cout << "=====================================" << std::endl;
    cout << "Palabra:" << word3 << endl;
    start = chrono::high_resolution_clock::now();
    SearchList(wordList, word3);
    end = chrono::high_resolution_clock::now();
    time = end - start;
    cout << "List: " << time.count() << "ms " << std::endl;

    start = chrono::high_resolution_clock::now();
    SearchBrute(text, word3);
    end = chrono::high_resolution_clock::now();
    time = end - start;
    cout << "Brute: " << time.count() << "ms" << std::endl;

    

    return 1;
}