#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int id;
    int arv,bst,tb,flag,st;
     
}process;
process p1[100],p2[100],p3[100];
int tmp1,tmp2,tmp3,prior;
int tqq1=8,tqq2=16;
int countT=0;   
void thw(process arRobin[],int a,int b,int c,int pos)
{
    arRobin[pos].id=a;
    arRobin[pos].arv=b;
    arRobin[pos].bst=c;
    arRobin[pos].tb=c;
}
void trvs(process arRobin[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("id is:%d",arRobin[i].id);
    }
}
void rRobin(process p[],int tQ,int ttq,int k)
{
    int i=0,fl=0;
    
    int TurnAround,wait;
    while(1){
        if(i==k){i=0;}
        if(ttq==0||fl==k)break; 
                
        if(p[i].arv<=countT && p[i].st!=1 && p[i].flag!=1)
        {
            
            if(tQ<=ttq){}
            else{tQ=ttq;}
            if(p[i].tb<=tQ)
            {
                printf("entered first");
                printf("%d\tTc val\n",countT);
                countT+=p[i].tb;
                TurnAround=countT-p[i].arv;
                wait=TurnAround-p[i].bst;
                p[i].st=1;
                p[i].flag=1;
                ttq-=p[i].tb;
                fl++;
                printf("process with id:%d completed\t waitTime is:%d\tTurnAroundTime is %d\n",p[i].id,wait,TurnAround);
                i++;
                continue;
            }
            if(p[i].tb>tQ)
            {
                printf("entered second");
                p[i].tb-=tQ;
                countT+=tQ;
                p[i].flag=0;
                ttq-=tQ;
                i++;
                continue;
            }
        }
        else{
            
            countT++;
            ttq--;
            
        }
        i++;
    }
    for(int i=0;i<k;i++)
    {
        p[i].flag=0;
    }
}

void fkfs(process p[],int k)
{
    int wait,Tat;
    for(int i=0;i<k;i++)
    {
        if(p[i].arv<=countT && p[i].st!=1 && p[i].flag!=1)
        {
            countT+=p[i].tb;
            Tat=countT-p[i].arv;
            wait=Tat-p[i].bst;
            p[i].flag=1;
            p[i].st=1;
            printf("process with id:%d completed\t waitTime is:%d\tTurnAroundTime is %d\n",p[i].id,wait,Tat);
        }   
        else{
            continue;
        }
    }
}

int main()
{
    int c1=0,c2=0,c3=0;
    int n,j,full=0;
    printf("Enter total number of processes");
    scanf("%d",&n);
    j=n;
    while(n!=0)
    {
        printf("Enter id of process");
        scanf("%d",&tmp1);
        printf("Enter arv time:");
        scanf("%d",&tmp2);
        printf("Enter bst time:");
        scanf("%d",&tmp3);
        
        printf("Enter priority of process");
        scanf("%d",&prior);
        
        if(prior==1){thw(p1,tmp1,tmp2,tmp3,c1);c1++;}
        else if(prior==2){thw(p2,tmp1,tmp2,tmp3,c2);c2++;}
        else if(prior==3){thw(p3,tmp1,tmp2,tmp3,c3);c3++;}
        else{printf("Wrong priority---TERMINATING");exit(-1);}
        n--;
    }
    
    while(countT<1000)
    {
    rRobin(p1,4,8,c1);
    rRobin(p2,4,16,c2);
    fkfs(p3,c3);
    }

    return 0;
}