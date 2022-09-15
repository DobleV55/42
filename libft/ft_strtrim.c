char	*ft_strtrim(char const *s1, char const *set)
{
    char    *leftIdx;
    char    *rightIdx;
    char    *r;
    int     len_r;

    leftIdx = (char *)s1;
    rightIdx = (char *)s1+ft_strlen(s1)-1;
    while (*leftIdx == *set)
        leftIdx++;
    while (*rightIdx == *set)
        rightIdx--;
    len_r = rightIdx-leftIdx+1;
    r = (char *) malloc (rightIdx-leftIdx);
    while (leftIdx <= rightIdx)
    {
        *r = *leftIdx;
        leftIdx++;
        r++;
    }
    return r-len_r;
}
