//#include <iostream>
//
//using namespace std;
//
//struct Node {
//	int val;
//	struct Node* next;
//	Node() : val(0), next(nullptr) { }
//	Node(int _val, struct Node* _next) : val(_val), next(_next) { }
//};
//
//class circular_list {	//ѭ������
//public:
//	circular_list() {	//���캯��
//		this->head = new Node();
//		this->head->next = this->head;
//	}
//
//	~circular_list() {	//��������
//		struct Node* ptr = this->head;
//		while (ptr->next != ptr) {
//			struct Node* node = ptr->next;
//			ptr->next = node->next;
//
//			node->next = nullptr;
//			delete(node);
//			node = nullptr;
//		}
//		ptr = nullptr;
//		delete(this->head);
//		this->head = nullptr;
//	}
//
//	bool empty() {		//�пպ���
//		return this->head->next == this->head;
//	}
//
//	void insert_head(int _val) {	//ͷ�巨�����½ڵ�
//		struct Node* newNode = new Node(_val, this->head->next);
//		this->head->next = newNode;
//		newNode = nullptr;
//	}
//
//	void insert_tail(int _val) {	//β�巨�����½ڵ�
//		struct Node* pre_head = this->head;
//		while (pre_head->next != this->head) {
//			pre_head = pre_head->next;
//		}
//
//		struct Node* newNode = new Node(_val, this->head);
//		pre_head->next = newNode;
//
//		pre_head = nullptr;
//		newNode = nullptr;
//	}
//
//	int size() {	//���ز������ڱ��ڵ����ڣ�ѭ���������ж��ٸ��ڵ�
//		struct Node* ptr = this->head;
//		int count = 0;
//		while (ptr->next != this->head) {
//			count++;
//			ptr = ptr->next;
//		}
//		return count;
//	}
//
//	struct Node* find(int _val) {		//Ѱ����ֵΪ_val�Ľڵ㣬����ж���ڵ㣬�򷵻ص�һ���ڵ�
//		struct Node* ptr = this->head;
//		while (ptr->next != this->head) {
//			if (ptr->val == _val) return ptr;
//			ptr = ptr->next;
//		}
//		cout << "ѭ�������в�������ֵΪ" << _val << "�Ľڵ�" << endl;
//		return nullptr;
//	}
//
//	void print() {
//		struct Node* ptr = this->head;
//		cout << "��ǰ�����а�����Ԫ��(�����ڱ��ڵ�)Ϊ��";
//		while (ptr->next != this->head) {
//			cout << ptr->val << " ";
//			ptr = ptr->next;
//		}
//		cout << ptr->val << endl;
//	}
//private:
//	struct Node* head;	//ѭ��������ڱ��ڵ�
//};
//
//struct dNode {
//	int val;
//	struct dNode* pre;
//	struct dNode* next;
//	dNode() : val(0), pre(nullptr), next(nullptr) { }
//	dNode(int _val, struct dNode* _pre, struct dNode* _next) : val(_val), pre(_pre), next(_next) { }
//};
//
//class double_dir_list {
//public:
//	double_dir_list() {		//���캯��
//		this->head = new dNode();
//		this->tail = new dNode();
//		
//		this->head->next = this->tail;
//		this->tail->pre = this->head;
//	}
//
//	~double_dir_list() {	//��������
//		while (this->head->next != this->tail) {
//			struct dNode* node = this->head->next;
//
//			this->head->next = node->next;
//			node->next->pre = node->pre;
//			node->next = nullptr;
//			node->pre = nullptr;
//
//			delete(node);
//			node = nullptr;
//		}
//
//		this->head->next = nullptr;
//		this->tail->pre = nullptr;
//
//		delete(this->head);
//		delete(this->tail);
//		
//		this->head = nullptr;
//		this->tail = nullptr;
//	}
//
//	struct dNode* find(int _val) {		//���ص�һ����ֵΪ_val�Ľڵ��ַ
//		struct dNode* ptr = this->head;
//
//		while (ptr != this->tail) {
//			if (ptr->val == _val) return ptr;
//			ptr = ptr->next;
//		}
//		cout << "˫�������в�������ֵΪ" << _val << "�Ľڵ�" << endl;
//
//		ptr = nullptr;
//		return nullptr;
//	}
//
//	void delete_ptr(struct dNode* ptr) {	//ɾ��ָ���ڵ�
//		ptr->pre->next = ptr->next;
//		ptr->next->pre = ptr->pre;
//
//		ptr->next = nullptr;
//		ptr->pre = nullptr;
//
//		delete(ptr);
//		ptr = nullptr;
//	}
//
//	void delete_val(int _val) {		//ɾ����һ����ֵΪ_val�Ľڵ�
//		struct dNode* ptr = this->find(_val);
//		this->delete_ptr(ptr);
//	}
//
//	void insert_after(struct dNode* node, int _val) {
//		if (node == this->tail) {
//			cout << "��������β���ڵ�������ڵ�" << endl;
//			return;
//		}
//
//		struct dNode* newNode = new dNode(_val, node, node->next);
//		node->next->pre = newNode;
//		node->next = newNode;
//
//		node = nullptr;
//		newNode = nullptr;
//	}
//
//	void insert_before(struct dNode* node, int _val) {
//		if (node == this->head) {
//			cout << "��������ͷ���ڵ�ǰ�����ڵ�" << endl;
//			return;
//		}
//
//		struct dNode* newNode = new dNode(_val, node->pre, node);
//		node->pre->next = newNode;
//		node->pre = newNode;
//
//		node = nullptr;
//		newNode = nullptr;
//	}
//
//	void print() {
//		struct dNode* ptr = this->head->next;
//		cout << "��ǰ˫�������а�����Ԫ��Ϊ����ͷ��β����";
//		while (ptr != this->tail) {
//			cout << ptr->val << " ";
//			ptr = ptr->next;
//		}
//		cout << endl;
//	}
//
//	struct dNode* head;	//˫��������ڱ�ͷ�ڵ�
//	struct dNode* tail; //˫��������ڱ�β�ڵ�
//};
//
//int main(void) {
//	/* �ڴ˴���Ӳ��Գ��� */
//	return 0;
//}