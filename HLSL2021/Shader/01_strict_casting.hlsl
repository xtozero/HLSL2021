struct LinearRGB
{
    float3 RGB;
};

struct LinearYCoCg
{
    float3 YCoCg;
};

float GetLuma4(LinearRGB In)
{
    return In.RGB.g * 2.0 + In.RGB.r + In.RGB.b;
}

float GetLuma4(LinearYCoCg In)
{
    return In.YCoCg.x;
}

[numthreads(1, 1, 1)]
void main()
{
    LinearYCoCg v = { { 0.0, 0.0, 0.0 } };
    GetLuma4(v);
}