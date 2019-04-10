#include<stdio.h>

#include<fcntl.h>

typedef struct 
{
    int id;
    int ar;
    int bt,tb;
    int probinR,flag,stt;
 
}
process;
process p1[100];

int smw,smTat;
int fl=0;

int c1=0;
int phl=1;


int counT=0;

int pindx=0;

void trvs(process arobinR[],int n){
    
for(int i=0;i<n;i++)
    {
        printf("id is:%d",arobinR[i].id);
 
   }
}

int mxm(process p[],int k)
{
    int idx=0;
  
  int mxm=-9999;
    for(int i=0;i<k;i++)

    {
        if(p[i].ar<=counT && p[i].probinR>mxm && p[i].flag!=1 && p[i].stt!=1)
   
     {
            idx=i;
           
 mxm=p[i].probinR;
      
      p[i].stt=0;
        }
        
    }
 
   for(int i=0;i<k;i++)
    {
    
    if(p[i].stt!=1 && p[i].flag!=1 && i!=idx)
    
    {
            if(i==idx){p[i].stt=0;continue;}
       
     p[i].stt=-2;
        }
    }
   
 return idx;
}

void fkfs(process p[],int k)
{
  
  int Tat=0,wait=0;
   
 for(int i=0;i<k;i++)
    {
    
    if(p[i].stt==-2 && p[i].flag!=1 && p[i].ar<=counT)
        {
        
    counT+=p[i].tb;

            p[i].tb=0;
        
    Tat=counT-p[i].ar;
          
  wait=Tat-p[i].bt;
            
smw+=wait;
          
  smTat+=Tat;
     
       p[i].flag=1;
         
   p[i].stt=1;
      
      printf("\nprocess with id[%d] COMPLETED\tWaitTime is[%d]\ttatTime is [%d]\n",p[i].id,wait,Tat);
   
         fl++;
        }
    }
  
  for(int i=0;i<k;i++)
    {
     
   if(p[i].stt!=1)
        {
    
    p[i].flag=0;
        p[i].stt=0;
        }
    }
}


void up(process arobinR[],int a,int b,int c,int d,int pos)
{
   
 arobinR[pos].id=a;
    
arobinR[pos].ar=b;
  
  arobinR[pos].bt=c;
   
 arobinR[pos].tb=c;
   
 arobinR[pos].probinR=d;
}

void robinR(process p[],int tQ,int Totaltq,int k)
{
    

    int i=0,idx=0;
    
    int tat,wait;
    while(1){
        

        if(i==k){i=0;}
        if(fl==k)
break; 
             
      
  idx=mxm(p,k);
      
  if(phl==1){    counT=p[idx].ar;phl++;}
  
      if(idx!=pindx){
            tQ=4;
        }
      
  pindx=idx;
       
 if(Totaltq>0)
        {
       
     if(Totaltq<tQ){tQ=Totaltq;}
            
  
              counT++;
                
             
   Totaltq--;
             
   p[idx].tb--;
            
    tQ--;
                
if(p[idx].tb==0)
                {
        
         tat=counT-p[idx].ar;
              
   wait=tat-p[idx].bt;
         
        smw+=wait;
       
          smTat+=tat;
              
   p[idx].flag=1;
         
        p[idx].stt=1;
           
      fl++;
              
   printf("\nprocess with id[%d] COMPLETED\tWaitTime is[%d]\ttatTime is [%d]\n",p[idx].id,wait,tat);
                 continue;
                }
     
       if(tQ==0)
            {
                p[idx].flag=1;
            }
            
        }
    
    else{
            printf("Time Quantum expired");
           
 fkfs(p,c1);
            Totaltq=16;
        }

}
}

int main()
{
    int tmpV1=0,tmpV2=0,tmpV3=0,probinR=0;
  
  int n,j,full=0;
 
   printf("Enter total number of processes");
    
scanf("%d",&n);
  
  j=n;
    
while(n!=0)
    {
    
    printf("Enter id of process");
        
scanf("%d",&tmpV1);
       
 printf("Enter ar time:");
     
   scanf("%d",&tmpV2);
     
   printf("Enter bt time:");
    
    scanf("%d",&tmpV3);
        
      
  printf("Enter probinRity of process");
       
 scanf("%d",&probinR);
       
 up(p1,tmpV1,tmpV2,tmpV3,probinR,c1);c1++;
        n--;
    }
    
 
   robinR(p1,4,16,c1);
   
 printf("\n\nAverage Waiting Time: %d \t Average Turn Around Time:%d\n\n",smw,smTat);
    return 0;
}