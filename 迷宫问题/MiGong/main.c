//
//  main.c
//  MiGong
//
//  Created by yanzi on 16/4/25.
//  Copyright © 2016年 yanzi. All rights reserved.
//
//poj3984迷宫问题，http://poj.org/problem?id=3984
#include <stdio.h>

int H[4] = {0, 1, 0, -1};
int V[4] = {-1,0, 1, 0};
int migong[5][5] = {
    0, 1, 0, 0, 0,
    
    0, 1, 0, 1, 0,
    
    0, 0, 0, 0, 0,
    
    0, 1, 1, 1, 0,
    
    0, 0, 0, 1, 0,
};
struct Pos{
    int m_x;
    int m_y;
}pos[30];
int cnt = 0;

void findPath(int x, int y);
void printArray();
int N = 5;

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    findPath(0, 0);
    for(int i =0 ; i < cnt; i++){
        printf("(%d, %d)", pos[i].m_x, pos[i].m_y);
    }
    return 0;
}

void findPath(int x, int y){
    int k = 0;
    if(x == N || y == N){
        printArray();
        return;
    }
    for(k=0; k < 4; k++){
        if(x >= 0 && y >= 0 && x < N && y < N && migong[x][y] == 0){
            pos[cnt].m_x = x;
            pos[cnt].m_y = y;
            
            migong[x][y] = -1;
            findPath(x + V[k], y + H[k]);
            migong[x][y] = 0;
            cnt++;

        }
    }
}

void printArray(){
    int i, j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++){
            printf("%d%c", migong[i][j], j < N-1 ? ' ' : '\n');
        }

}
