#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
      : val(x)
      , next(nullptr) {
    }
};
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int size = 0;
    ListNode* it = head;
    while (it != nullptr) {
        size++;
        it = it->next;
    }

    if (n == size) return head->next;

    int idx = size - n;
    it = head;
    for (int i = 1; i < idx; i++) it = it->next;

    it->next = it->next->next;

    return head;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
