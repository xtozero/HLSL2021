struct ColorRGBA
{
    uint R : 8;
    uint G : 8;
    uint B : 8;
    uint A : 8;
};

[numthreads(1, 1, 1)]
void main()
{
    ColorRGBA RGBA = (ColorRGBA)0;
    RGBA.R = 255;
}