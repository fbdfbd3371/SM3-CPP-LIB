#include "atmos-4401.hpp"

CAtmos* CAtmos::instance = nullptr;

void CAtmos::getCoefficients(double height)
    {
        ///@todo change assert to smth
        if (isnan(height)) {
            printf("Atmos input error: height is NaN\n");
            assert(!isnan(height));
        }
        double geoph = geopotentialAltitude(height);       
        if ((geoph > -2000.0) && (geoph < 0.0))
        {
            B = -0.0065;
            T = 301.15;
            He = -2000.0;
            Pe = 9.58382e+2;
        }
        else if (geoph < 11000.0)
        {
            B = -0.0065;
            T = 288.15;
            He = 0.0;
            Pe = 760.0;
        }
        else if (geoph < 20000.0)
        {
            B = 0.0;
            T = 216.65;
            He = 11000.0;
            Pe = 1.69754e+2;
        }
        else if (geoph < 32000.0)
        {
            B = 0.001;
            T = 216.65;
            He = 20000.0;
            Pe = 4.10649e+1;
        }
        else if (geoph < 47000.0)
        {
            B = 0.0028;
            T = 228.65;
            He = 32000.0;
            Pe = 6.51064;
        }
        else if (geoph < 51000.0)
        {
            B = 0.0;
            T = 270.65;
            He = 47000.0;
            Pe = 8.31860e-1;
        }
        else if (geoph < 71000.0)
        {
            B = -0.0028;
            T = 270.65;
            He = 51000.0;
            Pe = 5.02080e-1;
        }
        else if (geoph < 85000.0)
        {
            B = -0.0020;
            T = 214.65;
            He = 71000.0;
            Pe = 2.96753e-2;
        }
        else if (geoph < 94000.0)
        {
            B = 0.0;
            T = 186.65;
            He = 85000.0;
            Pe = 2.725787e-3;
        }
        else if (geoph < 102450.0)
        {
            B = 0.003;
            T = 186.65;
            He = 94000.0;
            Pe = 5.249022e-4;
        }
        else if (height < 120000.0)
        {
            B = 0.011;
            T = 212.0;
            He = 102450.0;
            Pe = 1.230968e-4;
        }
        else 
        {
            std::cout << "Atmos height error\t";
            printf("h: %.6f\n", height);
        }
    }

CAtmos* CAtmos::getInstance()
{
    if(instance==nullptr)
    {
        instance = new CAtmos;
        return instance;
    }

    return instance;
};

double CAtmos::geopotentialAltitude(double height)
{
    HH = Rz * height / (Rz + height);
    return HH;
}

double CAtmos::H_to_h(double H) 
{
    return H * Rz / (Rz - H);
}

double CAtmos::gravityAcceleration(double height)
{
    g = g0 * pow(Rz / (Rz + height), 2.0);
    return g;
}

double CAtmos::temperature(double height)
{
    getCoefficients(height);        
    TM = T + B * (geopotentialAltitude(height) - He);
    if (height < 97000.0) {
        TM *= ((height < 94000.0) ? 28.964420 : (28.82 + 0.158 * pow(1 - 7.5e-8 * pow(height - 94000.0, 2.0), 0.5) - 2.479e-4 * pow(97000.0 - height, 0.5))) / 28.964420;
    }
    else if (height < 120000.0) {
        TM *= ((height < 97500.0) ? 28.91007386 - (height - 97000.0) * 0.00012 : 28.85007386-0.0001511 * (height - 97500.0)) / 28.964420;
    }    
    return TM;
}

double CAtmos::pressure(double height)
{
        getCoefficients(height);
        if (B != 0.0)
        {
            P = Pe / pow(1 + B * (geopotentialAltitude(height) - He) / T, g0 / (B * R));
        }
        else
        {
            P = Pe / pow(10.0, 0.434294 * g0 / R / temperature(height) * (geopotentialAltitude(height) - He));
        }
        P *= 101325.0 / 760.0;
        return P;
    }

double CAtmos::density(double height)
{
    ro = pressure(height) / (R * temperature(height));
    return ro;
}

double CAtmos::soundVelocity(double height)
{
    a = 20.046796 * sqrt(temperature(height));
    return a;
}