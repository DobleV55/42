
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

void array_length(char const *s, char c, char **res, int arrays_need)
{
    int array_len;
    int counter;

    counter = 0 ;
    array_len = 0;
    while (counter < arrays_need)
    {
        if (*s == '\0')
        {
            res[counter] = (char *) malloc (array_len);
            counter++;
        }
        else if (*s != c)
            array_len++;
        else if (*s == c)
        {
            res[counter] = (char *) malloc (array_len);
            array_len = 0;
            counter++;
        }
        s++;
    }
    return;
}

void place_elements_into_arr(char const *s, char c, char **res)
{
    int i;
    int j;

    i = 0 ;
    j = 0 ;
    while (*s)
    {
        if (*s != c)
        {
            res[i][j] = *s;
            j++;
        }
        else if (*s == c)
        {
            i++;
            j = 0;
        }
        s++;
    }
    return;
}

char **ft_split(char const *s, char c) {
    char **r;
    int arrays_need;

    arrays_need = arrays_needed(s,c);
    *r = (char *) malloc (arrays_need);
    array_length(s, c, r, arrays_need);
    place_elements_into_arr(s, c, r);

    return r;
}
