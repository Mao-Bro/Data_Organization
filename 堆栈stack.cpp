//#include <iostream>
//#include <stdlib.h>
//
//using namespace std;
//
//class linear_stack {	//���Զ�ջ
//public:
//	linear_stack() {	//��ջ�޲ι��캯����Ĭ������Ϊ2
//		this->size = 2;
//		this->bottom = (int*)malloc(3 * sizeof(int));
//		this->top = bottom;
//		if (this->top && this->bottom) {
//			cout << "��ջ�����ɹ�" << endl;
//		}
//	}
//
//	linear_stack(int _size) {	//��ջ���ι��캯��������Ϊ��ջ�������
//		this->size = _size;
//		this->bottom = (int*)malloc(this->size * sizeof(int));
//		this->top = bottom;
//		if (this->top && this->bottom) {
//			cout << "��ջ�����ɹ�" << endl;
//		}
//	}
//
//	bool full() {
//		if (this->size == (top - bottom)) return true;
//		else return false;
//	}
//
//	bool empty() {
//		if (this->top == this->bottom) return true;
//		return false;
//	}
//
//	void push(int _val) {
//		if (this->full()) {		//��ǰ�Ķ�ջ�Ѿ����ˣ����ǲ��üӱ����ݲ��ԣ��������ݣ�
//			int* _bottom = (int*)malloc(2 * this->size * sizeof(int));
//			int* _top = _bottom + 1;
//
//			for (int* ptr = this->bottom; ptr <= this->top; ptr++, _top++) *_top = *ptr;
//
//			this->bottom = _bottom;
//			this->top = _top - 1;
//			this->size = 2 * this->size;
//
//			_top = nullptr;
//			_bottom = nullptr;
//		}
//		//��ǰ�Ķ�ջû����������˵�Ѿ�����˼ӱ����ݣ�����ֱ��ѹ�����ݣ�
//		this->top++;
//		*this->top = _val;
//	}
//
//	void pop() {
//		if (this->empty()) cout << "��ǰ��ջΪ�գ��޷�ʵ�ֵ�ջ����" << endl;
//		else this->top--;
//	}
//
//	int peek() {
//		if (this->empty()) {
//			cout << "��ǰ��ջΪ�գ��޷�ȡ��ջ��Ԫ��" << endl;
//			return -1;
//		}
//		else return *this->top;
//	}
//
//	void clear() {	//��ն�ջ���е�����Ԫ��
//		this->top = this->bottom;
//	}
//
//private:
//	int size;		//size������¼��ǰ��ջ��Ԫ��������������ǲ���Ҫ��¼��ǰ��Ԫ����Ŀ��top-bottom���ɣ�
//	int* bottom;	//����bottomΪջ��ָ�룻
//	int* top;		//����topΪջ��ָ�룻
//};
//
//struct Node {
//	int val;
//	struct Node* next;
//
//	Node(): val(0) , next(nullptr) { }
//	Node(int _val): val(_val) , next(nullptr) { }
//};
//
//class link_stack {
//public:
//	link_stack() {
//		this->head = new Node();
//		this->top = this->head;
//		this->_size = 0;
//		cout << "��ջ�����ɹ�" << endl;
//	}
//
//	int size() {
//		return this->_size;
//	}
//
//	bool empty() {
//		if (this->_size == 0) return true;
//		return false;
//	}
//
//	void clear() {
//		this->_size = 0;
//		this->head->next = nullptr;
//		this->top = this->head;
//	}
//
//	void push(int _val) {
//		struct Node* newNode = new Node(_val);
//		this->top->next = newNode;
//		this->top = newNode;
//		this->_size++;
//
//		newNode = nullptr;
//		delete(newNode);
//	}
//
//	void pop() {
//		if (this->empty()) cout << "��ǰ��ջΪ�գ��޷�ʵ�ֵ�ջ����" << endl;
//		else {
//			struct Node* ptr = this->head;
//			while (ptr->next != this->top) ptr = ptr->next;
//			ptr->next = nullptr;
//			this->top = ptr;
//			this->_size--;
//
//			ptr = nullptr;
//			delete(ptr);
//		}
//	}
//
//	int peek() {
//		if (this->empty()) {
//			cout << "��ǰ��ջΪ�գ��޷�ʵ��ȡջ������" << endl;
//			return -1;
//		}
//		return this->top->val;
//	}
//
//private:
//	struct Node* head;	//����������ڱ�ͷ�ڵ㣬���Ƕ�ջ�ĵ׽ڵ㣻
//	struct Node* top;	//�����е�β���ڵ㣬�Ƕ�ջ��ջ���ڵ㣻
//	int _size;			//���ڼ�¼��ǰ��ջ���к��ж���Ԫ�أ���������ʽջ�����û���������һ˵��
//};
//
//int main(void) {
//	/*��������������Ĳ��Գ���*/
//	return 0;
//}