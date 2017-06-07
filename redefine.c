#include<stdio.h>

typedef struct a_s{
	int a;
	int b;
}A_S;

/* redefine error */
/*
typedef struct a_s{
	int a;
	int b;
	int c;
}A_S_T;
*/
/*
typedef struct c_s{
	int d;
}A_S;
*/
//结构体定义时: 结构体名和别名不能重复，否则重复定义错误或指向不明错误

typedef struct b_s{
	int a;
	int b;
}B_S;
/**/////////////////////////////////////////////////////////////////////////////////////////



typedef A_S AS;
   typedef A_S AS;//单独别名定义时，只要没有歧义就行
// typedef B_S AS; //ERROR错误
typedef B_S BS;
typedef B_S CS;
//**///////////////////////////////////////////////////////////////////////////////////////

typedef enum a_e{
	ONE,
	TWO,
	THREE
}A_E;

/* redefine error */
/*
typedef enum a_e{
	ONE,
	TWO,
	THREE
}A_E_T;
*/
/*
typedef enum b_e{
	ONE,
	TWO,
	THREE
}B_E;
*/
//枚举类型： 枚举元素是常量，枚举变量只能赋值枚举常量（枚举变量只有一个确定值），否则要强制转换：A_E p=(enum a_e)2;
//枚举结构定义时：枚举结构名和别名以及元素常量名都不能重复，否则错误，指意不明

typedef enum c_e{
	ONE_,
	TWO_,
	THREE_,
}C_E;
///**/////////////////////////////////////////////////////////////////////////////////////


#define DED 19
#define DED 18 //重复的宏定义会发生编译warning 警告，且后定义的会覆盖前面的
//#define ONE //枚举常量不能重复定义成宏
#define DED 17

//#define EDE //宏定义没有常量值，不能printf打印
#define EDE 16
int main()
{
	AS expl={10,20};
	printf("expl.a=%d,expl.b=%d\n",expl.a,expl.b);

	A_E exam=THREE;
	printf("ONE=%d  exam=%d\n",ONE, exam);
	printf("THREE_=%d\n",THREE_);
	
	printf("DED=%d\n",DED);
  //	#define DED 17
	printf("EDE=%d\n",EDE);
}
