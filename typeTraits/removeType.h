#pragma once

namespace removeBase {
    template <typename T> struct removeConst          { typedef T type; };
    template <typename T> struct removeConst<const T> { typedef T type; };

    // template <typename T> struct removeVolatile             { typedef T type; };
    // template <typename T> struct removeVolatile<volatile T> { typedef T type; };

    template <typename T> struct removeReference      { typedef T type; };
    template <typename T> struct removeReference<T&>  { typedef T type; };
    template <typename T> struct removeReference<T&&> { typedef T type; };
}

template <typename T> using removeConst = typename removeBase::removeConst<T>::type;
template <typename T> using removeReference = typename removeBase::removeReference<T>::type;