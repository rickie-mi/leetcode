#include <iostream>
#include <unordered_map>
using namespace std;


struct doubleNode{
	int key, val;
	doubleNode *pre, *next;
	doubleNode(int k = 0, int v = 0) : key(k), val(v), pre(NULL), next(NULL) {}
};

class LRUCache {
private:
	unordered_map<int, doubleNode*> mp;
	doubleNode *head, *tail;
	int cap;
	int size;
public:
	LRUCache(int capacity) {
		head = new doubleNode();
		tail = new doubleNode();
		head->next = tail;
		tail->pre = head;
		cap = capacity;
		size = 0;
	}

	int get(int key) {
		if (mp.count(key))
		{
			doubleNode *cur = mp[key];
			removeNode(cur);
			addNode(cur);
			//cout<<size<<endl;
			return mp[key]->val;
		}
		//cout<<size<<endl;
		return -1;
	}

	void put(int key, int value) {
		if (mp.count(key))
		{
			doubleNode *cur = mp[key];
			cur->val = value;
			removeNode(cur);
			addNode(cur);
		}
		else
		{
			if (size == cap)
			{
				//cout<<head->next->key;
				removeFirst();
				size--;
			}
			doubleNode *cur = new doubleNode(key, value);
			mp[key] = cur;
			addNode(cur);
			size++;
		}
		//cout<<head->next->key;
		//cout<<size<<endl;
	}

	void removeNode(doubleNode *cur)
	{
		cur->pre->next = cur->next;
		cur->next->pre = cur->pre;
	}
	void removeFirst()
	{
		if (size == 0) return;
		mp.erase(head->next->key);
		removeNode(head->next);
	}
	void addNode(doubleNode *cur)
	{
		cur->next = tail;
		cur->pre = tail->pre;
		tail->pre->next = cur;
		tail->pre = cur;
	}
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/