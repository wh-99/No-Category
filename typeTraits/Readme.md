### isConst

1. isConst<const int&>      : 1  
2. isConst<const int&&>     : 1  
3. isConst<const int*>      : 0  
4. isConst<const int* const>: 1  
---
### isReference

1. isReference<int&>       : 1  
2. isReference<int&&>      : 1  
3. isReference<const int&> : 1  
4. isReference<const int&&>: 1  
---
### isPointer

1. isPointer<int*>                    : 1  
2. isPointer<const int*>              : 1  
3. isPointer<const int* const>        : 1  
4. isPointer<const int* const*>       : 1  
5. isPointer<const int* const* const> : 1  
6. isPointer<const int* const* const*>: 1  
---
### isFloat

1. isFloat<float>        : 1  
2. isFloat<const float>  : 1  
3. isFloat<const float&> : 1  
4. isFloat<const float&&>: 1  
---
### isLvalueReference

1. isLvalueReference<int&>      : 1  
2. isLvalueReference<const int&>: 1  
---
### isArray

1. isArray<int[]>        : 1  
2. isArray<int[10]>      : 1  
3. isArray<const int[]>  : 1  
4. isArray<const int[10]>: 1  
5. isArray<int*[]>       : 1  
6. isArray<const int*[]> : 1  
---
