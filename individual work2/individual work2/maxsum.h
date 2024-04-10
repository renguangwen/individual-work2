#pragma once
#ifndef MAXSUM_H  
#define MAXSUM_H  

// 声明MaxSum函数的原型  
int MaxSum(int a[], int left, int right, int length) {
    int sum = 0;
    int center, leftsum, rightsum, s1, lefts, i, s2, rights, j;
    if (left == right) { // 如果序列长度为1，直接求解  
        if (a[left] > 0)
            sum = a[left];
        else
            sum = 0;
    }
    else {
        center = (left + right) / 2; // 划分  
        leftsum = MaxSum(a, left, center, length); // 递归求解左半部分  
        rightsum = MaxSum(a, center + 1, right, length); // 递归求解右半部分  
        s1 = 0;
        lefts = 0;
        // 计算包含中心的最大子段和  
        for (i = center; i >= left; i--) {
            lefts += a[i];
            if (lefts > s1)
                s1 = lefts;
        }
        s2 = 0;
        rights = 0;
        // 计算包含中心的最大子段和  
        for (j = center + 1; j <= right; j++) {
            rights += a[j];
            if (rights > s2)
                s2 = rights;
        }
        sum = s1 + s2; // 计算跨越中心的最大子段和  
        if (sum < leftsum)
            sum = leftsum;
        // 合并结果  
        if (sum < rightsum)
            sum = rightsum;
    }
    return sum;
}
#endif // MAXSUM_H