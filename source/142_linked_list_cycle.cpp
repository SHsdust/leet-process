#include "iostream"
#include "algorithm"
using namespace std;


// slow-fast pointer

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        do{
            if(fast == NULL || fast->next==NULL)
                return NULL;
            fast = fast->next->next;
            slow = slow->next;
        }while(fast != slow);

        fast = head;

        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }

};

int main(){
    int arr[10] = {3, 2, 0, -4};
    int pos(1);

    ListNode *head = new ListNode(arr[0]);
    ListNode *tail = head;
    ListNode *start;

    for(int i(1); i<4; ++i){
        ListNode *node = new ListNode(arr[i]);
        if(i==pos)
            start = node;

        tail->next = node;
        tail = node;
    }

    tail->next = start;

    Solution s;
    ListNode *cycle = s.detectCycle(head);

    if(cycle == NULL)
        cout << "no cycle" << endl;
    else
        cout << cycle->val << endl;
    return 0;
}
