#pragma once

template <typename T>
class Vec3 {
    public:
        Vec3();
        ~Vec3() noexcept;

    private:
        T v1 = { };
        T v2 = { };
        T v3 = { };
};

template <typename T> Vec3<T>::Vec3() { }
template <typename T> Vec3<T>::~Vec3() noexcept { }
