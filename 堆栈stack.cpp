#include <iostream>
#include <stdlib.h>

using namespace std;

class linear_stack {	//线性堆栈
public:
	linear_stack() {	//堆栈无参构造函数，默认容量为2
		this->size = 2;
		this->bottom = (int*)malloc(3 * sizeof(int));
		this->top = bottom;
		if (this->top && this->bottom) {
			cout << "堆栈创建成功" << endl;
		}
	}

	linear_stack(int _size) {	//堆栈含参构造函数，参数为堆栈最大容量
		this->size = _size;
		this->bottom = (int*)malloc(this->size * sizeof(int));
		this->top = bottom;
		if (this->top && this->bottom) {
			cout << "堆栈创建成功" << endl;
		}
	}

	bool full() {
		if (this->size == (top - bottom)) return true;
		else return false;
	}

	bool empty() {
		if (this->top == this->bottom) return true;
		return false;
	}

	void push(int _val) {
		if (this->full()) {		//当前的堆栈已经满了，我们采用加倍扩容策略，对其扩容；
			int* _bottom = (int*)malloc(2 * this->size * sizeof(int));
			int* _top = _bottom + 1;

			for (int* ptr = this->bottom; ptr <= this->top; ptr++, _top++) *_top = *ptr;

			this->bottom = _bottom;
			this->top = _top - 1;
			this->size = 2 * this->size;

			_top = nullptr;
			_bottom = nullptr;
		}
		//当前的堆栈没有满，或者说已经完成了加倍扩容，我们直接压入数据；
		this->top++;
		*this->top = _val;
	}

	void pop() {
		if (this->empty()) cout << "当前堆栈为空，无法实现弹栈操作" << endl;
		else this->top--;
	}

	int peek() {
		if (this->empty()) {
			cout << "当前堆栈为空，无法取得栈顶元素" << endl;
			return -1;
		}
		else return *this->top;
	}

	void clear() {	//清空堆栈当中的所有元素
		this->top = this->bottom;
	}

private:
	int size;		//size用来记录当前堆栈的元素最大容量，我们不需要记录当前的元素数目，top-bottom即可；
	int* bottom;	//定义bottom为栈底指针；
	int* top;		//定义top为栈顶指针；
};

struct Node {
	int val;
	struct Node* next;

	Node(): val(0) , next(nullptr) { }
	Node(int _val): val(_val) , next(nullptr) { }
};

class link_stack {
public:
	link_stack() {
		this->head = new Node();
		this->top = this->head;
		this->_size = 0;
		cout << "堆栈创建成功" << endl;
	}

	int size() {
		return this->_size;
	}

	bool empty() {
		if (this->_size == 0) return true;
		return false;
	}

	void clear() {
		this->_size = 0;
		this->head->next = nullptr;
		this->top = this->head;
	}

	void push(int _val) {
		struct Node* newNode = new Node(_val);
		this->top->next = newNode;
		this->top = newNode;
		this->_size++;

		newNode = nullptr;
		delete(newNode);
	}

	void pop() {
		if (this->empty()) cout << "当前堆栈为空，无法实现弹栈操作" << endl;
		else {
			struct Node* ptr = this->head;
			while (ptr->next != this->top) ptr = ptr->next;
			ptr->next = nullptr;
			this->top = ptr;
			this->_size--;

			ptr = nullptr;
			delete(ptr);
		}
	}

	int peek() {
		if (this->empty()) {
			cout << "当前堆栈为空，无法实现取栈顶操作" << endl;
			return -1;
		}
		return this->top->val;
	}

private:
	struct Node* head;	//既是链表的哨兵头节点，又是堆栈的底节点；
	struct Node* top;	//链表当中的尾部节点，是堆栈的栈顶节点；
	int _size;			//用于记录当前堆栈当中含有多少元素，由于是链式栈，因此没有最大容量一说；
};

int main(void) {
	/*在这里可以添加你的测试程序*/
	return 0;
}
