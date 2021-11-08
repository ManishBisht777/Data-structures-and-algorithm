int ap(int a, int b, int c)
{
    if (c == 0)
    {
        if (a == b)
            return 1;
        return 0;
    }

    int n = (b - a) / c + 1;

    return ((b - a) % c == 0 && n > 0);
}