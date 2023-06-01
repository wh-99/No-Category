#pragma once

template <typename T>
class Vec3 {
    public:
        Vec3();
        Vec3(const Vec3<T>& _other);
        ~Vec3() noexcept;

        Vec3<T>& operator=(const Vec3<T>& _other);

    private:
        T v1 = { };
        T v2 = { };
        T v3 = { };
};

template <typename T> Vec3<T>::Vec3() { }
template <typename T> Vec3<T>::Vec3(const Vec3<T>& _other)
    : v1{_other.v1}
    , v2{_other.v2}
    , v3{_other.v3}
{ }
template <typename T> Vec3<T>::~Vec3() noexcept { }

template <typename T> Vec3<T>& Vec3<T>::operator=(const Vec3<T>& _other) {
    v1 = _other.v1;
    v2 = _other.v2;
    v3 = _other.v3;

    return *this;
}