#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
	vector<int> heap;	//���ǽ�����һ��vector������ά���ѵ��е�����
	int size;			//����ʹ��size��¼��ǰ�ѵ��к��е�Ԫ����Ŀ

	void buildHeap() {	//������ά��Ϊ�����
		for (int i = this->size / 2; i >= 1; i--) {
			this->down(i, this->size);
		}
	}

	void down(int k, int n) {	//�����Ϊk��Ԫ�ؽ����³������������³����ʵ���λ��
		int max_child = 0, i = k;	//max_childָ����ǵ�ǰ�ڵ������ӵ��±�λ�ã�iָ����ǵ�ǰ�ڵ�

		while (i <= n / 2) {	//�ѱ�����һ����ȫ������������������һ����Ҷ�ڵ���±�Ϊ[n / 2]

			//������Ҫ����ǰ�ڵ����������Һ��ӵ��еĽϴ��߱Ƚϣ�����������ж�һ�µ�ǰ�ڵ��Ƿ�����Һ��ӣ�
			//���ڵ�������Һ��ӵ���ֵ�Ƿ�Ҫ�����Ӵ����߶����������£����ǽ�max_child����ֵ��ֵΪ�Һ��ӵ��±�
			if (2 * i + 1 <= n && this->heap[2 * i + 1] > this->heap[2 * i]) {
				max_child = 2 * i + 1;
			}
			else max_child = 2 * i;		//��ȫ�������ķ�Ҷ�ڵ���һ���������ӽڵ��

			//����������ֻ��Ҫ�ж�һ�¸ýڵ��Ƿ��Ѿ��½���λ
			if (this->heap[i] < this->heap[max_child]) {
				int temp = this->heap[i];
				this->heap[i] = this->heap[max_child];
				this->heap[max_child] = temp;

				i = max_child;		//�½�����λ���ڽ���ֵ����֮�����ǻ�Ҫ�����³�
			}
			else return;			//�½���λ֮������ֱ�ӽ��������³�����
		}
	}

public:
	Heap() {			//���캯��
		this->heap.push_back(-1);
		this->size = 0;
	}

	void add(int _val) {	//��ѵ�������µ�Ԫ��
		this->heap.push_back(_val);
		this->size++;
	}

	void heap_sort() {		//�Զѵ���Ԫ�ؽ�������
		int last = this->size;
		while (last != 1) {
			int temp = this->heap[1];
			this->heap[1] = this->heap[last];
			this->heap[last] = temp;

			this->down(1, last - 1);

			last--;
		}
	}

	void print() {		//���ѵ��е�Ԫ�ش�ӡ��������ڲ鿴��ǰ�ѵ��а�����Ԫ��
		for (int i = 1; i <= this->size; i++) {
			cout << this->heap[i] << " ";
		}
		cout << endl;
	}
};

int main(void) {
	/* ��������Ӳ��Գ��� */
	return 0;
}