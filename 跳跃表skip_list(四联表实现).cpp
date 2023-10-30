////����������У���ʹ����������ķ�ʽʵ��������
////����ʵ�ʵĿ������У����ַ�ʽ�ǲ�̫���еģ�
////��Ϊ����ÿһ���ڵ㶼��洢һ�����ݣ�
////��������ʵ�ʵ������������ʹ�õ����ݺ��п����Ƿǳ���ģ�
////����һ���ʵ��һ��ֻ�洢һ�����ݣ��������ɶ�������ķ�ʽʵ������
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//
////Ϊ��ʵ����Ծ���������ȸ���������ڵ�ṹ�壺
//struct Node {	
//	int val;
//	struct Node* up;
//	struct Node* down;
//	struct Node* pre;
//	struct Node* next;
//
//	Node(): val(0), up(nullptr), down(nullptr), pre(nullptr), next(nullptr) { }
//	Node(int _val): val(_val), up(nullptr), down(nullptr), pre(nullptr), next(nullptr) { }
//};
//
//class SkipList {
//public:
//	SkipList() {
//		this->head = new Node(INT_MIN);
//		this->tail = new Node(INT_MAX);
//
//		this->head->next = this->tail;
//		this->tail->pre = this->head;
//		this->size = 0;
//	}
//
//	~SkipList() {
//		this->clear();
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
//	//�������в���һ������Ϊ_val�Ľڵ㣬����ɹ�ʱ��������true�����򷵻�false
//	bool insert(int _val) {
//		//�������Ѿ������иýڵ㣬ֱ�ӷ��ز���ɹ�
//		struct Node* insertPos = this->find(_val);
//		if (insertPos->val == _val) return true;
//
//		//�����в��������ýڵ㣬������Ҫ��insertPos�������ýڵ�
//		//��1��������������ײ����ýڵ�
//		struct Node* newNode = new Node(_val);
//
//		newNode->next = insertPos->next;
//		insertPos->next->pre = newNode;
//		newNode->pre = insertPos;
//		insertPos->next = newNode;
//
//		this->size++;
//
//		insertPos = nullptr;
//		//��2��������Ҫ��Ӳ�Ҿ����Ƿ�Ҫ���ýڵ���������һ��
//		this->seed = time(0);
//		srand(this->seed);
//		while (this->OneOrZero()) {
//			//��Ӳ���׳����棬��������Ҫ���½ڵ�����һ��ʱ�������ֻ�����һ�����⣺��ǰ�㻹����һ����
//			//�������ҵ�newNode����һ��������Чup�Ľڵ�ptr
//			struct Node* ptr = newNode->pre;
//			while (ptr && ptr->up == nullptr) ptr = ptr->pre;
//
//			struct Node* newNode1 = new Node(_val);
//
//			//��ǰ�㲻����߲㣬����ֱ������һ��ptrλ�õĺ����ٲ���һ��newNode����
//			if (ptr != nullptr) {
//				ptr = ptr->up;	//��ptr��������һ��
//
//				newNode1->next = ptr->next;
//				ptr->next->pre = newNode1;
//				ptr->next = newNode1;
//				newNode1->pre = ptr;
//
//				newNode1->down = newNode;
//				newNode->up = newNode1;
//
//				ptr = nullptr;
//			}
//			//��ǰ���Ѿ�����߲㣬������Ҫ�ȴ����µ�һ�㣬�ٽ�newNode���뵽���²㣨ͬʱҲ����߲㣩�ڱ��׽ڵ����һ��λ��
//			else {
//				//�ȴ������µ�һ��
//				struct Node* newHead = new Node(INT_MIN);
//				struct Node* newTail = new Node(INT_MAX);
//
//				newHead->next = newTail;
//				newTail->pre = newHead;
//
//				newHead->down = this->head;
//				this->head->up = newHead;
//
//				newTail->down = this->tail;
//				this->tail->up = newTail;
//
//				//��newNode1���뵽���²�
//				newNode1->next = this->tail;
//				this->tail->pre = newNode1;
//
//				newNode1->pre = this->head;
//				this->head->next = newNode1;
//
//				newNode1->down = newNode;
//				newNode->up = newNode1;
//			}
//
//			newNode = newNode1;
//		}
//	}
//
//	//������������Ϊ_val�Ľڵ�ɾ��
//	bool erase(int _val) {
//		struct Node* ptr = this->find(_val);
//		if (ptr == nullptr) return false;
//
//		if (ptr->val != _val) return true;	//˵��������ѹ�������и�����
//		else {
//			//������ڸ����ݽڵ㣬ptrָ��Ľ�������ײ�Ľڵ㣬����Ҫ�ӵ�����ȷ��������������Ŀ��ڵ�ɾ��
//			while (ptr) {
//				ptr->pre->next = ptr->next;
//				ptr->next->pre = ptr->pre;
//				ptr->next = nullptr;
//				ptr->pre = nullptr;
//				ptr->down = nullptr;
//
//				struct Node* ptr_up = ptr->up;
//				ptr->up = nullptr;
//				delete(ptr);
//
//				ptr = ptr_up;
//				ptr_up = nullptr;
//			}
//			this->size--;
//		}
//	}
//
//private:
//	struct Node* head;	//head��tailָ�뽫ָ�����ϲ���β�ڱ��ڵ�
//	struct Node* tail;
//	int size;			//size����ֵ��¼�˵�ǰ��Ծ���д洢�����ݸ���
//	unsigned int seed;
//
//	//����������Ͳ��һ����ֵΪ_val�Ľڵ㣬�������������һ���ڵ㣬�򷵻�_val�ڵ�����λ�����ĵ�һ���ڵ�
//	struct Node* find(int _val) {	
//		struct Node* cur = this->head;
//		while (1) {
//			while (cur->val <= _val) cur = cur->next;
//			cur = cur->pre;
//			if (cur->down != nullptr) {
//				cur = cur->down;
//				continue;
//			}
//			return cur;
//		}
//	}
//
//	bool OneOrZero() {
//		return rand() % 2;
//	}
//
//	void clear() {		//�����Ծ���е��������ݣ���ɶ�����ĳ�ʼ��
//		//��������Ҫ����Ծ���е����нڵ����
//		struct Node* rootHead = this->head;
//		struct Node* rootTail = this->tail;
//
//		while (rootHead->down && rootTail->down) {
//			rootHead = rootHead->down;
//			rootTail = rootTail->down;
//		}
//
//		while (rootHead->next != rootTail) {
//			this->erase(rootHead->next->val);
//		}
//		//Ȼ��Ҫ����Ծ��Ĳ���ѹ��Ϊһ��
//		struct Node* ph = this->head;
//		struct Node* pt = this->tail;
//
//		while (this->head != rootHead) {
//			ph = this->head;
//			pt = this->tail;
//			this->head = this->head->down;
//			this->tail = this->tail->down;
//
//			ph->down = nullptr;
//			ph->next = nullptr;
//			pt->down = nullptr;
//			pt->pre = nullptr;
//
//			delete(ph);
//			delete(pt);
//		}
//
//		ph = nullptr;
//		pt = nullptr;
//		rootHead = nullptr;
//		rootTail = nullptr;
//	}
//};
//
//int main(void) {
//	/*�ڴ˴������Ĳ��Գ���*/
//	SkipList sl = SkipList();
//
//	for (int i = 0; i < 10; i++) {
//		int _val = 0;
//		cin >> _val;
//		sl.insert(_val);
//	}
//
//	return 0;
//}