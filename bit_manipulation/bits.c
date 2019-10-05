#include<stdio.h>

struct bits{
	signed int s_bits:2;
	unsigned int u_bits:2;
}bits; 	

int main(){
	struct bits b = {1,1};
//	printf("\nSigned: %d",b.s_bits);
//	printf("\nUnsigned: %d",b.u_bits);
		
	int i;
	for(i=0;i<10;i++){
		b.u_bits=i;
		printf("\n%d",b.u_bits);
	}
}
