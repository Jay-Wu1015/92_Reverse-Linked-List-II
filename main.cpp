#include<iostream>
#include<vector>
#include <cmath>
#include <unordered_set>
#include<string>
#include<unordered_map>
#include <set>
#include<map>

using namespace std;

class ListNode {
    public: 
        int val;
        ListNode *next;
        ListNode(int val) : val(val), next(nullptr) {}
};

class Solution {
        
    public:
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            if (!head || left == right) return head;
        
            // 建立 dummy node 簡化邏輯
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode* prev = dummy;
        
            // 1. 找到 left 前一個節點
            cout<<"1. find a node"<<endl;
            for (int i = 1; i < left; ++i) {
                prev = prev->next;
            }
        
            // 2. 開始反轉
            ListNode* curr = prev->next;  // 指向第 left 個節點
            ListNode* nextNode = nullptr;
            
            cout<<" 2. start to reverse" <<endl;
            
            for (int i = 0; i < right - left; ++i) {
                nextNode = curr->next;
                curr->next = nextNode->next;
                nextNode->next = prev->next;
                prev->next = nextNode;
            }
        
            return dummy->next;
        }
        
        
       
    };


    void printList(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
    
    int main(){

        Solution sol;
        vector<int> vec {1,2,3,4,5};
        
        cout<<"=============ans=========="<<endl;

       ListNode* head = new ListNode(vec[0]);
       ListNode* temp=head;
       for(int i=1; i<5;i++){
        temp->next = new ListNode(vec[i]);
        temp = temp->next;

       }
       head=sol.reverseBetween(head, 2,4 );
       
       printList(head);

        return 0;
    }