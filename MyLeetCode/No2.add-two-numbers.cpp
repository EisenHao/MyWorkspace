/**
 * No2. 两数相加
 * 给出两个非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 您可以假设除了数字 0 之外，这两个数都不会以 0开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

#include <iostream>
#include <vector>
#include "myTools.h"
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptrL1 = l1, *ptrL2 = l2;
        ListNode *ptrAns = new ListNode(0), *ansHead = ptrAns;// 生成临时头节点
        int jinWei = 0, tmp = 0;

        while (ptrL1 != NULL && ptrL2 != NULL) {
            tmp = ptrL1->val + ptrL2->val + jinWei;
            if (tmp > 9) {
                tmp -= 10;
                jinWei = 1;
            } else {
                jinWei = 0;
            }
            ptrAns->next = new ListNode(tmp);
            ptrAns = ptrAns->next;
            ptrL1 = ptrL1->next;
            ptrL2 = ptrL2->next;
        }

        if (ptrL1 == NULL) {
            ptrL1 = ptrL2;
        }
        while (ptrL1 != NULL) {
            tmp = ptrL1->val + jinWei;
            if (tmp > 9) {
                tmp -= 10;
                jinWei = 1;
            } else {
                jinWei = 0;
            }
            ptrAns->next = new ListNode(tmp);
            ptrAns = ptrAns->next;
            ptrL1 = ptrL1->next;
        }

        // 进位处理
        if (jinWei == 1) {
            ptrAns->next = new ListNode(1);
        }

        // 去掉临时头
        ptrAns = ansHead;
        ansHead = ansHead->next;
        delete ptrAns;
        return ansHead;
    }
};

int main() {
    Solution solution;
    ListNode *ptrL1 = new ListNode(3);
    ptrL1->next = new ListNode(2);
    ListNode *ptrL2 = new ListNode(5);
    ptrL2->next = new ListNode(4);
    ListNode *result = solution.addTwoNumbers(ptrL1, ptrL2);
    MyTools::printList(result);
    return 0;
}
