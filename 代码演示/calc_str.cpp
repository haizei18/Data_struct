/*************************************************************************
	> File Name: calc_str.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年10月23日 星期二 10时44分16秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x3f3f3f3f

int calc(const char *str,int l, int r) {
    int pos = -1, temp_prior = 0, prior = INF - 1;
    for (int i = l; i <= r; i++) {
        int cur_prior = INF;
        switch (str[i]) {
            case '(' : temp_prior += 100; break;
            case ')' : temp_prior -= 100; break;
            case '+' : cur_prior = temp_prior + 1; break;
            case '-' : cur_prior = temp_prior + 1; break;
            case '*' : cur_prior = temp_prior + 2; break;
            case '/' : cur_prior = temp_prior + 2; break;
        }
        if (cur_prior <= prior) {
            prior = cur_prior;
            pos = i;
        }
    }
    if (pos == -1) {
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + str[i] - '0';
        }
        return num;
    } else {
        int a = calc(str, l, pos - 1);
        int b = calc(str, pos + 1, r);
        switch (str[pos]) {
            case '+' : return a + b;
            case '-' : return a - b;
            case '*' : return a * b;
            case '/' : return a / b;
        }
    }
    return 0;
}

int main() {
    char str[1000];
    scanf("%[^\n]s", str);
    printf("%d\n", calc(str, 0, strlen(str) - 1));
}
