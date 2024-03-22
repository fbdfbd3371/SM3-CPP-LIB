#pragma once
#include <math.h>
#include <iostream>
#include <assert.h>

class CAtmos 
{
    static CAtmos* instance;

    const double Rz = 6356767.0;
    const double g0 = 9.80665;
    const double R = 287.05287;
    double height, HH, g, T, TM, He, B, Pe, P, ro, a;
    
    CAtmos() {}

    void getCoefficients(double height);
    
public:

    static CAtmos* getInstance();
    
    double geopotentialAltitude(double height);
    
    double H_to_h(double H);
    
    double gravityAcceleration(double height);
    
    double temperature(double height);
    
    double pressure(double height);
    
    double density(double height);

    double soundVelocity(double height);
};