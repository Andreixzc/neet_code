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

ListNode* reverseList(ListNode* head) {
    ListNode* reverseList(ListNode * head) {

        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* tmpNext = current->next;
            current->next = prev;
            prev = current;
            current = tmpNext;
        }

        return prev;
    }
}

void printList(ListNode* head) {
    ListNode* current = head;

    while (current != nullptr) {
        cout << current->val << endl;
        current = current->next;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Method 1: Manual creation
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);

    cout << "List 1:" << endl;
    printList(head1);

    return 0;
}
