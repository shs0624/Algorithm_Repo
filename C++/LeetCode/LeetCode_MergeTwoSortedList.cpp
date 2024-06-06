// 20.Add Binary
#include <iostream>
#include <stack>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 재귀 방식 깔끔한거 찾다가 발견
// https://lessbutbetter.tistory.com/entry/LeetCodeEasyC%EB%AC%B8%EC%A0%9C%ED%92%80%EC%9D%B4-21-Merge-Two-Sorted-Lists

//Runtime: 11 ms, faster than 59.92 % of C++ online submissions for Merge Two Sorted Lists.
//Memory Usage : 14.8 MB, less than 42.41 % of C++ online submissions for Merge Two Sorted Lists.
//class Solution {
//public:
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        if (list1 == nullptr)
//        {
//            return list2;
//        }
//        else if (list2 == nullptr)
//        {
//            return list1;
//        }
//
//        if (list1->val <= list2->val)
//        {
//            ListNode* nextNode = mergeTwoLists(list1->next, list2);
//            list1->next = nextNode;
//            return list1;
//        }
//        else 
//        {
//            ListNode* nextNode = mergeTwoLists(list1, list2->next);
//            list2->next = nextNode;
//            return list2;
//        }
//    }
//};

// 하나하나 검사하면서 하는 코드
//Runtime: 8 ms, faster than 78.53 % of C++ online submissions for Merge Two Sorted Lists.
//Memory Usage : 15.1 MB, less than 8.02 % of C++ online submissions for Merge Two Sorted Lists.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* target;

        if (list1 == nullptr && list2 == nullptr)
        {
            return head;
        }
        else if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }

        if (list1->val <= list2->val)
        {
            head = new ListNode(list1->val);
            target = head;
            list1 = list1->next;
        }
        else
        {
            head = new ListNode(list2->val);
            target = head;
            list2 = list2->next;
        }

        while (list1 != nullptr || list2 != nullptr)
        {
            if (list1 == nullptr || list2 == nullptr)
            {
                if (list1 == nullptr)
                {
                    target->next = new ListNode(list2->val);
                    list2 = list2->next;
                    target = target->next;
                    continue;
                }
                if (list2 == nullptr)
                {
                    target->next = new ListNode(list1->val);
                    list1 = list1->next;
                    target = target->next;
                    continue;
                }
            }

            if (list1->val <= list2->val)
            {
                target->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                target->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            target = target->next;
        }
        return head;
    }
};

int main()
{
    Solution s;
}