int strlen(const char *target)
{
    int len = 0;
    for (len = 0; target[len] != '\0'; len++)
        ;
    return len;
}

// not works as the original version though. returns 1 if both string don't match otherwise 0
int strcmp(const char *s1, const char *s2)
{
    int l1 = strlen(s1), l2 = strlen(s2);
    if (l1 != l2)
    {
        return 1;
    }
    while (l1 > -1)
    {
        if(s1[l1] != s2[l1]) {
            return 1;
        }
        l1--;
    }
    return 0;
}

void memcpy(char *dest, const char *src, int size)
{
    for(int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
    dest[size] = '\0';
}