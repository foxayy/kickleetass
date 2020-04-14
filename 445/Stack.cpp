#include "stdc++.h"

using namespace std;

// 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
// 你可以假设除了数字 0 之外，这两个数字都不会以零开头。

// 进阶：
//     如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/add-two-numbers-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//解法1：栈处理逆序数据
//解法2：对齐链表相加+进位处理
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> s1, s2;

		ListNode* pLN = l1;
		while (pLN != nullptr) {
			s1.push(pLN->val);
			pLN = pLN->next;
		}
		pLN = l2;
		while (pLN != nullptr) {
			s2.push(pLN->val);
			pLN = pLN->next;
		};

		vector<int> data;
		int tmp = 0;
		int b = 0;
		while (!(s1.empty() || s2.empty())) {
			tmp = s1.top() + s2.top() + b;
			data.insert(data.begin(), tmp%10);
			b = tmp > 9 ? 1 : 0;
			s1.pop();
			s2.pop();
		}
		while (!s1.empty()) {
			tmp = s1.top() + b;
			data.insert(data.begin(), tmp % 10);
			b = tmp > 9 ? 1 : 0;
			s1.pop();
		}
		while (!s2.empty()) {
			tmp = s2.top() + b;
			data.insert(data.begin(), tmp % 10);
			b = tmp > 9 ? 1 : 0;
			s2.pop();
		}
		if (b) {
			data.insert(data.begin(), b);
		}

		ListNode* res = new ListNode(0);
		pLN = res;
		for (int i = 0; i < data.size(); i++) {
			pLN->val = data[i];
			if (i + 1 == data.size()) {
				pLN->next = nullptr;
				pLN = nullptr;
			}
			else {
				pLN->next = new ListNode(0);
				pLN = pLN->next;
			}
		}
		return res;
	}
	void printList(ListNode* lptr) {
		while (lptr!=nullptr)
		{
			cout << lptr->val << " ";
			lptr = lptr->next;
		}
		cout << endl;
	}
	ListNode* createList(const vector<int>& data) {
		ListNode* res = new ListNode(0);
		ListNode* pLN = res;
		for (int i = 0; i < data.size(); i++) {
			pLN->val = data[i];
			if (i + 1 == data.size()) {
				pLN->next = nullptr;
				pLN = nullptr;
			}
			else {
				pLN->next = new ListNode(0);
				pLN = pLN->next;
			}
		}
		return res;
	}
};

int main() {
	vector<int> d1 = { 7,2,4,3 };
	vector<int> d2 = { 5,6,4 };

	Solution s;

	ListNode* l1 = s.createList(d1);
	ListNode* l2 = s.createList(d2);
	s.printList(l1);
	s.printList(l2);

	s.printList(s.addTwoNumbers(l1,l2));

	return 0;
}