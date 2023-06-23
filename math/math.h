#pragma once

/*  TODO LIST
        1. add SFINAE to abs (isArithmetic)
        2. search about sqrt func. how to improve the speed
*/

namespace Math {
    #define SQUARE(X) ((X) * (X))

    template <typename T> T abs(const T& _val) { return (_val < 0 ? -_val : _val); }

    double sqrt(double x) {     // Babylonian method
        double estimate = x;

        while (true) {
            double next_estimate = 0.5 * (estimate + x / estimate);

            if (abs(next_estimate - estimate) < 0.0001)
                break;

            estimate = next_estimate;
        }

        return estimate;
    }
}