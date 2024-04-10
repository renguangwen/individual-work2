#pragma once
#ifndef MAXSUM_H  
#define MAXSUM_H  

// ����MaxSum������ԭ��  
int MaxSum(int a[], int left, int right, int length) {
    int sum = 0;
    int center, leftsum, rightsum, s1, lefts, i, s2, rights, j;
    if (left == right) { // ������г���Ϊ1��ֱ�����  
        if (a[left] > 0)
            sum = a[left];
        else
            sum = 0;
    }
    else {
        center = (left + right) / 2; // ����  
        leftsum = MaxSum(a, left, center, length); // �ݹ������벿��  
        rightsum = MaxSum(a, center + 1, right, length); // �ݹ�����Ұ벿��  
        s1 = 0;
        lefts = 0;
        // ����������ĵ�����Ӷκ�  
        for (i = center; i >= left; i--) {
            lefts += a[i];
            if (lefts > s1)
                s1 = lefts;
        }
        s2 = 0;
        rights = 0;
        // ����������ĵ�����Ӷκ�  
        for (j = center + 1; j <= right; j++) {
            rights += a[j];
            if (rights > s2)
                s2 = rights;
        }
        sum = s1 + s2; // �����Խ���ĵ�����Ӷκ�  
        if (sum < leftsum)
            sum = leftsum;
        // �ϲ����  
        if (sum < rightsum)
            sum = rightsum;
    }
    return sum;
}
#endif // MAXSUM_H