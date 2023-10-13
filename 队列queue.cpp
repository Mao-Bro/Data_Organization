//#include <iostream>
//
//using namespace std;
//
//struct Node {
//	int val;
//	struct Node* next;
//	Node(): val(0), next(nullptr) { }
//	Node(int _val): val(_val), next(nullptr) { }
//};
//
//class link_queue {
//public:
//	link_queue() {
//		this->_size = 0;
//		this->front = new Node();
//		this->rear = this->front;
//	}
//
//	~link_queue() {
//		struct Node* pre = this->front;
//		struct Node* ptr = this->front->next;
//
//		while (ptr) {
//			delete(pre);
//			pre = ptr;
//			ptr = ptr->next;
//		}
//		delete(pre);
//
//		ptr = nullptr;
//		pre = nullptr;
//
//		this->front = nullptr;
//		this->rear = nullptr;
//	}
//
//	int size() {
//		return this->_size;
//	}
//
//	bool empty() {
//		return this->front == this->rear;
//	}
//
//	int peek() {
//		if (!this->empty()) return this->front->next->val;
//		else cout << "����Ϊ��" << endl;
//	}
//
//	void clear() {
//		this->~link_queue();
//		this->_size = 0;
//		this->front = new Node();
//		this->rear = this->front;
//	}
//
//	void push(int _val) {
//		struct Node* newNode = new Node(_val);
//		this->rear->next = newNode;
//		this->rear = newNode;
//		newNode = nullptr;
//		this->_size++;
//	}
//
//	void pop() {
//		if (this->empty()) cout << "����Ϊ��" << endl;
//		else {
//			struct Node* ptr = this->front->next;
//			this->front->next = ptr->next;
//			ptr->next = nullptr;
//			delete(ptr);
//			ptr = nullptr;
//			this->_size--;
//		}
//	}
//private:
//	struct Node* front;
//	struct Node* rear;
//	int _size;
//};
//
//class linear_queue {
//public:
//	linear_queue() {
//		this->q = (int*)malloc(2 * sizeof(int));	//���г�ʼ��������Ϊ2�����üӱ����ݲ��ԣ�
//		this->maxsize = 2;
//
//		this->front = 0;
//		this->rear = this->front;
//		this->count = 0;
//	}
//
//	~linear_queue() {
//		delete[] this->q;
//	}
//
//	int size() {
//		return this->count;
//	}
//
//	bool full() {
//		return this->count == this->maxsize;
//	}
//
//	void push(int _val) {
//		if (this->full()) {			//��ǰ�����Ѿ��ﵽ���������������Ҫ�������������Ԫ�أ�
//			int* newMem = (int*)malloc(2 * this->maxsize * sizeof(int));
//			this->maxsize = this->maxsize * 2;
//
//			int i = 0;
//			int j = this->front;
//			int cont = this->maxsize / 2;
//			while (cont--) {
//				newMem[i++] = this->q[(j++) % (this->maxsize / 2)];
//			}
//
//			this->q = newMem;
//			newMem = nullptr;
//
//			this->front = 0;
//			this->rear = this->maxsize / 2;
//			this->count = this->maxsize / 2;
//
//			this->q[this->rear] = _val;
//			this->rear++;
//			this->count++;
//		}
//		else {						//��ǰ���л�δ�ﵽ������������ǿ���ֱ�������Ԫ�أ�
//			this->q[this->rear] = _val;
//			this->rear = (this->rear + 1) % maxsize;
//			this->count++;
//		}
//	}
//
//	bool empty() {
//		return this->count == 0;
//	}
//
//	void pop() {
//		if (this->empty()) cout << "��ǰ����Ϊ��" << endl;
//		else {
//			this->front = (this->front + 1) % this->maxsize;
//			this->count--;
//		}
//	}
//
//	int peek() {
//		if (this->empty()) cout << "��ǰ����Ϊ��" << endl;
//		return this->q[this->front];
//	}
//
//	void clear() {
//		this->~linear_queue();
//
//		this->q = (int*)malloc(2 * sizeof(int));
//		this->maxsize = 2;
//
//		this->front = 0;
//		this->rear = this->front;
//		this->count = 0;
//	}
//private:
//	int front;
//	int rear;
//	int count;
//	int maxsize;
//	int* q;
//};
//
//int main(void) {
//	/* �ڴ˴������Ĳ��Գ��� */
//	linear_queue q = linear_queue();
//	return 0;
//}