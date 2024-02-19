#include "Parsers.h"
#include <iostream>

int main()
{
    std::vector<std::string> files = getFileNames();
    for (int i = 0; i < files.size(); i++) {
        std::cout << files[i] << ":\n";
        std::vector<double> values = getValuesFromFile(files[i]);
        for (int j = 0; j < values.size(); j++) {
            std::cout << values[j] << "\t";
        }
        std::cout << "\n\n";
    }
    system("pause");
}