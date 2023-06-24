#pragma once

/*  TODO LIST
        1. add SFINAE to abs (isArithmetic)
        2. search about sqrt func. how to improve the speed
        3. ERR CHECKS x != 0 -> toRad, toDeg, sqrt
        4. add invSqrt (Quake3)
        5. add Trigonometrics
*/

namespace Math {
    #define PI static_cast<double>(3.141592653589793);

    #define SQUARE(X) ((X) * (X))

    template <typename T> constexpr T abs(const T& _val) { return (_val < 0 ? -_val : _val); }
    template <typename T> constexpr double toRad(const double& _deg) {
        constexpr double RAD = 0.017453292519943;

        return RAD * _deg;
    }
    template <typename T> constexpr double toDeg(const double& _rad) {
        constexpr double DEG = 57.295779513082325;

        return DEG * _rad;
    }

    constexpr double sqrt(const double& _x) {     // Babylonian method
        double estimate = _x;

        while (true) {
            double next_estimate = 0.5 * (estimate + _x / estimate);

            if (abs(next_estimate - estimate) < 0.0001)
                break;

            estimate = next_estimate;
        }

        return estimate;
    }
}