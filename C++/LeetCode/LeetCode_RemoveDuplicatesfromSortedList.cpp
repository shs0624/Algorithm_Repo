#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//4ms, 3.8MB 남의 코드
//class Solution {
//public:
//    ListNode* deleteDuplicates(ListNode* head) {
//        if (!head)
//            return NULL;
//        auto p = head;
//        while (p->next != NULL) {
//            auto q = p;
//            // do while을 통해 이전 노드와 다음 노드값이 같은경우 다른 값이 나올때까지 이동
//            do {
//                q = q->next;
//            } while (q->next && q->val == p->val);
//            // 아마 둘 다 NULL일 경우 while을 끝내느 목적인듯
//            if (q->val == p->val) {
//                p->next = NULL;
//            }
//            else {
//                p->next = q;
//                p = q;
//            }
//        }
//        return head;
//    }
//};


// 14ms(54.02%), 11.5MB(79.42%) 내 코드
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* lastNode = NULL;
        ListNode* Node = head;

        if (Node == NULL) return head;

        while (Node->next != NULL)
        {
            if (lastNode == NULL)
            {
                lastNode = Node;
                continue;
            }
            Node = lastNode->next;
            if (Node == NULL) break;

            if (Node->val == lastNode->val)
            {
                lastNode->next = Node->next;
            }
            else
            {
                lastNode = Node;
            }
        }

        return head;
    }
};

int main()
{
    Solution s;
}

