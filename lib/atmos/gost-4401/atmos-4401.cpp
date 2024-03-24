#include "atmos-4401.hpp"

CAtmos4401* CAtmos4401::instance = nullptr;

/**
 * @brief 
 * @warning МЕТОД НЕ РЕАЛИЗОВАН. ДОЛЖЕН ВЫЗЫВАТЬ МЕТОД КЛАССА MISSLE ДЛЯ ПОЛУЧЕНИЯ АКТУАЛЬНОЙ ВЫСОТЫ.
 */
double CAtmos4401::getCrntHeight()
{
    ///@todo Сделать вызов метода из основного класса missle
    return 1000;
}

void CAtmos4401::getCoefficients()
    {
        ///@todo change assert to smth
        if (isnan(getCrntHeight())) {
            printf("Atmos input error: height is NaN\n");
            assert(!isnan(getCrntHeight()));
        }
        double geoph = getGeopotentialHeight();       
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
        else if (getCrntHeight() < 120000.0)
        {
            B = 0.011;
            T = 212.0;
            He = 102450.0;
            Pe = 1.230968e-4;
        }
        else 
        {
            std::cout << "Atmos height error\t";
            printf("h: %.6f\n", getCrntHeight());
        }
    }

CAtmos4401* CAtmos4401::getInstance()
{
    if(instance==nullptr)
    {
        instance = new CAtmos4401;
        return instance;
    }

    return instance;
};

double CAtmos4401::getGeopotentialHeight()
{
    HH = Rz * getCrntHeight() / (Rz + getCrntHeight());
    return HH;
}

double CAtmos4401::H_to_h(double H) 
{
    return H * Rz / (Rz - H);
}

double CAtmos4401::gravityAcceleration()
{
    g = g0 * pow(Rz / (Rz + getCrntHeight()), 2.0);
    return g;
}

double CAtmos4401::getTemperature()
{
    getCoefficients();        
    TM = T + B * (getGeopotentialHeight() - He);
    if (getCrntHeight() < 97000.0) {
        TM *= ((getCrntHeight() < 94000.0) ? 28.964420 : 
        (28.82 + 0.158 * pow(1 - 7.5e-8 * pow(getCrntHeight() - 94000.0, 2.0), 0.5) - 2.479e-4 * pow(97000.0 - getCrntHeight(), 0.5))) / 28.964420;
    }
    else if (getCrntHeight() < 120000.0) {
        TM *= ((getCrntHeight() < 97500.0) ? 28.91007386 - (getCrntHeight() - 97000.0) * 0.00012 : 
        28.85007386-0.0001511 * (getCrntHeight() - 97500.0)) / 28.964420;
    }    
    return TM;
}

double CAtmos4401::getPressure()
{
        getCoefficients();
        if (B != 0.0)
        {
            P = Pe / pow(1 + B * (getGeopotentialHeight() - He) / T, g0 / (B * R));
        }
        else
        {
            P = Pe / pow(10.0, 0.434294 * g0 / R / getTemperature() * (getGeopotentialHeight() - He));
        }
        P *= 101325.0 / 760.0;
        return P;
    }

double CAtmos4401::getDensity()
{
    ro = getPressure() / (R * getTemperature());
    return ro;
}

double CAtmos4401::getSoundVelocity()
{
    a = 20.046796 * sqrt(getTemperature());
    return a;
}