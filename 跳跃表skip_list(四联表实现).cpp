////在这个程序当中，我使用了四联表的方式实现了跳表，
////但在实际的开发当中，这种方式是不太可行的，
////因为它的每一个节点都会存储一次数据，
////而我们在实际的软件开发当中使用的数据很有可能是非常大的，
////因此我还会实现一种只存储一次数据，但会生成多个索引的方式实现跳表
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//
////为了实现跳跃表，我们首先给出四联表节点结构体：
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
//	//向跳表当中插入一个数据为_val的节点，插入成功时函数返回true，否则返回false
//	bool insert(int _val) {
//		//跳表当中已经包含有该节点，直接返回插入成功
//		struct Node* insertPos = this->find(_val);
//		if (insertPos->val == _val) return true;
//
//		//跳表当中并不包含该节点，我们需要在insertPos后面插入该节点
//		//（1）我们首先在最底层插入该节点
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
//		//（2）我们需要抛硬币决定是否要将该节点上升到上一层
//		this->seed = time(0);
//		srand(this->seed);
//		while (this->OneOrZero()) {
//			//当硬币抛出正面，即我们需要将新节点上升一层时，我们又会面临一个问题：当前层还有上一层吗
//			//我们先找到newNode左侧第一个含有有效up的节点ptr
//			struct Node* ptr = newNode->pre;
//			while (ptr && ptr->up == nullptr) ptr = ptr->pre;
//
//			struct Node* newNode1 = new Node(_val);
//
//			//当前层不是最高层，我们直接在上一层ptr位置的后面再插入一次newNode即可
//			if (ptr != nullptr) {
//				ptr = ptr->up;	//将ptr上升到上一层
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
//			//当前层已经是最高层，我们需要先创建新的一层，再将newNode插入到最新层（同时也是最高层）哨兵首节点的下一个位置
//			else {
//				//先创建出新的一层
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
//				//将newNode1插入到最新层
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
//	//将跳表当中数据为_val的节点删除
//	bool erase(int _val) {
//		struct Node* ptr = this->find(_val);
//		if (ptr == nullptr) return false;
//
//		if (ptr->val != _val) return true;	//说明跳表当中压根不含有该数据
//		else {
//			//如果存在该数据节点，ptr指向的仅仅是最底层的节点，我们要从底向上确保将跳表当中所有目标节点删除
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
//	struct Node* head;	//head和tail指针将指向最上层首尾哨兵节点
//	struct Node* tail;
//	int size;			//size的数值记录了当前跳跃表当中存储的数据个数
//	unsigned int seed;
//
//	//返回跳表最低层第一个数值为_val的节点，如果不存在这样一个节点，则返回_val节点理论位置左侧的第一个节点
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
//	void clear() {		//清空跳跃表当中的所有内容，完成对跳表的初始化
//		//我们首先要将跳跃表当中的所有节点清空
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
//		//然后要将跳跃表的层数压缩为一层
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
//	/*在此处添加你的测试程序*/
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