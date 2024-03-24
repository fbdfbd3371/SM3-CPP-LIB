#pragma once
#include <math.h>
#include <iostream>
#include <assert.h>
#include "atmos-abstract.hpp"

class CAtmos4401: public CAtmosAbstract
{
    static CAtmos4401* instance;

    const double Rz = 6356767.0;
    const double g0 = 9.80665;
    const double R = 287.05287;
    double HH, g, T, TM, He, B, Pe, P, ro, a;
    
    CAtmos4401() {}

    void getCoefficients();

    double getCrntHeight() override;
    
public:

    static CAtmos4401* getInstance();
    
    double getGeopotentialHeight() override;
    
    double H_to_h(double H);
    
    double gravityAcceleration();
    
    double getTemperature() override;
    
    double getPressure() override;
    
    double getDensity() override;

    double getSoundVelocity() override;
};