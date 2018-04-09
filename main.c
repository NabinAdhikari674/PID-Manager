#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
const int MIN_PID = 30;
const int MAX_PID = 35;
int pid[4700];
int map[4700];
int allocateMap();
int allocatePID();
int releasePID();
void *thread();
int z=0;
int main()
{
   srand(time(0));
   int i;
   allocateMap();
   pthread_t t[100];
    printf("The threads are being created..\n\n");
    for(i=0;i<5;i++) 
    {
        pthread_create(&t[i],NULL,&thread,NULL);
        pthread_join(t[i],NULL);
    }
   printf("\n\nThe threads are created\n");
   printf("%d\n",z);
}
    
int allocateMap()
{   
   int i;
   if(pid == NULL)
       return -1; 
   for(i=0; i<(MAX_PID-MIN_PID); i++)
   {
   pid[i]=0;
   map[i]=0;
   } 
   return 1;
}
     
int allocatePID()
{      
   if(pid ==NULL)
   {
   printf("PID Manager is not initialized ");
   return -1;
   } 
    int pidNum=-1;
    int yoyo=0;
   while(yoyo==0)
   { 
        pidNum = rand()%(MAX_PID-MIN_PID)+MIN_PID;
        if (map[pidNum]==0)
            break;
   }
   map[pidNum]=1;
   if(pidNum == -1)
   {
   printf("Unable to allocate PID");
   } 
   return pidNum;
}
     
int releasePID(int pidNum)
{     
   if(pid == NULL)
   {
   printf("PID Manager is not initialized ");
   return 0;
   }
     
   if(pidNum < MIN_PID || pidNum > MAX_PID){
   printf("Given PID is out or Range");
   }
     
   int newPid = pidNum - MIN_PID;
     
   if(map[pidNum] == 0){
   printf("PID %d is already released ",pidNum);
   return 1;
   }
     
   map[newPid]=0;
}
void *thread()
{
   z=z+1;
   printf("%d\n",z);
   int t;
   t=allocatePID();
   printf("Allocate PID : %d\n",t);
    sleep(1);
   printf("Releasing PID : %d\n",t);
   releasePID(t);
    
}
