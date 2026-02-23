#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

class LRUCache {
  public:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v)
          : key(k)
          , val(v)
          , prev(nullptr)
          , next(nullptr) {
        }
    };

    unordered_map<int, Node*> cache;
    int cap;
    int currentCap;
    Node* head;
    Node* tail;

    LRUCache(int capacity)
      : cap(capacity)
      , currentCap(0) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* curr = cache[key];
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->next = tail;
        curr->prev = tail->prev;
        tail->prev->next = curr;
        tail->prev = curr;
        return curr->val;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* curr = cache[key];
            curr->val = value;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr->next = tail;
            curr->prev = tail->prev;
            tail->prev->next = curr;
            tail->prev = curr;
        } else {
            if (currentCap == cap) {
                Node* lru = head->next;
                cache.erase(lru->key);
                head->next = lru->next;
                lru->next->prev = head;
                delete lru;
                currentCap--;
            }
            Node* curr = new Node(key, value);
            curr->next = head->next;
            curr->prev = head;
            head->next->prev = curr;
            head->next = curr;
            cache[key] = curr;
            currentCap++;
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}
