#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <stack>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>

using namespace std;
#define fin cin

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


int main()
{

    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    ListNode *head = n1 ;

}

