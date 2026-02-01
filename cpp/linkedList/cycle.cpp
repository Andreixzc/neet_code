#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

bool hasCycle(ListNode* head) {

    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) return true;
    }

    return false;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
