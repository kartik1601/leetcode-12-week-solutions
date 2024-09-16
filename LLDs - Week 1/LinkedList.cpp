#include<bits/stdc++.h>
using namespace std;
/* ListNode definition {Defined like LC} */
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v) : val(v) , next(NULL) {}
    ListNode(int v, ListNode*n) : val(v) , next(n) {}
};

class MyLinkedList {
    int size;
    ListNode *head, *tail;
public:
    MyLinkedList() {
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    int get(int index) { // O(index)
        if(index >= size){return -1;}
        ListNode *curr = head;
        while(curr && index){
            curr = curr->next;
            index -= 1;
        }
        return curr->val;
    }
    
    void addAtHead(int val) { // O(1)
        ListNode *temp = new ListNode(val);
        temp->next = head;
        head = temp;
        if(!size){tail = head;}
        size++;
    }
    
    void addAtTail(int val) { // O(1)
        if(!size){
            addAtHead(val); return;
        }
        ListNode *temp = new ListNode(val);
        if(tail){tail->next = temp;}
        tail = temp;
        size++;
    }
    
    void addAtIndex(int index, int val) { // O(index)
        if(index == 0){
            addAtHead(val); return;
        } else if (index == size) {
            addAtTail(val); return;
        } else if (index > size){
            return;
        }

        ListNode *curr = head, *prev = NULL;

        while(curr && index){
            prev = curr;
            curr = curr->next;
            index -= 1;
        }

        ListNode *temp = new ListNode(val);
        temp->next = curr;
        prev->next = temp;
        size++;
    }
    
    void deleteAtIndex(int index) { // O(index)
        if (!size || index >= size) {
            return;
        }
        if(index == 0){
            ListNode *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
            size--;
            return;
        }

        ListNode *curr = head, *prev = NULL;
        int idx = index;
        while(curr && idx){
            prev = curr;
            curr = curr->next;
            idx -= 1;
        }

        prev->next = curr->next;
        if(index==size-1){tail = prev;}
        curr->next = NULL;
        delete curr;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */