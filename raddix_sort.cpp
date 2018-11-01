/*************************************************************************
	> File Name: raddix_sort.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年10月21日 星期日 11时03分13秒
 ************************************************************************/

#include<iostream>
using namespace std;

void raddix_sort(int *num, int n) {
    int *temp = (int *)malloc(sizeof(int) * n);
    int cnt[65536] = 0;
    for (int i = 0; i < n; i++) cnt[num[i] & 0xffff]++;//统计数字出现了几次
    for (int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];//计算有几个数字
    cnt[0] = 0;
    for (int i = 65536; i >= 1; i--) cnt[i] = cnt[i - 1];//
    for (int i = 0; i < n; i++) temp[cnt[(num[i] & 0xffff)]++] = num[i];
    memset(cnt, 0, sizeof(cnt));//第二轮比较
    for (int i = 0; i < n; i++) cnt[(temp[i] >> 16) & oxffff]++;
    for (int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];
    cnt[0] = 0;
    for (int i = 65536; i >= i; i--) cnt[i] = cnt[i - 1]
    num[cnt[(temp[i] >> 16) & 0xffff]++] = temp[i];
     return ;
}


