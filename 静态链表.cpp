/*
例题：有若干个盒子，从左至右依次编号为1,2,3,...,n。
可执行以下指令（保证X不等于Y）：
➢L X Y表示把盒子X移动到盒子Y左边（如果X已在Y左边，则忽略该指令）。
➢R X Y表示把盒子X移动到盒子Y右边（如果X已在Y右边，则忽略该指令）。
例如n=6时,初始：123456
执行指令L 1 4： 231456
执行指令R 3 5： 214536
*/

#include <iostream>

using namespace std;

const int N = 1e5 + 10;

struct staticListNode {				//实现一个静态双向链表
	int val;
	int pre;
	int next;
};

struct staticListNode l[N];

int main(void) {
	int n = 0, m = 0;		//一共有n个盒子，m个操作
	cin >> n >> m;

	for (int i = 0; i <= n + 1; i++) {		//0号盒子和n+1号盒子作为哨兵节点
		l[i].val = i;
		l[i].pre = i - 1;
		l[i].next = i + 1;	
	}
	l[0].pre = -1;
	l[n + 1].next = -1;			//处理两个特殊节点

	cout << "移动前盒子编号为：";
	int ptr = 0;
	while (ptr != n) {
		cout << l[l[ptr++].next].val << " ";
	}
	cout << endl;

	while (m--) {
		int x = 0, y = 0;
		char op = ' ';

		cin >> op >> x >> y;
		if (op == 'L') {	//将第x号盒子移动到y号盒子的左侧
			l[l[x].pre].next = l[x].next;
			l[l[x].next].pre = l[x].pre;

			l[x].pre = l[x].next = -1;

			l[l[y].pre].next = x;
			l[x].pre = l[y].pre;
			l[y].pre = x;
			l[x].next = y;
		}
		else {				//将第x号盒子移动到y号盒子的右侧
			l[l[x].pre].next = l[x].next;
			l[l[x].next].pre = l[x].pre;

			l[x].pre = l[x].next = -1;

			l[l[y].next].pre = x;
			l[x].next = l[y].next;
			l[x].pre = y;
			l[y].next = x;
		}
	}

	ptr = 0;
	cout << "移动后盒子编号为：";
	while (ptr != n) {
		cout << l[l[ptr].next].val << " ";
		ptr = l[ptr].next;
	}
	cout << endl;

	return 0;
}