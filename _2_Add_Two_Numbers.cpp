/**
 *PROBLEM: 
 *You are given two linked lists representing two non-negative 
 *numbers. The digits are stored in reverse order and each of 
 *their nodes contain a single digit. Add the two numbers and 
 *return it as a linked list.
 *
 *Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *Output: 7 -> 0 -> 8
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a=0, b=0, c=0;
		ListNode *la, *lb, *sum, *carry;
		for (auto p = l1; p != NULL; p = p->next)
			++a;
		for (auto p = l2; p != NULL; p = p->next)
			++b;
		if (a >= b) {
			sum = la = l1;
			lb = l2;
		}
		else {
			sum = la = l2;
			lb = l1;
		}
		while (lb!=NULL) {
			la->val = la->val + lb->val + c;
			c = la->val / 10;
			la->val %= 10;
			carry = la;
			la = la->next;
			lb = lb->next;
		}
		while (la != NULL) {
			la->val += c;
			c = la->val / 10;
			la->val %= 10;
			carry = la;
			la = la->next;
		}
		if(c != 0) {
		    ListNode *p = new ListNode(c);
		    carry->next = p;
		}
		return sum;
    }
};