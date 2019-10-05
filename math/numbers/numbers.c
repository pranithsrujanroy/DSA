#include <stdio.h>

int main()
{
   
   char s[100];
   scanf("%s",s);
   int a[10]={0,0,0,0,0,0,0,0,0,0};
   
   for(int i=0;s[i]!='\0';i++)
   {

      for(int j=0;j<10;j++)
      {
         if(s[i]==(j+48))
            a[j]=a[j] + 1;
      }
   }
   
   for(int i=0;i<10;i++)
   {
       printf("%d %d\n",i,a[i]);
   }
   
    return 0;
}
