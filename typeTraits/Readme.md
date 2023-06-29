### isConst

1. isConst<const int&>      : 1  
2. isConst<const int&&>     : 1  
3. isConst<const int*>      : 0  
4. isConst<const int* const>: 1  
---
### isReference

isReference<int&>       : 1  
isReference<int&&>      : 1  
isReference<const int&> : 1  
isReference<const int&&>: 1  
---
### isPointer

isPointer<int*>                    : 1  
isPointer<const int*>              : 1  
isPointer<const int* const>        : 1  
isPointer<const int* const*>       : 1  
isPointer<const int* const* const> : 1  
isPointer<const int* const* const*>: 1  
---
### isFloat

isFloat<float>        : 1  
isFloat<const float>  : 1  
isFloat<const float&> : 1  
isFloat<const float&&>: 1  
---
### isLvalueReference

isLvalueReference<int&>      : 1  
isLvalueReference<const int&>: 1  
---
### isArray

isArray<int[]>        : 1  
isArray<int[10]>      : 1  
isArray<const int[]>  : 1  
isArray<const int[10]>: 1  
isArray<int*[]>       : 1  
isArray<const int*[]> : 1  
---
