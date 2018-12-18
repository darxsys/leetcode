#include <cstdio>
#include <cassert>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        m_cap = capacity;
        first = last = nullptr;
        elements.clear();
    }
    
    int get(int key) {
        unordered_map<int, Node*>::iterator it = elements.find(key);
        if (it == elements.end())
            return -1;

        // put element to the front of the list
        putToFront(it->second);
        return it->second->val;
    }
    
    void put(int key, int value) {
        unordered_map<int, Node*>::iterator it = elements.find(key);
        if (it != elements.end())
        {
            it->second->val = value;
            putToFront(it->second);
            return;
        }

        if (elements.size() == m_cap)
        {
            // remove the last used node
            Node *tail = last;

            if (tail->prev != nullptr)
                tail->prev->next = nullptr;

            last = tail->prev;
            if (last == nullptr)
                first = nullptr;

            elements.erase(elements.find(tail->key));
            delete tail;
        }

        Node *n = new Node();
        n->key = key;
        n->val = value;
        n->next = first;
        n->prev = nullptr;
        if (n->next != nullptr)
            n->next->prev = n;

        if (first == nullptr)
        {
            last = n;
        }

        first = n;
        elements.insert({key, n});
    }

private:
    struct Node {
        int key;
        int val;

        Node *next;
        Node *prev;
    };

    void putToFront(Node *cur)
    {
        if (elements.size() <= 1 || cur == first) return;

        if (cur->next == nullptr)
            last = cur->prev;

        cur->prev->next = cur->next;

        if (cur->next)
            cur->next->prev = cur->prev;

        cur->next = first;
        first->prev = cur;

        first = cur;
        cur->prev = nullptr;        
    }

    Node *first;
    Node *last;
    int m_cap;
    unordered_map<int, Node*> elements;
};


int main() {
    LRUCache *cache = new LRUCache( 2 /* capacity */ );
    assert(cache->get(0) == -1);
    cache->put(1, 1);
    cache->put(2, 2);
    assert(cache->get(1) == 1);
    cache->put(3, 3);
    assert(cache->get(2) == -1);
    cache->put(4, 4);    // evicts key 1
    assert(cache->get(1) == -1);
    assert(cache->get(3) == 3);
    assert(cache->get(4) == 4);       // returns 4

    delete cache;
    return 0;
}