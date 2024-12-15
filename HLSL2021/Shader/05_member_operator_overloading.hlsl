struct Pupper
{
    int Fur;

    Pupper operator+(int MoarFur)
    {
        Pupper Val = { Fur + MoarFur };
        return Val;
    }

    bool operator<=(int y)
    {
        return Fur <= y;
    }

    operator bool() 
    {
        return Fur > 50;
    }
};

[numthreads(1, 1, 1)]
void main(uint tidx : SV_DispatchThreadId)
{
    Pupper y = { 0 };
    for (Pupper x = y; x <= 100; x = x + 1)
    {
        if ((bool) x)
            y = y + 1;
    }
}