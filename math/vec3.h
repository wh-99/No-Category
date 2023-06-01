#pragma once

template <typename T>
class Vec3 {
    public:
        Vec3() noexcept;
        Vec3(const Vec3<T>& _other) noexcept;
        ~Vec3() noexcept;

        Vec3<T>& operator=(const Vec3<T>& _other) noexcept;

        T x() const noexcept;
        T y() const noexcept;
        T z() const noexcept;

        void x(const T& _val) noexcept;
        void y(const T& _val) noexcept;
        void z(const T& _val) noexcept;

    private:
        T v1 = { };
        T v2 = { };
        T v3 = { };
};

template <typename T> Vec3<T>::Vec3() noexcept { }
template <typename T> Vec3<T>::Vec3(const Vec3<T>& _other) noexcept { *this = _other; }
template <typename T> Vec3<T>::~Vec3() noexcept { }

template <typename T> Vec3<T>& Vec3<T>::operator=(const Vec3<T>& _other) noexcept {
    if (this != &_other) {
        v1 = _other.v1;
        v2 = _other.v2;
        v3 = _other.v3;
    }

    return *this;
}

template <typename T> T Vec3<T>::x() const noexcept { return v1; }
template <typename T> T Vec3<T>::y() const noexcept { return v2; }
template <typename T> T Vec3<T>::z() const noexcept { return v3; }

template <typename T> void Vec3<T>::x(const T& _val) noexcept { v1 = _val; }
template <typename T> void Vec3<T>::y(const T& _val) noexcept { v2 = _val; }
template <typename T> void Vec3<T>::z(const T& _val) noexcept { v3 = _val; }