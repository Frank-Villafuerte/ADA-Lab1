#include <iostream>
#include <string>

bool WordExist(const std::string& text, const std::string& word)
{
    int wordIdx = 0;
    //int textIdx = 0;
    for (int i = 0;i < text.length()-word.length()+1;i++)
    {
        while (word.at(wordIdx) == text.at(i + wordIdx))
        {
            wordIdx++;
            if (wordIdx == word.length() - 1)
            {
                return true;
            }
        }
            wordIdx = 0;
    }
    //char* charlist=nullptr;
    //std::string test = "xd a b";
    //SplitText(test,charlist);
    //int size = test.length();
    //std::cout << *(charlist+1) << std::endl;
    //char characters[] = {'a'};
    return false;
}
int main()
{
    ///*
    std::string text = R"(Lorem ipsum dolor sit amet, consectetur adipiscing elit.Morbi id est vitae enim euismod mollis a et dolor.Nam at elit in risus ultricies facilisis quis eu lacus.Pellentesque sollicitudin libero ut tortor pharetra tincidunt.Etiam dolor ipsum, laoreet eu consequat eget, aliquet eget dolor.Vestibulum sed ex mollis sem imperdiet vestibulum sed eget diam.Praesent justo lectus, vulputate in mollis in, vehicula vestibulum nisl.In commodo sapien ut velit tincidunt, at rutrum ligula commodo.Pellentesque mollis enim tellus, a fermentum velit bibendum non.
        Sed mi dolor, ornare ac consectetur a, porttitor sed diam.Maecenas id dui nisl.Maecenas cursus porttitor orci, sed dignissim urna rhoncus sit amet.Donec at magna tellus.Etiam nec semper ex, vitae fermentum lorem.Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.Suspendisse ut cursus quam, et fringilla orci.Morbi laoreet velit sit amet ligula venenatis, sed vulputate orci suscipit.Donec et commodo sapien.Ut sed porta eros.Nulla facilisi.Nunc lacinia iaculis risus vitae viverra.Sed eget metus sem.In fringilla, sem vitae suscipit suscipit, purus ex efficitur diam, vel molestie libero enim ac ipsum.Mauris tincidunt nec neque non lacinia.Phasellus rhoncus consequat gravida.
        Fusce ut posuere lorem, eu dictum nisl.Nulla viverra quis enim id elementum.Aenean ut est in orci venenatis rhoncus.Donec posuere turpis sed neque auctor, id consequat ex congue.Sed venenatis placerat augue eu tincidunt.Integer feugiat ut dolor a condimentum.Maecenas venenatis fringilla tellus, id egestas nisi rhoncus quis.Nunc at dolor vel nulla viverra pellentesque quis quis sem.
        In maximus magna augue, vel ultrices velit ornare sit amet.Pellentesque placerat tincidunt nibh, eu vestibulum lorem.Mauris molestie convallis nibh.Curabitur sit amet justo risus.Etiam vel tortor in purus auctor facilisis eu eu neque.Duis mattis ex mollis dui egestas rutrum.Etiam tempus augue elit, a vehicula velit tincidunt vitae.Nulla porttitor leo lectus, at vehicula enim mattis non.Nullam feugiat odio id quam ultricies suscipit.Duis pharetra pretium tellus quis consequat.Pellentesque id ipsum imperdiet, euismod nunc eu, efficitur sem.Nullam lacinia sapien in molestie finibus.Quisque ut leo pulvinar, lacinia nulla et, placerat felis.Nam leo mi, hendrerit id imperdiet ut, ultricies hendrerit purus.Cras congue tellus viverra sagittis scelerisque.
        Proin pretium tellus sed ligula lobortis, at pharetra arcu dictum.Phasellus varius justo ut massa molestie interdum.Nunc dapibus mi sem, et maximus ligula rutrum eu.Curabitur odio diam, cursus vel molestie at, pellentesque id nibh.In pulvinar sem lectus, eu blandit ante dapibus et.Suspendisse ut rutrum purus.Suspendisse eu elementum augue.Sed porttitor consectetur est ac accumsan.Vivamus facilisis, nunc vitae dapibus dictum, est ante pretium tortor, et condimentum sem quam commodo est.Donec eget eros consequat dui aliquam interdum.Nunc aliquet fermentum urna vel aliquam.Fusce bibendum a neque in dapibus.Donec pharetra odio eget dui consectetur congue.Donec et est dapibus, placerat magna ut, malesuada est.In lobortis, ante vitae facilisis convallis, arcu erat euismod orci, ac vestibulum eros lorem non lectus.Maecenas eu turpis eu velit fringilla consectetur.)";
    //*/
    //std::string text = "sasamfñ asdkalñsfa sflañ v al";
    std::string word = "tetur";

    if (WordExist(text, word))
    {
        std::cout << "La palabra '"<<word<<"' existe" << std::endl;
    }
    else
    {
        std::cout << "La palabra '" << word << "' no existe" << std::endl;
    }

    

    return 1;
}