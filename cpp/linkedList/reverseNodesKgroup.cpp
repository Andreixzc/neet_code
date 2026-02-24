#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
      : val(0)
      , next(nullptr) {
    }
    ListNode(int x)
      : val(x)
      , next(nullptr) {
    }
    ListNode(int x, ListNode* next)
      : val(x)
      , next(next) {
    }
};

pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* stop) {

    ListNode* prev = nullptr;
    ListNode* tail = head;

    while (head != stop) {
        ListNode* tmpNext = head->next;
        head->next = prev;
        prev = head;
        head = tmpNext;
    }

    return { prev, tail };
}

ListNode* reverseKGroup(ListNode* head, int k) {

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* curr = head;
    ListNode* prevTail = dummy;

    while (curr != nullptr) {

        ListNode* stop = curr;
        int c = 0;
        while (c < k && stop != nullptr) {
            stop = stop->next;
            c++;
        }
        if (c < k) break;

        auto [newHead, tail] = reverse(curr, stop);
        prevTail->next = newHead;
        tail->next = stop;
        prevTail = tail;
        curr = stop;
    }

    return dummy->next;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
