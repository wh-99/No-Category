isConst<const int&>      : 1

isConst<const int&&>     : 1

isConst<const int*>      : 0    // 가리키는 포인터를 변경할 수 있으므로 False

isConst<const int* const>: 1

isReference<int&>       : 1

isReference<int&&>      : 1

isReference<const int&> : 1

isReference<const int&&>: 1


isPointer<int*>                    : 1

isPointer<const int*>              : 1

isPointer<const int* const>        : 1

isPointer<const int* const*>       : 1

isPointer<const int* const* const> : 1

isPointer<const int* const* const*>: 1


isFloat<float>        : 1

isFloat<const float>  : 1

isFloat<const float&> : 1

isFloat<const float&&>: 1


isLvalueReference<int&>      : 1

isLvalueReference<const int&>: 1


isArray<int[]>        : 1

isArray<int[10]>      : 1

isArray<const int[]>  : 1

isArray<const int[10]>: 1

isArray<int*[]>       : 1

isArray<const int*[]> : 1
