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
    int getDecimalValue(ListNode* head) {
        ListNode *temp = head;
        string num;
        while(temp){
            num+=to_string(temp->val);
            temp = temp->next;

        }
        int factor = 0;
        long long res = 0;
        int n = num.size();
        for(int i = n-1;i>=0;i--){
            res += (num[i] - '0')*pow(2,factor);
            factor++;
        }
        return res;
    }
};