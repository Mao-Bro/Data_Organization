#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
	vector<int> heap;	//我们借助于一个vector数组来维护堆当中的数据
	int size;			//我们使用size记录当前堆当中含有的元素数目

	void buildHeap() {	//将数组维护为大根堆
		for (int i = this->size / 2; i >= 1; i--) {
			this->down(i, this->size);
		}
	}

	void down(int k, int n) {	//对序号为k的元素进行下沉操作，将他下沉到适当的位置
		int max_child = 0, i = k;	//max_child指向的是当前节点的最大孩子的下标位置，i指向的是当前节点

		while (i <= n / 2) {	//堆本身是一种完全二叉树，因此他的最后一个非叶节点的下标为[n / 2]

			//我们需要将当前节点与它的左右孩子当中的较大者比较，因此我们先判断一下当前节点是否存在右孩子，
			//存在的情况下右孩子的数值是否要比左孩子大，两者都满足的情况下，我们将max_child的数值赋值为右孩子的下标
			if (2 * i + 1 <= n && this->heap[2 * i + 1] > this->heap[2 * i]) {
				max_child = 2 * i + 1;
			}
			else max_child = 2 * i;		//完全二叉树的非叶节点是一定存在左孩子节点的

			//接下来我们只需要判断一下该节点是否已经下降到位
			if (this->heap[i] < this->heap[max_child]) {
				int temp = this->heap[i];
				this->heap[i] = this->heap[max_child];
				this->heap[max_child] = temp;

				i = max_child;		//下降不到位，在将数值交换之后，我们还要继续下沉
			}
			else return;			//下降到位之后我们直接结束整个下沉函数
		}
	}

public:
	Heap() {			//构造函数
		this->heap.push_back(-1);
		this->size = 0;
	}

	void add(int _val) {	//向堆当中添加新的元素
		this->heap.push_back(_val);
		this->size++;
	}

	void heap_sort() {		//对堆当中元素进行排序
		int last = this->size;
		while (last != 1) {
			int temp = this->heap[1];
			this->heap[1] = this->heap[last];
			this->heap[last] = temp;

			this->down(1, last - 1);

			last--;
		}
	}

	void print() {		//将堆当中的元素打印输出，便于查看当前堆当中包含的元素
		for (int i = 1; i <= this->size; i++) {
			cout << this->heap[i] << " ";
		}
		cout << endl;
	}
};

int main(void) {
	/* 在这里添加测试程序 */
	return 0;
}