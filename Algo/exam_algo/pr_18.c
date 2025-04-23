#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void computeLPSArray(const char *pat, int M, int *lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int *KMPSearch(const char *pat, const char *txt, int *count)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int *lps = (int *)malloc(M * sizeof(int));
    computeLPSArray(pat, M, lps);

    int *result = (int *)malloc(N * sizeof(int));
    *count = 0;
    int i = 0, j = 0;

    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }
        if (j == M)
        {
            result[*count] = i - j + 1; // 1-based position
            (*count)++;
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    free(lps);
    return result;
}

int main()
{
    char txt[100], pat[100];
    printf("Enter text: ");
    scanf("%s", txt);
    printf("Enter pattern: ");
    scanf("%s", pat);

    int count;
    int *positions = KMPSearch(pat, txt, &count);

    if (count == 0)
    {
        printf("Pattern not found.\n");
    }
    else
    {
        printf("Pattern found at positions: ");
        for (int i = 0; i < count; i++)
            printf("%d ", positions[i]);
        printf("\n");
    }

    free(positions);
    return 0;
}
