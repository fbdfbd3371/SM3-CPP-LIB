#pragma once

class CGravAbstract
{
public:
    /**
     * @brief В проекции на Ox стартовой системы координат
     */
    virtual double getGX() = 0;

    /**
     * @brief В проекции на Oy стартовой системы координат
     */
    virtual double getGY() = 0;

    /**
     * @brief В проекции на Oz стартовой системы координат
     */
    virtual double getGZ() = 0;
};