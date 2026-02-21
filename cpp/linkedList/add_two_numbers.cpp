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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    vector<int> rawSum;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr) {
        int cl1 = 0;
        int cl2 = 0;
        if (l1 != nullptr) {
            cl1 = l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            cl2 = l2->val;
            l2 = l2->next;
        }

        int sum = cl1 + cl2 + carry;
        carry = sum / 10;
        rawSum.push_back(sum % 10);
    }
    if (carry > 0) rawSum.push_back(carry);
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int digit : rawSum) {
        curr->next = new ListNode(digit);
        curr = curr->next;
    }

    return dummy->next;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Create first linked list: 2 -> 4 -> 3
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);

    // Create second linked list: 5 -> 6 -> 4
    ListNode* l2 = new ListNode(4);
    l2->next = new ListNode(5);
    l2->next->next = new ListNode(6);
    addTwoNumbers(l1, l2);

    return 0;
}
