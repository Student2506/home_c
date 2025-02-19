
int is_two_same(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        for (int y = i + 1; y < size; y++)
        {
            if (a[y] == a[i])
                return 1;
        }
    }

    return 0;
}