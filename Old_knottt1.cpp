#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 100010  //���������Դ����ô��Ľڵ�

typedef struct Node
{
	int v;
	int next;
}Node;

Node a[maxn];  //����
int vis[maxn]; //��¼���ʹ��ľ���ֵ
int head, n;  //ͷ�ڵ㣬�ڵ�����

int main()
{
	int last = -1, address;
	int headnode1 = 100001, p1 = headnode1, headnode2 = 100002, p2 = headnode2;
	memset(vis, 0, sizeof(vis));

	scanf("%d%d", &head, &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &address);
		scanf("%d%d", &a[address], &a[address].next);
	}

	for (int i = head; i != -1; i = a[i].next)
	{
		if (vis[abs(a[i].v)])
		{
			a[p2].next = i;
			p2 = i;
		}
		else
		{
			vis[abs(a[i].v)] = 1;
			a[p1].next = i;
			p1 = i;
		}
	}

	a[p1].next = -1;
	a[p2].next = -1;


	printf("output::\n");
	for (int i = a[headnode1].next; i != -1; i = a[i].next)
	{
		printf("Value: %d, Next: %d\n", a[i].v, a[i].next);
	}

	printf("output:\n");
	for (int i = a[headnode2].next; i != -1; i = a[i].next) {
		printf("Value: %d, Next: %d\n", a[i].v, a[i].next);
	}

	return 0;
}
