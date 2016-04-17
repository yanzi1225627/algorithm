//
//  main.c
//  quicksort
//
//  Created by yanzi on 16/4/11.
//  Copyright © 2016年 yanzi. All rights reserved.
//

#include <stdio.h>
void quicksort(int a[], int l, int r);
void quicksort2(int a[], int l, int r);
void swap2(int* a, int*b);


int main(int argc, const char * argv[]) {
    int i = 0;
    printf("Hello, World!\n");
    int a[] = {49,38,65,97,76,13,27};
    quicksort2(a, 0, 6);
    for(i=0; i< 7; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}

void quicksort(int a[], int l, int r){
    int i, j, temp;
    if(l < r){
        i = l;
        j = r;
        temp = a[i];
        while(i < j){
            while(i < j && a[j] > temp)
                j--;
            if(i < j)
                a[i++] = a[j];
            
            
            while(i < j && a[i] < temp)
                i++;
            if(i < j)
                a[j--] = a[i];
            
            
        }
        a[i] = temp;
    
        quicksort(a, l, i-1);
        quicksort(a, i+1, r);
    }
}

void swap2(int* a, int*b){
    if(a == b){
        return;
    }
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort2(int a[], int l, int r){
    if(r <= l){
        return;
    }
    int m = l;
    for(int i = l+1; i<=r; i++){
        if(a[i] < a[l]){
            swap2(&a[++m], &a[i]);
        }
    }
    swap2(&a[m], &a[l]);
}