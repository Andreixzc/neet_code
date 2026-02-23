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

ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    ListNode* curr = nullptr;
    bool l1end = false;
    bool l2end = false;
    while (l1 != nullptr && l2 != nullptr) {
        ListNode* chosen;
        if (l1->val <= l2->val) {
            chosen = l1;
            l1 = l1->next;
        } else {
            chosen = l2;
            l2 = l2->next;
        }
        if (head == nullptr) {
            head = chosen;
            curr = head;
        } else {
            curr->next = chosen;
            curr = curr->next;
        }
        if (l1 == nullptr) {
            l1end = true;
            break;
        } else if (l2 == nullptr) {
            l2end = true;
            break;
        }
    }
    if (l1end == true) {
        curr->next = l2;
    } else if (l2end == true) {
        curr->next = l1;
    }
    return head;
}

ListNode* mergeKLists(vector<ListNode*>& lists, int start, int end) {
    if (start == end) return lists[start];
    int mid = (start + end) / 2;
    ListNode* left = mergeKLists(lists, start, mid);
    ListNode* right = mergeKLists(lists, mid + 1, end);
    return merge(left, right);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    return mergeKLists(lists, 0, lists.size() - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}
