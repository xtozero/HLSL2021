template<typename T>
void increment(inout T X)
{
    X += 1;
}

template<>
void increment(inout float3 X)
{
    X.x += 1.0;
}

template<typename T, typename U>
void partial(T X, U Y)
{
    
}

#if 0
// Partial template specializations are not supported
template<typename T>
void partial(T X, int Y)
{
    
}
#endif

template<typename V, typename T>
V cast(T X)
{
    return (V) X;
}

[numthreads(1, 1, 1)]
void main()
{
    int X = 0;
    int3 Y = { 0, 0, 0 };
    float3 Z = { 0.0, 0.0, 0.0 };
    increment(X);
    increment(Y);
    increment(Z);
    
    partial(X, Y);
    partial(X, X);

    int I = 1;
    uint J = cast<uint>(I);
}