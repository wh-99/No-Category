#pragma once

#include "./math.h"

/*  TODO LIST
        1. distance(v1, v2)
        2. angle(v1, v2)
        3. operator/, /=
*/

/*  ERR CHECKS
        1. magnitude() -> sqrt's _val > 0
        2. operator/, /= -> _val != 0
*/

class Vec3 {
    public:
        Vec3() noexcept;
        Vec3(const Vec3& _other) noexcept;
        Vec3(const float& _v1, const float& _v2, const float& _v3) noexcept;
        ~Vec3() noexcept;

        Vec3& operator=(const Vec3& _other) noexcept;
        Vec3& operator+=(const Vec3& _vec) noexcept;
        Vec3& operator-=(const Vec3& _vec) noexcept;
        Vec3& operator*=(const float& _val) noexcept;
        // Vec3& operator/=(const float& _val) noexcept;

        Vec3 operator+(const Vec3& _vec) noexcept;
        Vec3 operator-(const Vec3& _vec) noexcept;
        Vec3 operator*(const float& _val) noexcept;
        // Vec3 operator/(const float& _val) noexcept;

        float magnitude() const noexcept;

        float x() const noexcept;
        float y() const noexcept;
        float z() const noexcept;

        void x(const float& _val) noexcept;
        void y(const float& _val) noexcept;
        void z(const float& _val) noexcept;

        static Vec3 normalize(const Vec3& _vec) noexcept;
        static Vec3 crossProduct(const Vec3& _v1, const Vec3& _v2) noexcept;
        static float dotProduct(const Vec3& _v1, const Vec3& _v2) noexcept;

    private:
        float v1 = { };
        float v2 = { };
        float v3 = { };
};

Vec3::Vec3() noexcept { }
Vec3::Vec3(const Vec3& _other) noexcept { *this = _other; }
Vec3::Vec3(const float& _v1, const float& _v2, const float& _v3) noexcept
    : v1{_v1}
    , v2{_v2}
    , v3{_v3}
{ }
Vec3::~Vec3() noexcept { }

Vec3& Vec3::operator=(const Vec3& _other) noexcept {
    if (this != &_other) {
        v1 = _other.v1;
        v2 = _other.v2;
        v3 = _other.v3;
    }

    return *this;
}
Vec3& Vec3::operator+=(const Vec3& _vec) noexcept {
    v1 += _vec.v1;
    v2 += _vec.v2;
    v3 += _vec.v3;

    return *this;
}
Vec3& Vec3::operator-=(const Vec3& _vec) noexcept {
    v1 -= _vec.v1;
    v2 -= _vec.v2;
    v3 -= _vec.v3;

    return *this;
}
Vec3& Vec3::operator*=(const float& _val) noexcept {
    v1 *= _val;
    v2 *= _val;
    v3 *= _val;

    return *this;
}

Vec3 Vec3::operator+(const Vec3& _vec) noexcept {
    return Vec3(
        v1 + _vec.v1,
        v2 + _vec.v2,
        v3 + _vec.v3
    );
}
Vec3 Vec3::operator-(const Vec3& _vec) noexcept {
    return Vec3(
        v1 - _vec.v1,
        v2 - _vec.v2,
        v3 - _vec.v3
    );
}
Vec3 Vec3::operator*(const float& _val) noexcept {
    return Vec3(
        v1 * _val,
        v2 * _val,
        v3 * _val
    );
}

float Vec3::magnitude() const noexcept { return Math::sqrt(SQUARE(v1) + SQUARE(v2) + SQUARE(v3)); }

float Vec3::x() const noexcept { return v1; }
float Vec3::y() const noexcept { return v2; }
float Vec3::z() const noexcept { return v3; }

void Vec3::x(const float& _val) noexcept { v1 = _val; }
void Vec3::y(const float& _val) noexcept { v2 = _val; }
void Vec3::z(const float& _val) noexcept { v3 = _val; }

Vec3 Vec3::normalize(const Vec3& _vec) noexcept {
    float mag = _vec.magnitude();

    return Vec3(
        _vec.v1 / mag,
        _vec.v2 / mag,
        _vec.v3 / mag
    );
}
Vec3 Vec3::crossProduct(const Vec3& _v1, const Vec3& _v2) noexcept {
    // Cross (u, v) =
    //     u.y * v.z - u.z * v.y,
    //     u.z * v.x - u.x * v.z,
    //     u.x * v.y - u.y * v.x

    return Vec3(
        (_v1.v2 * _v2.v3) - (_v1.v3 * _v2.v2),
        (_v1.v3 * _v2.v1) - (_v1.v1 * _v2.v3),
        (_v1.v1 * _v2.v2) - (_v1.v2 * _v2.v1)
    );
}
float Vec3::dotProduct(const Vec3& _v1, const Vec3& _v2) noexcept {
    // Dot (u, v) =
    //     u.x * v.x +
    //     u.y * v.y +
    //     u.z * v.z

    return (_v1.v1 * _v2.v1 + _v1.v2 * _v2.v2 + _v1.v3 * _v2.v3);
}