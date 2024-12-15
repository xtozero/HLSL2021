[numthreads(1, 1, 1)]
void main()
{
    int3 X = { 1, 1, 1 };
    int3 Y = { 0, 0, 0 };
    
#if 1
    bool3 Cond = X && Y;
    bool3 Cond2 = X || Y;
    int3 Z = X ? 1 : 0;
#else
    // In HLSL 2021 this code should like this
    bool3 Cond = and(X, Y);
    bool3 Cond2 = or(X, Y);
    int3 Z = select(X, 1, 0);
#endif
}