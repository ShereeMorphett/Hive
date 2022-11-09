int    word_counter(const char *str)
{
    int    size;

    size = 0;
    while (*str)
    {
        while (!ft_split_whitespaces(*str) && *str)
            ++str;
        ++size;
        while (ft_split_whitespaces(*str) && *str)
            ++str;
    }
    return (size);
}