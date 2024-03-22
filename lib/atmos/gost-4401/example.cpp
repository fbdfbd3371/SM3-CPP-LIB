#include "atmos-4401.hpp"

int main()
{
    CAtmos* atmos = CAtmos::getInstance();
    printf("%.6f\n", atmos->pressure(10000));
    system("pause");
}