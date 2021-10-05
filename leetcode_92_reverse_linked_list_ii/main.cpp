#include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}

    friend ostream &operator<<(ostream &os, ListNode n){
        if(&n == nullptr) return os;
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

ListNode *reverseBetween(ListNode *head, int left, int right){
    if(left > right) return head;

    // Count positions
    int count = 0;
    // Store current and preLeft
    ListNode *preLeft = new ListNode(0, head);
    ListNode *current = head;
    while(count < left -1){
        if(current == nullptr) return head;
        preLeft = current;
        current = current->next;
        count++; 
    }
    // cout << *current << endl;

    ListNode *prev = nullptr;
    ListNode *next;
    while(count <= right ){
        // Get next
        next = current->next;
        // Point to prev
        current->next = prev;
        // Update prev
        prev = current;
        // Update current
        current = next;
        count++;
        // cout<<*prev<<endl;
    }
    // cout<<"---"<<endl;
    // if(current == nullptr) cout << "?";
    // cout<<current->val<<endl;
    preLeft->next->next = current;
    preLeft->next = prev;
    return head;
}


int main(){
    ListNode l1 = vectorToList(vector<int>{1, 2, 3, 4, 5, 6, 7, 8});
    cout<<l1<<endl;
    cout<<*reverseBetween(&l1, 2, 4) << endl << "******************" << endl;

    ListNode l2 = vectorToList(vector<int>{5});
    cout<<l2<<endl;
    cout<<*reverseBetween(&l2, 1, 1) << endl << "******************" << endl;

    ListNode l3 = vectorToList(vector<int>{3, 5});
    cout<<l3<<endl;
    cout<<*reverseBetween(&l3, 1, 2) << endl << "******************" << endl;

    return 0;
}