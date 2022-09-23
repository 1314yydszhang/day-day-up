#include<stdio.h>
int main()
{
	int a[10] = {0};
	int* pa = a;
	char* pc = a;
	printf("%p\n", pa);
	printf("%p\n", pa+1);//加一个整型 
	printf("%p\n", pc);
	printf("%p\n", pc+1);//加一个字符
	return 0;

}
int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int* p1 , *p2;
	p1 = &a;//& 是取地址符号，取的是地址
	        //*是解引用符号，取p指针指向的地址的值，指针指向内容（* 在定义指针变量时是指针标志）
	p2 = &(*(a+5));//扩展：*(a+5)=a[5] 也是跟地址有关哦
	printf("p1存储的值：%d\n", *p1);
	printf("p2存储的值：%d\n", *p2);
	printf("p1-1存储的值：%d\n", *(p1+1));
	printf("这又是什么呢%d\n", *p1-1);
	printf("这呢：%d\n", *(p1 + 3));
	printf("这个呢：%d\n", *p1 + 3);
	//如果换成char的话，字节大小就会变成1，后面会有更多内容
	return 0;
}
int main()
{
	int a[10] = {0};
	int* pa = a;
	int*pa1=&(*(a+5));
	
	printf("%p\n", pa1);
	printf("%p\n", pa);
	printf("%d\n", pa1 - pa);//字节大小为4

	char b[10] = { 0 };
	char* pa2 = b;
	char* pa3 = &(*(b + 5));
	printf("%p\n", pa2);
	printf("%p\n", pa3);
	printf("%d\n", pa3 - pa2);//字节大小为1
	return 0;

}
