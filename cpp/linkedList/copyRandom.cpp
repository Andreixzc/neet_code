#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

class Node {
  public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {

    if (head == nullptr) return nullptr;

    Node* it = head;
    unordered_map<Node*, Node*> map;

    while (it != nullptr) {
        Node* copy = new Node(it->val);
        map[it] = copy;
        it = it->next;
    }

    it = head;

    while (it != nullptr) {
        map[it]->next = map[it->next];
        map[it]->random = map[it->random];
        it = it->next;
    }

    return map[head];
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
