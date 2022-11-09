int    word_length(const char *str)
{
    int        size;

    while (*str)
    {
        if (!split_whitespaces(*str))
            break ;
        ++str;
    }
    size = 0;
    while (*str)
    {
        if (split_whitespaces(*str))
            break ;
        ++size;
        ++str;
    }
    return (size - 1);
}
