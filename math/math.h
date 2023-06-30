#pragma once

/*  TODO LIST
        1. ERR CHECKS x != 0 -> sqrt
        2. add Trigonometrics
*/

#include "../typeTraits/isType.h"
#include "../typeTraits/typeCondition.h"

namespace Math {
    constexpr float PI = 3.141592;
    constexpr float E = 2.718282;

    template <typename T, typename = enableIF<isArithmetic<T>>> constexpr T abs(const T& _val) {
        if constexpr (isFloat<T>) {
            T result = _val;

            if constexpr (isSame<T, float>)
                *((unsigned int*)&result) &= 0x7FFFFFFF;

            else if constexpr (isSame<T, double>)
                *((unsigned long long*)&result) &= 0x7FFFFFFFFFFFFFFF;

            else {
                // long double
            }

            return result;
        }

        else
            return (_val < 0 ? -_val : _val);
    }
    template <typename T> constexpr T square(const T& _val) { return _val * _val; }

    template <typename T> constexpr float toRad(const float& _deg) { return _deg * 0.0174533; }   // PI / 180 = 0.017453292519943
    template <typename T> constexpr float toDeg(const float& _rad) { return _rad * 57.295779; }  // 180 / PI = 57.295779513082325

    float sqrt(const float& _x, const float& precision = 0.0001f) {   // Babylonian method
        double estimate = _x;

        while (true) {
            double next_estimate = 0.5 * (estimate + _x / estimate);

            if (abs(next_estimate - estimate) < precision)
                break;

            estimate = next_estimate;
        }

        return estimate;
    }
    float invSqrt(const float& _x) { return 1 / sqrt(_x); }
}