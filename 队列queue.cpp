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
//		else cout << "队列为空" << endl;
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
//		if (this->empty()) cout << "队列为空" << endl;
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
//		this->q = (int*)malloc(2 * sizeof(int));	//队列初始容量设置为2，采用加倍扩容策略；
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
//		if (this->full()) {			//当前队列已经达到最大容量，我们需要先扩容再入队新元素；
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
//		else {						//当前队列还未达到最大容量，我们可以直接入队新元素；
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
//		if (this->empty()) cout << "当前队列为空" << endl;
//		else {
//			this->front = (this->front + 1) % this->maxsize;
//			this->count--;
//		}
//	}
//
//	int peek() {
//		if (this->empty()) cout << "当前队列为空" << endl;
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
//	/* 在此处添加你的测试程序 */
//	linear_queue q = linear_queue();
//	return 0;
//}