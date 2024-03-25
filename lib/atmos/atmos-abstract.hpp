#pragma once

/**
 * @brief Абстрактный класс атмосферы. Реализован в виде синглетона.
 *
 */
class CAtmosAbstract
{
private:
    virtual double getCrntHeight() = 0;

public:
    /**
     * @brief Давление, [Па]
     */
    virtual double getPressure() = 0;

    /**
     * @brief Плотность, [кг/м^3]
     */
    virtual double getDensity() = 0;

    /**
     * @brief Температура, [К]
     */
    virtual double getTemperature() = 0;

    /**
     * @brief Скорость звука, [м/с]
     */
    virtual double getSoundVelocity() = 0;
};