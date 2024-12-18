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
struct Partial
{
    T first;
    U second;
};

template<typename T>
struct Partial<T, int>
{
    T first;
};

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
    
    Partial<float, float> P1;
    P1.first = 0.f;
    P1.second = 0.f;
    
    Partial<float, int> P2;
    P2.first = 0.f;
    // Because partial specialization is supported, uncommenting below will cause a compile error
    // P2.second = 0;

    int I = 1;
    uint J = cast<uint>(I);
}