#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream ifs("test.cpp");
    char str[256];
    if (ifs.fail())
    {
        std::cerr << "失敗" << std::endl;
        return -1;
    }
    while (ifs.getline(str, 256 - 1))
    {
        std::cout << "[" << str << "]" << std::endl;
    }
    return 0;
}