#include <iostream>
using namespace std;

int main()
{
  
   char s[100];
   cin>>s;
   
   int a[10]={0,0,0,0,0,0,0,0,0,0};
   
   
   for(int i=0;s[i]!='\0';i++)
   {
   	for(int j=0;j<10;j++)
   	{
   		if((int)(s[i])==(j+48)){
            a[j]=a[j]+1;
         }
      		
   		
   	}
   }
   
   for(int i=0;i<10;i++)
   {
   	cout<<i<<" "<<a[i]<<"\n";
   }
    
    return 0;
}
