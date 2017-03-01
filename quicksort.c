#include<stdio.h>


/*
void change(int& a,int& b)//引用形参 是实参的别名，可改变实参的值
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
*/

#define uchar unsigned char
void quicksort(int *a,int low,int high, uchar *b)//数组，数组头0，数组尾N-1=（sizeof(a)/sizeof(a[0])  -1）
{
	if(low>high)
	{
		return;
	}

	int left=low;
	int right=high;
    	int key=a[left];
	uchar keyB=b[left];

	while(left<right)
	{
		while(left<right&&a[right]<=key)
		{
			--right;
		}
		/*
		change(key,a[right]);//不是传统意义上的交换，是a[left]=a[right];a[right]=key;
		*/
		a[left]=a[right];
		b[left]=b[right];
		//a[right]=key;//多余了，但无所谓，方便理解

		while(left<right&&a[left]>=key)
		{
			++left;
		}
		/*
		change(key,a[left]);//不是传统意义上的交换，是a[right]=a[left];a[left]=key;
		*/
		a[right]=a[left];
		b[right]=b[left];
		a[left]=key;
		b[left]=keyB;

	}
	quicksort(a,low,left-1,b);//递归左半边
	quicksort(a,left+1,high,b);//递归右半边
}

int main()
{
	int A[]={57,68,59,52,77,32,56,12,99,80};
	uchar B[]={0,1,2,3,4,5,6,7,8,9};

	printf("origin:\n");
	for(int i=0;i<=(sizeof(A)/sizeof(A[0])-1);i++)
	{
		printf("%3d ", A[i]);
		
	}
	printf("\n");

	for(int i=0;i<=(sizeof(B)/sizeof(B[0])-1);i++)
	{
		printf("%3d ", B[i]);
		
	}
	printf("\n");
	quicksort(A,0,sizeof(A)/sizeof(A[0])-1,B);

	printf("result:\n");
	for(int i=0;i<=(sizeof(A)/sizeof(A[0])-1);i++)
	{
		printf("%3d ", A[i]);
		
	}
	printf("\n");

	for(int i=0;i<=(sizeof(B)/sizeof(B[0])-1);i++)
	{
		printf("%3d ", B[i]);
		
	}
	printf("\n");

	return 0;
}
