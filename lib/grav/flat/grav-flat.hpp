#pragma once
#include "grav-abstract.hpp"
//#include "atmos-4401.hpp"

class CGravFlat: public CGravAbstract
{
private:

public:
    double getGX() override;
    double getGY() override;
    double getGZ() override;
};