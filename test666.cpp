#include<stdio.h>
#define m  100 //��0Ԫ�ظ���
typedef struct element
{
	int val;//ֵ��
	int row,col;
}elem;
elem b[m],c[m];//����洢����
void create(int row,int col,int &i)
{
	int p,q,a;
	i = 0;
	printf("������ϡ�����:\n");
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
//n-��,t-��0Ԫ�ظ���
{
	int i,j,k;
	int *num = new int[n],*pot =new int[n];
	for(j = 0; j < n; j++)
		num[j] = 0; //Ԥ����׶�
	for(i = 0;i < t; i++)
		num[b[i].col]++;
	for(pot[0] = 0,j = 1; j < n;j++)
		pot[j] = pot[j -1] +num[j-1];
	for(i = 0; i < t;i++)//ת�ý׶�
	{
		j = b[i].col;//ȡ�к�
		k = pot[j];//ȡ�ж�λָ��ֵ
		c[k].row = j,c[k].col = b[i].row,c[k].val = b[i].val;
		pot[j] ++;//�޸Ķ�λָ��
	}
}
void main()
{
	int ro,co,a;
	printf("������ϡ�������к�����:");
	scanf("%d%d",&ro,&co);
	create(ro,co,a);
	transpose(b,c,co,a);
	printf("ת�þ���:\n");
	print(c,co,ro);
}
