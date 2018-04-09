#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>
const int MIN_PID = 300;
const int MAX_PID = 5000;
int allocateMap();
int allocatePID();
int releasePID();
void *thread();
int z=0;
int pid[4700];
int map[4700];
int main()
{
    printf("\n\n\t#########  PROCESS ID MANAGER  #########\n\n");
   int i;
    int j;
   srand(time(0));
   allocateMap();
   pthread_t t[100];
    printf("## The threads are being created..\n\n");
    for(i=0;i<100;i++)
        pthread_create(&t[i],NULL,&thread,NULL);
    for(j=0;j<100;j++)
        (pthread_join(t[j],NULL));
   printf("\n\n#The Total threads created are : \n");
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
   printf("\n!! PID %d is already released !!\n\n",pidNum);
   return 1;
   }
     
   map[newPid]=0;
}
void *thread()
{
   z=z+1;
   int t;
   t=allocatePID();
   printf("%d Allocate PID : %d\n",z,t);
   pthread_yield(rand()%(10-5)+5);
   printf("\n## Releasing PID : %d ##\n\n",t);
   releasePID(t);
    
}
