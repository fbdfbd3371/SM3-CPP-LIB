#include <iostream>
#include "grav-flat.hpp"

int main()
{
    CGravAbstract* gravModel = new CGravFlat;
    std::cout << "FLAT Earth gravity model:" << std::endl;

    std::cout << "gX:\t"<<gravModel->getGX()<<std::endl;
    std::cout << "gY:\t"<<gravModel->getGY()<<std::endl;
    std::cout << "gZ:\t"<<gravModel->getGZ()<<std::endl;
    return 0;
}