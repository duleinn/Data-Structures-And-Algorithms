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

/* 在 S 中找到 P 第一次出现的位置 */
int KMP(char *S, char *P, int next[])
{
    GetNext(P, next);

    int i = 0;  // S 的下标
    int j = 0;  // P 的下标
    int s_len = strlen(S);
    int p_len = strlen(S);

    while (i < s_len && j < p_len) // 因为末尾 '\0' 的存在，所以不会越界
    {
        if (j == -1 || S[i] == P[j])  // P 的第一个字符不匹配或 S[i] == P[j]
        {
            i++;
            j++;
        }
        else
            j = next[j];  // 当前字符匹配失败，进行跳转
    }

    if (j == p_len)  // 匹配成功
        return i - j;
    
    return -1;
}

int main()
{
    int next[100] = { 0 };

    KMP("bbc abcdab abcdabcdabde", "abcdabd", next);
    
    return 0;
}
