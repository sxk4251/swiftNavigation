#include<stdio.h>
#include<stdlib.h>

int main(void){
	unsigned int n,i;
	unsigned long long int a=1,b=1;
	unsigned int flag=0;
	
	unsigned int readNumber(void);	//function to get the user input

	printf("This program can generate upto 93 fibonacci numbers and check if the last number generated is prime or divisible by 15 or 5 or 3\n");
	n=readNumber();
	
	unsigned long long int *A=(unsigned long long int*)malloc(sizeof(unsigned long long int)*n); // Dynamic array to store the generated numbers

	A[0]=a;
	if(n==1) // If entered 1, print the first number & exit
	{   
		printf("%llu",a);
		return 0;
	}
	else if(n==2) // If entered 2, print the second number & exit
	{
		printf("%llu",b);
		A[1]=b;
		return 0;
	}
	else if(n>2){
		A[1]=b;
		for(i=3;i<=n;i++){ // Loop to calculate and store the number generated
			A[i-1]=a+b;
			b=a;
			a=A[i-1];
		}
	}
	if(!flag){ //Check the result stored in variable a is prime or not
		if(n>5){ // by default 2,3, and 5 are prime
		for(i=2;i<(n-1);i++){  //check if the number is divisible by any of the previous primes
			if(a%A[i]==0)
			{
				flag=1;
				break;
			}
		}
		}
		if(!flag){
			printf("\nBuzzFizz");
			return 0;
		}

	}
	
	if(a%15==0)
		printf("\nFizzBuzz");
	else if(a%5==0)
		printf("\nFizz");
	else if(a%3==0)
		printf("\nBuzz");
	else if(flag)	//If not a prime and not divisible by 3, 5, and 15
		printf("\n%llu",a);
	

	return 0;
}

unsigned int readNumber(){
	unsigned int n;
	printf("\nEnter number (n>0):");
	scanf("%u",&n);
	if(n>0)
		return n;
	else
		readNumber();
}
