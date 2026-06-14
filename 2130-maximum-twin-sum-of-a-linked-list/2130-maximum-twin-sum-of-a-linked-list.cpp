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
    int pairSum(ListNode* head) {
        int count = 0; 
        struct ListNode* temp = head; 
        while(temp) {
            count++; 
            temp = temp->next; 
        }
        
        int i = 0, m = 0;
        temp = head;  
        vector<int> hash; 
        
        while(temp) {
            if(i < count / 2) {
                hash.push_back(temp->val); 
            } 
            else {
                hash[count - i - 1] += temp->val; 
                m = max(m, hash[count - i - 1]); 
            }
            i++; 
            temp = temp->next;
        }
        return m; 
    }
};