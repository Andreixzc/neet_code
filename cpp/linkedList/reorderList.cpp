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

void reorderList(ListNode* head) {
    if (!head || !head->next) return;

    int count = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    ListNode* mid = head;
    for (int i = 0; i < (count - 1) / 2; i++) {
        mid = mid->next;
    }

    ListNode* second = mid->next;
    mid->next = nullptr;

    ListNode* prev = nullptr;
    ListNode* current = second;
    while (current != nullptr) {
        ListNode* tmpNext = current->next;
        current->next = prev;
        prev = current;
        current = tmpNext;
    }

    ListNode* first = head;
    second = prev;
    while (second != nullptr) {
        ListNode* tmp1 = first->next;
        ListNode* tmp2 = second->next;

        first->next = second;
        second->next = tmp1;

        first = tmp1;
        second = tmp2;
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
