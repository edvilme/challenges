#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}

    friend ostream &operator<<(ostream &os, ListNode n){
        os << n.val;
        if(n.next != nullptr) os << "->" << *n.next;
        return os;
    }
};

ListNode vectorToList(vector<int> v){
    ListNode head;
    ListNode *current = &head;
    for(int i = 0; i < v.size(); i++){
        current->val = v[i];
        if(i == v.size() - 1) continue;
        current->next = new ListNode();
        current = current->next;
    }
    return head;
}

ListNode reverseBetween(ListNode &head, int left, int right){
    if(&head == nullptr) return head;
    // Init index
    int index = 1;
    // Current and newHead
    ListNode *current = &head;
    ListNode *prev = new ListNode(0, current);
    // Iterate from left
    while(index < left){
        prev = current;
        current = current->next;
        index++;
    }
    // Iterate until right and swap
    while(index < right){
        // Temporarily store next
        ListNode *next = current->next;
        current->next = next->next;
        next->next = prev->next;
        prev->next = next;
        index++;
    }

    return left == 1 ? *prev->next : head;
}

int main(){
    ListNode l1 = vectorToList(vector<int>{1, 2, 3, 4, 5, 6, 7, 8});
    cout<<l1<<endl;
    cout<<reverseBetween(l1, 2, 4) << endl << "******************" << endl;

    ListNode l2 = vectorToList(vector<int>{5});
    cout<<l2<<endl;
    cout<<reverseBetween(l2, 1, 1) << endl << "******************" << endl;

    ListNode l3 = vectorToList(vector<int>{3, 5});
    cout<<l3<<endl;
    cout<<reverseBetween(l3, 1, 2) << endl << "******************" << endl;

    return 0;
}


