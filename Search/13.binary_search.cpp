/*************************************************************************
	> File Name: 13.binary_search.cpp
	> Author:zhangrui 
	> Mail:772962518@qq.com
	> Created Time: 2018年11月06日 星期二 19时27分11秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>


int binary_search1(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] > x) tail = mid - 1;
        else head = mid + 1;
    }
    return -1;
}

//1111100000
int binary_search2(int *num, int n) { 
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (num[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

//0000011111
int binary_search3(int *num, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (num[mid] == 1) tail = mid;
        else head = mid + 1;
    }
    return head;
}

int main() {
    int arr1[10] = {1, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int arr2[10] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    int arr3[10] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    int a = binary_search2(arr2, 10);
    int b = binary_search3(arr3, 10);
    printf("%d\n", a);
    printf("%d\n", b);
    return 0;
}
