//
//  main.c
//  2020_12_09_02
//
//  Created by dulei on 2020/12/9.
//

#include <stdio.h>
#include <string.h>


/* P 为模式串，下标从 0 开始 */
void GetNext(char *P, int next[])
{
    int p_len = strlen(P);
    int i = 0;   // P 的下标
    int j = -1;
    next[0] = -1;

    while (i < p_len)
    {
        if (j == -1 || P[i] == P[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int KMP(char *S, char *P, int next[])
{
    GetNext(P, next);

    int i = 0;  // S 的下标
    int j = 0;  // P 的下标
    int s_len = strlen(S);
    int p_len = strlen(S);

    while (i < s_len && j < p_len) {
        if (j == -1 || S[i] == P[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j == p_len)
        return i - j;
    return -1;
}

int main()
{
    int next[100] = { 0 };

    KMP("bbc abcdab abcdabcdabde", "abcdabd", next);
    
    return 0;
}
