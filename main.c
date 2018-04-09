#include<stdio.h>
static int MIN_PID = 300;
static int MAX_PID = 5000;
static int pid[];

int main()
{  int z;
   z=allocateMap();
   printf("Allocate PID : %d",allocatePID());
   printf("Allocate PID : %d",allocatePID());
   printf("Releasing PID : 300");
   releasPID(300);
   printf("Allocate PID : %d",allocatePID());
}
    
int allocateMap()
{   

    pid=rangeIntArray(pid,MIN_PID,MAX_PID);
    //Sets range for pid range
    //returns -1 if pid is unavailable
   if(pid == NULL)
       return -1; 
   //sets all pid to 0, which indicates the process if of i is available
   int i;
   for(i=0; i<(MAX_PID-MIN_PID); i++)
   {
   pid[i] = 0;
   } 
   return pid;
}
     
int allocatePID()
{      
   if(pid ==NULL)
   {
   printf("PID Manager is not initialized ");
   return -1;
   } 
   //pidNum is used to determine if the pid was allocate
   int pidNum =-1;
   //Sets values to 1 to indicate the pid is currently in use.
   int i;
   for(i=0; i<(MAX_PID-MIN_PID); i++)
   {        
        if(pid[i] == 0)
		{
        pid[i] = 1;
        //Adds value to pidNum to determine for loop was executed.
        pidNum = i + MIN_PID;
        break;
        }
   }  
   //If for loop was not executed, prints error
   if(pidNum == -1)
   {
   printf("Unable to allocate PID");
   } 
   return pidNum;
}
     
int releasPID(int pidNum)
{     
   if(pid == NULL)
   {
   printf("PID Manager is not initialized ");
   return;
   }
     
   if(pidNum < MIN_PID || pidNum > MAX_PID){
   printf("Given PID is out or Range");
   }
     
   int newPid = pidNum - MIN_PID;
     
   if(pid[newPid] == 0){
   printf("PID %d is already released ",newPid);
   return;
   }
     
   pid[newPid]=0;
}
