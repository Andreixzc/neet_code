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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    ListNode* head;
    ListNode* sorted;

    if (list1->val < list2->val) {
        head = list1;
        list1 = list1->next;
    } else {
        head = list2;
        list2 = list2->next;
    }

    sorted = head;

    while (list1 != nullptr && list2 != nullptr) {

        if (list1->val < list2->val) {
            sorted->next = list1;
            list1 = list1->next;
        }

        else {
            sorted->next = list2;
            list2 = list2->next;
        }

        sorted = sorted->next;
    }

    if (list1 != nullptr) {
        sorted->next = list1;
    } else {
        sorted->next = list2;
    }

    return head;
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

    ListNode* head1 = new ListNode(1);
    ListNode* curr1 = head1;
    for (int i = 3; i <= 5; i += 2) {
        curr1->next = new ListNode(i);
        curr1 = curr1->next;
    }

    ListNode* head2 = new ListNode(2);
    ListNode* curr2 = head2;
    for (int i = 4; i <= 6; i += 2) {
        curr2->next = new ListNode(i);
        curr2 = curr2->next;
    }

    printList(head1);
    cout << "------------" << endl;
    printList(head2);
    cout << "------------" << endl;
    ListNode* mergedHead = mergeTwoLists(head1, head2);
    printList(mergedHead);

    return 0;
}
