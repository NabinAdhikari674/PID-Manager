#include<stdio.h>
const int MIN_PID = 300;
const int MAX_PID = 5000;
int pid[4700];
int allocateMap();
int allocatePID();
int releasePID();
int main()
{  int z;
   allocateMap();
   printf("Allocate PID : %d\n",allocatePID());
   printf("Allocate PID : %d\n",allocatePID());
   printf("Releasing PID : 300\n");
   releasePID(300);
   printf("Allocate PID : %d\n",allocatePID());
}
    
int allocateMap()
{   
   int i;
   if(pid == NULL)
       return -1; 
   //sets all pid to 0, which indicates the process if of i is available
   
   for(i=0; i<(MAX_PID-MIN_PID); i++)
   {
   pid[i] = 0;
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
     
   if(pid[newPid] == 0){
   printf("PID %d is already released ",newPid);
   return 1;
   }
     
   pid[newPid]=0;
}
