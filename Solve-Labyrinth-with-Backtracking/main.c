//
//  main.c
//  Solve-Labyrinth-with-Backtracking
//
//  Created by nevzat ekmekçi on 24/12/15.
//  Copyright © 2015 nevzat ekmekçi. All rights reserved.
//

#include <stdio.h>
#define MAX_STACK_SIZE 100
#define BOYUT 8
typedef struct {
    int satir;
    int sutun;
}STACK;
int boyut,K,L,top=-1;
STACK stack[MAX_STACK_SIZE];
/*
 printf("Matris boyutunu veriniz\n");
 scanf("%d",&boyut);
 */

int labyrinth[BOYUT+2][BOYUT+2]={
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,0,0,1,1,1,0},
    {0,0,1,0,1,1,1,1,1,0},
    {0,1,1,1,0,1,1,0,0,0},
    {0,0,1,0,1,1,1,0,0,0},
    {0,1,1,1,0,1,1,0,0,0},
    {0,1,1,0,1,1,0,1,1,0},
    {0,1,1,1,1,1,1,1,1,0},
    {0,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0},
};
int markedLabyrinth[BOYUT+2][BOYUT+2];
int main(int argc, const char * argv[]) {

    printf("Çıkış noktasının X ve Y koordinatlarını veriniz\n");
    scanf("%d %d",&K,&L);
    
    int i,satir,sutun;
    top=0;
    stack[0].satir=1;
    stack[0].sutun=1;
    markedLabyrinth[stack[top].satir][stack[top].sutun]=1;

    
    //yığıt boşalmadıkça ve çıkış bulunmadıkça dön.
    while ((top>=0)&&(!(stack[top].satir==K && stack[top].sutun==L))) {
        if((labyrinth[stack[top].satir-1][stack[top].sutun]==1)&&(markedLabyrinth[stack[top].satir-1][stack[top].sutun]==0))
        {
            top++;
            stack[top].satir =stack[top-1].satir-1;
            stack[top].sutun =stack[top-1].sutun;
            markedLabyrinth[stack[top].satir][stack[top].sutun]=1;
        }
        else if ((labyrinth[stack[top].satir][stack[top].sutun+1]==1)&&(markedLabyrinth[stack[top].satir][stack[top].sutun+1]==0))
        {
            top++;
            stack[top].satir =stack[top-1].satir;
            stack[top].sutun =stack[top-1].sutun+1;
            markedLabyrinth[stack[top].satir][stack[top].sutun]=1;
        }
        else if ((labyrinth[stack[top].satir+1][stack[top].sutun]==1)&&(markedLabyrinth[stack[top].satir+1][stack[top].sutun]==0))
        {
            top++;
            stack[top].satir =stack[top-1].satir+1;
            stack[top].sutun =stack[top-1].sutun;
            markedLabyrinth[stack[top].satir][stack[top].sutun]=1;
        }
        else if((labyrinth[stack[top].satir][stack[top].sutun-1]==1)&&(markedLabyrinth[stack[top].satir][stack[top].sutun-1]==0))
        {
            top++;
            stack[top].satir =stack[top-1].satir;
            stack[top].sutun =stack[top-1].sutun-1;
            markedLabyrinth[stack[top].satir][stack[top].sutun]=1;
        }
        else
        {
            top--;
        }
    }
    if(top<0)
    {
        printf("Yol Bulunamadı!!!\n");
    }
    else
    {
        stack[++top].satir=K;
        stack[top].sutun=L;
        printf("Yol Bulundu\n");
    }
    
    for(i=0;i<top;i++){
        printf("%d. eleman: %d %d\n",(i+1),stack[i].satir,stack[i].sutun);
        
    }
    return 0;
}
