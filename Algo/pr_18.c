// Write C/C++ program to implement KMP string matching 
// method to find the pattern string in a text string both given by the 
// user.  Compute  the  complexity  of  the  method  for  a  text  string  of 
// length N and pattern string of length M, where N>M. 


#include <stdio.h>
#include <string.h>

int count = 0; // Complexity Counter

void computeLPSArray(char *pat, int m, int *lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m) {
        count++; 
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
        
    }
}

void KMPsearch(char *pat, char *txt) {
    int m = strlen(pat);
    int n = strlen(txt);
    int lps[m];

    computeLPSArray(pat, m, lps);
    
    int i = 0, j = 0;
    while (i < n) {
        count++; 
        if (pat[j] == txt[i]) {
            j++, i++;
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            j ? (j = lps[j - 1]) : i++;
        }
        
    }
}

// Time Complexity: O(N + M)

int main() {
    char txt[100], pat[100];
    printf("Enter text: ");
    scanf("%s", txt);
    printf("Enter pattern: ");
    scanf("%s", pat);

    KMPsearch(pat, txt);
    printf("Operation Count: %d\n", count);

    return 0;
}
