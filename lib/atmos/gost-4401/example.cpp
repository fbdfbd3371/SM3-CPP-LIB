#include "atmos-4401.hpp"

int main()
{
    CAtmosAbstract* atmos = CAtmos4401::getInstance();
    printf("%.6f\n", atmos->getDensity());
    printf("%.6f\n", atmos->getPressure());
    printf("%.6f\n", atmos->getSoundVelocity());
    printf("%.6f\n", atmos->getTemperature());
    system("pause");
}