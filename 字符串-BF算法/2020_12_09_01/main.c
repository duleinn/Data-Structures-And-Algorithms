//
//  main.c
//  2020_12_09_01
//
//  Created by dulei on 2020/12/9.
//

#include <stdio.h>
#include <string.h>

int brute_force(char *s, char *p);
int brute_force(char *s, char *p)
{
    long sLen = strlen(s);
    long pLen = strlen(p);
    int i = 0, j = 0;
    while (i < sLen && j < pLen) {
        if (s[i] == p[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == pLen) {
        return i - j;
    }
    return 0;
}

int main(int argc, const char * argv[]) {

    char *s = "abcacabdffe";
    char *p = "cab";
    int res = brute_force(s, p);
    printf("");
    return 0;
}
