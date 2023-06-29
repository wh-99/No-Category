#pragma once

#include "./removeType.h"

namespace typeBase {
    template <typename T> constexpr bool isConst          = false;
    template <typename T> constexpr bool isConst<const T> = true;

    // template <typename T> constexpr bool isVolatile             = false;
    // template <typename T> constexpr bool isVolatile<volatile T> = false;

    template <typename T> constexpr bool isPointer     = false;
    template <typename T> constexpr bool isPointer<T*> = true;

    template <typename T> constexpr bool isLvalueReference     = false;
    template <typename T> constexpr bool isLvalueReference<T&> = true;

    template <typename T> constexpr bool isRvalueReference      = false;
    template <typename T> constexpr bool isRvalueReference<T&&> = true;

    template <typename T> constexpr bool isFloat    = false;
    template <> constexpr bool isFloat<float>       = true;
    template <> constexpr bool isFloat<double>      = true;
    template <> constexpr bool isFloat<long double> = true;

    template <typename T> constexpr bool isUnsigned           = false;
    template <> constexpr bool isUnsigned<unsigned char>      = true;
    template <> constexpr bool isUnsigned<unsigned short>     = true;
    template <> constexpr bool isUnsigned<unsigned int>       = true;
    template <> constexpr bool isUnsigned<unsigned long>      = true;
    template <> constexpr bool isUnsigned<unsigned long long> = true;

    template <typename T> constexpr bool isSignedInteger  = false;
    template <> constexpr bool isSignedInteger<char>      = true;
    template <> constexpr bool isSignedInteger<short>     = true;
    template <> constexpr bool isSignedInteger<int>       = true;
    template <> constexpr bool isSignedInteger<long>      = true;
    template <> constexpr bool isSignedInteger<long long> = true;

    template <typename T, unsigned long long N = 0> constexpr bool isArray   = false;
    template <typename T, unsigned long long N> constexpr bool isArray<T[N]> = true;
    template <typename T>                       constexpr bool isArray<T[]>  = true;
}

template <typename T> constexpr bool isConst = typeBase::isConst<removeReference<T>>;
template <typename T> constexpr bool isReference = typeBase::isLvalueReference<T> || typeBase::isRvalueReference<T>;
template <typename T> constexpr bool isLvalueReference = typeBase::isLvalueReference<T>;
template <typename T> constexpr bool isRvalueReference = typeBase::isRvalueReference<T>;
template <typename T> constexpr bool isPointer = typeBase::isPointer<removeConst<T>>;

template <typename T> constexpr bool isFloat = typeBase::isFloat<removeCR<T>>;
template <typename T> constexpr bool isSignedInteger = typeBase::isSignedInteger<removeCR<T>>;
template <typename T> constexpr bool isUnsigned = typeBase::isUnsigned<removeCR<T>>;
template <typename T> constexpr bool isSigned = typeBase::isSignedInteger<T> || typeBase::isFloat<T>;
template <typename T> constexpr bool isInteger = typeBase::isSignedInteger<T> || typeBase::isUnsigned<T>;

template <typename T> constexpr bool isArithmetic = isFloat<T> || isInteger<T>;

template <typename T> constexpr bool isArray = typeBase::isArray<T>;