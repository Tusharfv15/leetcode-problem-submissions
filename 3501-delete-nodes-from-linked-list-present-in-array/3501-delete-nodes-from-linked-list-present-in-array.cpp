/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int,int>mpp;
        for(auto it : nums){
            mpp[it] = 1;
        }
        ListNode* curr = head;
        ListNode *prev = NULL;
        while(curr){
            int value = curr->val;
            ListNode* nextNode = curr->next;
            if(mpp[value]){
                if(prev){
                        prev->next = nextNode;
                        curr->next = NULL;
                        curr = nextNode;
                }
                else {
                     curr->next = NULL;
                     curr = nextNode;
                     head = nextNode;
                }
                
            }
            else {
                prev = curr;
                curr = nextNode;
            }


        }
        return head;

    }
};