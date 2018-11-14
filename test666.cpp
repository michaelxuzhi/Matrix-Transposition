#include<stdio.h>
#define m  100 //非0元素个数
typedef struct element
{
	int val;//值域
	int row,col;
}elem;
elem b[m],c[m];//定义存储数组
void create(int row,int col,int &i)
{
	int p,q,a;
	i = 0;
	printf("请输入稀疏矩阵:\n");
	for(p = 0;q<col;q++)
	{
		scanf("%d",&a);
	}
	if(a != 0)
	{
		b[i].row = p;
		b[i].col = q;
		b[i].val = a;
		i++;
	}
}
void print(elem a[],int i ,int j)
{
	int k = 0;
	for(int p = 0; p < i;p++)
	{
		for(int q= 0; q<j; q++)
			if(a[k].row == p && a[k].col == q)
			{
				printf("%d",a[k].val);
				i++;
			}
			else printf("0");
	}
	printf("\n");
}
void transpose(elem b[],elem c[],int n, int t)
//n-列,t-非0元素个数
{
	int i,j,k;
	int *num = new int[n],*pot =new int[n];
	for(j = 0; j < n; j++)
		num[j] = 0; //预处理阶段
	for(i = 0;i < t; i++)
		num[b[i].col]++;
	for(pot[0] = 0,j = 1; j < n;j++)
		pot[j] = pot[j -1] +num[j-1];
	for(i = 0; i < t;i++)//转置阶段
	{
		j = b[i].col;//取列号
		k = pot[j];//取行定位指针值
		c[k].row = j,c[k].col = b[i].row,c[k].val = b[i].val;
		pot[j] ++;//修改定位指针
	}
}
void main()
{
	int ro,co,a;
	printf("请输入稀疏矩阵的行和列数:");
	scanf("%d%d",&ro,&co);
	create(ro,co,a);
	transpose(b,c,co,a);
	printf("转置矩阵:\n");
	print(c,co,ro);
}
