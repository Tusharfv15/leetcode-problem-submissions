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
        unordered_set<int> numSet;
        for(auto it : nums){
            numSet.insert(it);
        }
        ListNode* curr = head;
        ListNode *prev = NULL;
        while(curr){
            int value = curr->val;
            ListNode* nextNode = curr->next;
            if(numSet.count(value)){
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