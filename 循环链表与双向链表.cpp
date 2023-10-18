#include <iostream>

using namespace std;

struct Node {
	int val;
	struct Node* next;
	Node() : val(0), next(nullptr) { }
	Node(int _val, struct Node* _next) : val(_val), next(_next) { }
};

class circular_list {	//循环链表
public:
	circular_list() {	//构造函数
		this->head = new Node();
		this->head->next = this->head;
	}

	~circular_list() {	//析构函数
		struct Node* ptr = this->head;
		while (ptr->next != ptr) {
			struct Node* node = ptr->next;
			ptr->next = node->next;

			node->next = nullptr;
			delete(node);
			node = nullptr;
		}
		ptr = nullptr;
		delete(this->head);
		this->head = nullptr;
	}

	bool empty() {		//判空函数
		return this->head->next == this->head;
	}

	void insert_head(int _val) {	//头插法插入新节点
		struct Node* newNode = new Node(_val, this->head->next);
		this->head->next = newNode;
		newNode = nullptr;
	}

	void insert_tail(int _val) {	//尾插法插入新节点
		struct Node* pre_head = this->head;
		while (pre_head->next != this->head) {
			pre_head = pre_head->next;
		}

		struct Node* newNode = new Node(_val, this->head);
		pre_head->next = newNode;

		pre_head = nullptr;
		newNode = nullptr;
	}

	int size() {	//返回不包含哨兵节点在内，循环链表当中有多少个节点
		struct Node* ptr = this->head;
		int count = 0;
		while (ptr->next != this->head) {
			count++;
			ptr = ptr->next;
		}
		return count;
	}

	struct Node* find(int _val) {		//寻找数值为_val的节点，如果有多个节点，则返回第一个节点
		struct Node* ptr = this->head;
		while (ptr->next != this->head) {
			if (ptr->val == _val) return ptr;
			ptr = ptr->next;
		}
		cout << "循环链表当中不存在数值为" << _val << "的节点" << endl;
		return nullptr;
	}

	void print() {
		struct Node* ptr = this->head;
		cout << "当前链表当中包含的元素(包含哨兵节点)为：";
		while (ptr->next != this->head) {
			cout << ptr->val << " ";
			ptr = ptr->next;
		}
		cout << ptr->val << endl;
	}
private:
	struct Node* head;	//循环链表的哨兵节点
};

struct dNode {
	int val;
	struct dNode* pre;
	struct dNode* next;
	dNode() : val(0), pre(nullptr), next(nullptr) { }
	dNode(int _val, struct dNode* _pre, struct dNode* _next) : val(_val), pre(_pre), next(_next) { }
};

class double_dir_list {
public:
	double_dir_list() {		//构造函数
		this->head = new dNode();
		this->tail = new dNode();
		
		this->head->next = this->tail;
		this->tail->pre = this->head;
	}

	~double_dir_list() {	//析构函数
		while (this->head->next != this->tail) {
			struct dNode* node = this->head->next;

			this->head->next = node->next;
			node->next->pre = node->pre;
			node->next = nullptr;
			node->pre = nullptr;

			delete(node);
			node = nullptr;
		}

		this->head->next = nullptr;
		this->tail->pre = nullptr;

		delete(this->head);
		delete(this->tail);
		
		this->head = nullptr;
		this->tail = nullptr;
	}

	struct dNode* find(int _val) {		//返回第一个数值为_val的节点地址
		struct dNode* ptr = this->head;

		while (ptr != this->tail) {
			if (ptr->val == _val) return ptr;
			ptr = ptr->next;
		}
		cout << "双向链表当中不存在数值为" << _val << "的节点" << endl;

		ptr = nullptr;
		return nullptr;
	}

	void delete_ptr(struct dNode* ptr) {	//删除指定节点
		ptr->pre->next = ptr->next;
		ptr->next->pre = ptr->pre;

		ptr->next = nullptr;
		ptr->pre = nullptr;

		delete(ptr);
		ptr = nullptr;
	}

	void delete_val(int _val) {		//删除第一个数值为_val的节点
		struct dNode* ptr = this->find(_val);
		this->delete_ptr(ptr);
	}

	void insert_after(struct dNode* node, int _val) {
		if (node == this->tail) {
			cout << "不可以在尾部节点后面插入节点" << endl;
			return;
		}

		struct dNode* newNode = new dNode(_val, node, node->next);
		node->next->pre = newNode;
		node->next = newNode;

		node = nullptr;
		newNode = nullptr;
	}

	void insert_before(struct dNode* node, int _val) {
		if (node == this->head) {
			cout << "不可以在头部节点前面插入节点" << endl;
			return;
		}

		struct dNode* newNode = new dNode(_val, node->pre, node);
		node->pre->next = newNode;
		node->pre = newNode;

		node = nullptr;
		newNode = nullptr;
	}

	void print() {
		struct dNode* ptr = this->head->next;
		cout << "当前双向链表当中包含的元素为（从头到尾）：";
		while (ptr != this->tail) {
			cout << ptr->val << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}

	struct dNode* head;	//双向链表的哨兵头节点
	struct dNode* tail; //双向链表的哨兵尾节点
};

int main(void) {
	/* 在此处添加测试程序 */
	return 0;
}
