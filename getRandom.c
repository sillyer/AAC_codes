/***@author YatingChen @time 03.23.16*********/
/***AAC 2.7 get the Random permutation of N*******/
/***** getRandom time used bound to O(N*N*logN)******
*******getRandom2 time used bound to 0(N*logN)*******
* getRandom3 time used bound to 0(n)*************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 640000
#define true 1
#define false 0

int randInt(int i,int j)
{
	int res;
	res=i+(j-i)*1.0*rand()/RAND_MAX+1;
//	res=rand()/RAND_MAX*(j-i)+i;
//	printf("res=%d\n",res);
	return res;
//	i+(j-i)*rand()/RAND_MAX+1;
}

int* getRandom(int* a, int length)
{
	int i,j;
	for(i=0; i<length; i++)
	{
		j=randInt(0,length);
//		printf("i=%d,j=%d\n",i,j);
//		/*********************
		while(1)
		{
			if(findExit(a,i,j))
			{
				j=randInt(0,length);
//				printf("new j=%d;\n",j);
			}else{
				break;
			}
		}
		a[i]=j;
//		************************/
	}
	return a;
}

int* getRandom2(int* a, int length)
{
	int i,j;
	int Used[LEN]={0};
//	for(i=0;i<length;i++)	printf("used[%d]=%d\n",i,Used[i]);
	for(i=0; i<length; i++)
	{
		j=randInt(0,length);
//		printf("j=%d\n",j);
		while(Used[j-1])
		{
			j=randInt(0,length);
//			printf("new j=%d,\n",j);
		}
		Used[j-1]=1;
		a[i]=j;
	}
//	printf_a(a,length);
	return a;
}

int* getRandom3(int* a,int length)
{
	int i,j;
	for(i=0; i<length; i++)
	{
		a[i]=i+1;
	}
	for(i=0; i<length; i++)
	{
		int temp = a[i];
		j=randInt(0,i);
		a[i]=a[j-1];
		a[j-1]=temp;
	}
	return a;
}

int findExit(int* a,int length,int value)
{
	int i;
	for(i=0; i<length; i++)
	{
		if(a[i]==value)
			return true;
	}
	return false;
}

void printf_a(int* a,int length)
{
	printf("a[%d]={",length);
	int i;
	for(i=0; i<length; i++)
	{
		if(i!=length-1)
			printf("%d,",a[i]);
		else
			printf("%d",a[i]);
	}
	printf("};\n");
}

int main(int argc, char argv[])
{
	int * a;
	a = malloc(LEN*sizeof(int));
	
	int loop_time = 10;
	srand((unsigned)time(NULL));
	//timer
	clock_t start,finish;
	double duration;
	start = clock();
	
	while(loop_time>0)
	{
		getRandom3(a,LEN);
		loop_time--;
	}
	
	finish = clock();
	duration = (double)(finish-start)/CLOCKS_PER_SEC;
	printf("run time is %fs.\n",duration);

//	printf_a(a,LEN);
}

