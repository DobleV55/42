int arrays_needed(char const *s, char c)
{
    int arrays;
    int start;

    arrays = 0;
    start = 0;
    while (*s)
    {
        if (*s != c && !start)
        {
            arrays++;
            start = 1;
        }
        else if (*s == c)
        {
            start = 0;
        }
        s++;
    }
    return arrays;
}




char **ft_split(char const *s, char c)
{
    char    **r;
    *r = (char *) malloc (arrays_needed(s,c));

    return r;
}
