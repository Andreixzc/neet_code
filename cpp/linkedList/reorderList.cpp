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
    ListNode* tmpHead = head;
    while (tmpHead != nullptr) {
        count++;
        tmpHead = tmpHead->next;
    }

    int mid = (count - 1) / 2;

    ListNode* midNode = head;
    for (int i = 0; i < mid; i++) midNode = midNode->next;

    ListNode* secondHalf = midNode->next;
    midNode->next = nullptr;

    ListNode* prev = nullptr;
    ListNode* curr = secondHalf;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    ListNode* first = head;
    ListNode* second = prev;
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

    int n = 4;
    vector<int> arr = { 1, 2, 3, 4, 5 };
    cout << arr[n / 2];

    return 0;
}
