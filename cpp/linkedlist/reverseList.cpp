#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    ListNode* current = head;

    while (current != nullptr) {
        cout << current->val << endl;
        current = current->next;
    }

    return 0;
}
