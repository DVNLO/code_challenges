#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node
{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache
{   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function
};

class LRUCache : protected Cache
{
    Node * update(int const key);
public:
    LRUCache(int const capacity);
    void set(int key, int val) override;
    int get(int key) override;
};

LRUCache::LRUCache(int const capacity)
{
    cp = capacity;
    head = nullptr;
    tail = nullptr;
}

Node * LRUCache::update(int const key)
{
    auto itr{ mp.find(key) };
    if(itr == mp.end())
    {
        if(mp.size() >= cp)
        {
            mp.erase(tail->key);
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
            head->prev = new Node(key, 0);
            head = head->prev;
            mp[key] = head;
        }
        else
        {
            head->prev = new Node(key, 0);
            head = head->prev;
            mp[key] = head;
        }
    }
    else 
    {
        // we found it
        // it could be tail, head, or in the middle
        // either way we need to move it to the front
    }
    return head;
}

void LRUCache::set(int key, int val)
{
    update(key)->value = val;
}

int LRUCache::get(int key)
{
    return update(key)->value;
}

int main() {