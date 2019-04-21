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
        while( i != r )                  //·��ѹ��
        {
            j = pre[ i ]; 				
            pre[ i ]= r ; 				//���ϼ���Ϊ���ڵ�
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
    printf("���������벢�鼯�и�Ԫ�ص��ϼ��±꣨����-1��ֹͣ����\n");
    do
    {
        printf("�������%d��Ԫ�ص��ϼ��±꣺",i+1);
        scanf("%d",&pre[i]);
    } while (pre[i++] >= 0);
    while (1)
    {
        printf("������������Ĳ���:\n");
        printf("1. �󲢼�\n");
        printf("2. ��root\n");
        printf("3. �˳�\n");
        scanf("%d",&s);
        switch (s)
        {
        case 1:
            printf("�ݲ�֧�ִ˹���,��������ҳ�鿴\n");
            break;
        
        case 2:
            printf("������Ҫ����root���±꣺");
            scanf("%d",&temp);
            temp = FindRoot(temp,&pre);
            printf("�±�Ϊ%d\n",temp);
            break;
        case 3:
            exit(-1);
        default:
            break;
        }
        
    }
    
    return 0;
}