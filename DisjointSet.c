#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 1000


int FindRoot(int x,int pre[])                    
{
    int r=x;                      
    while (pre[r]!=r)           
    r=pre[r];  
    int i=x , j ;
        while( i != r )                  //路径压缩
        {
            j = pre[ i ]; 				
            pre[ i ]= r ; 				//把上级改为根节点
            i=j;
        }               
    return  r ;                
}

void Merge(int x,int y,int pre[])
{                           
    int fx = FindRoot(x,&pre),fy = FindRoot(y,&pre);
    if(fx != fy)
        pre[fx ]=fy;
}

int main()
{
    int pre[MAXSIZE];
    int i = 0;
    int s = -1;
    int temp = -1;
    printf("请依次输入并查集中各元素的上级下标（输入-1以停止）：\n");
    do
    {
        printf("请输入第%d个元素的上级下标：",i+1);
        scanf("%d",&pre[i]);
    } while (pre[i++] >= 0);
    while (1)
    {
        printf("请输入接下来的操作:\n");
        printf("1. 求并集\n");
        printf("2. 求root\n");
        printf("3. 退出\n");
        scanf("%d",&s);
        switch (s)
        {
        case 1:
            printf("暂不支持此功能,请进入代码页查看\n");
            break;
        
        case 2:
            printf("请输入要查找root的下标：");
            scanf("%d",&temp);
            temp = FindRoot(temp,&pre);
            printf("下标为%d\n",temp);
            break;
        case 3:
            exit(-1);
        default:
            break;
        }
        
    }
    
    return 0;
}