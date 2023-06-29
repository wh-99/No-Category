#pragma once

namespace conditionBase {
    template <bool, typename = void> struct enableIF          { };
    template <typename T>            struct enableIF<true, T> { using type = T; };
}

template <bool Condition, typename T = void> using enableIF = typename conditionBase::enableIF<Condition, T>::type;