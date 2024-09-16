#include<bits/stdc++.h>
using namespace std;
/* LitNode definition {Defined like LC}
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int v) : val(v) , next(NULL) {}
        ListNode(int v, ListNode*n) : val(v) , next(n) {}
    };
*/

/* DOUBLY LINKED LIST FORMAT*/
struct ListNodeD{
    int val;
    ListNodeD* next;
    ListNodeD* prev;
    ListNodeD(int v) : val(v) , next(NULL) , prev(NULL) {}
    ListNodeD(int v, ListNodeD*n, ListNodeD*p) : val(v) , next(n) , prev(p) {}
};

class MyLinkedList {
    int size;
    ListNodeD *head, *tail;
public:
    MyLinkedList() {
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    int get(int index) { // O(index)
        if(index >= size){return -1;}

        if(index <= size/2){
            ListNodeD *curr = head;
            while(curr && index){
                curr = curr->next;
                index -= 1;
            }
            return curr->val;
        } else {
            ListNodeD *curr = tail;
            index = size - index-1;
            while(curr && index){
                curr = curr->prev;
                index -= 1;
            }
            return curr->val;
        }
    }
    
    void addAtHead(int val) { // O(1)
        ListNodeD *temp = new ListNodeD(val);
        temp->next = head;
        if(head){head->prev = temp;}
        head = temp;
        if(!size){tail = head;}
        size++;
    }
    
    void addAtTail(int val) { // O(1)
        if(!size){
            addAtHead(val); return;
        }
        ListNodeD *temp = new ListNodeD(val);
        if(tail){
            tail->next = temp;
            temp->prev = tail;
        }
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

        if(index <= size/2){
            ListNodeD *curr = head, *prev = NULL;
            while(curr && index){
                prev = curr;
                curr = curr->next;
                index -= 1;
            }

            ListNodeD *temp = new ListNodeD(val);
            temp->next = curr;
            curr->prev = temp;
            prev->next = temp;
            temp->prev = prev;
        } else {
            index = size - index;
            ListNodeD *curr = tail, *prev=NULL;
            while(curr && index){
                prev = curr;
                curr = curr->prev;
                index -= 1;
            }

            ListNodeD *temp = new ListNodeD(val);
            temp->next = prev;
            prev->prev = temp;
            curr->next = temp;
            temp->prev = curr;
        }

        size++;
    }
    
    void deleteAtIndex(int index) { // O(index)
        if (!size || index >= size) {
            return;
        }
        if(index == 0){
            ListNodeD *temp = head;
            head = head->next;
            if(head){head->prev = NULL;}
            temp->next = NULL;
            delete temp;
            size--;
            return;
        }

        if(index == size-1){
            ListNodeD *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            temp->prev = NULL;
            delete temp;
            size--;
            return;
        }

        if(index <= size/2){
            ListNodeD *curr = head, *prev = NULL;
            int idx = index;
            while(curr && idx){
                prev = curr;
                curr = curr->next;
                idx -= 1;
            }

            prev->next = curr->next;
            curr->next->prev = prev;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
        } else {
            ListNodeD *curr = tail, *prev = NULL;
            int idx = size - index-1;
            while(curr && idx){
                prev = curr;
                curr = curr->prev;
                idx -= 1;
            }

            if(prev){prev->prev = curr->prev;}
            curr->prev->next = prev;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;
        }

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