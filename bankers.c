#include<stdio.h>
int required[100] , allocate[100], need[100];
void main()

   {
   int n; 
   int max = 10 , allocateCount= 0;
   printf("enterv the num of process: \n");
   scanf("%d", &n);
   
   printf("enter the required resourse for each process: \n");
   for(int i=0; i<n; i++)
   {
   printf("requirement for process %d: \n", i+1);
   scanf("%d", &required[i]);
   }
   printf("enter the alloacrted resourse for each process: \n");
   for(int i=0; i<n; i++)
   {
   printf("allocated for process %d: \n", i+1);
   scanf("%d", &allocate[i]);
   allocateCount += allocate[i];
   need[i] = required[i] - allocate[i];
   }
   
   int available = max - allocateCount;
   int count = n , sequence=0;
   int ans[n] , ind =0;
   for(int i=0; i<n; i++)
   {
      for(int j=0; j<n; j++)
      {
       if(need[j] > available)
       {
       continue;
       }
       else{
       ans[ind++] = j+1;
       sequence++;
       count--;
       available+= need[j];
       need[j] = 0;
       }
      }
   }
 
  if (sequence < n)
  {
  printf("\n the system is unsafe state \n");
  }
  else 
  {
  printf("\n the system is safe state \n");
  for (int i= 0; i<n ; i++)
  {
  printf("p%d->", ans[i]);
  }
  }
  }
