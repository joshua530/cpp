#include <iostream>
#include <stack>

struct Node {
    int num;
    Node *next;
};
typedef Node *ListNode;

/** uses tail recursion */
void displayLinkedList(ListNode headNode)
{
    // recursive approach
    // if (headNode == NULL)
    //     return;
    // std::cout << headNode->num << "\n";
    // displayLinkedList(headNode->next);

    // iterative approach
    for (ListNode n = headNode; n != NULL; n = n->next)
        std::cout << n->num << "\n";
}

/** uses head recursion */
void displayLinkedListReverseOrder(ListNode headNode)
{
    // iterative approach
    // std::stack<ListNode> theStack;
    // for (ListNode n = headNode; n != NULL; n = n->next)
    //     theStack.push(n);

    // while (!theStack.empty()) {
    //     ListNode n = theStack.top();
    //     theStack.pop();
    //     std::cout << n->num << "\n";
    // }

    // recursive approach
    if (headNode == NULL)
        return;
    displayLinkedListReverseOrder(headNode->next);
    std::cout << headNode->num << "\n";
}

int main(int argc, char const *argv[])
{
    Node *a = new Node;
    a->num = 1;
    Node *b = new Node;
    b->num = 2;
    Node *c = new Node;
    c->num = 3;
    Node *d = new Node;
    d->num = 4;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;
    ListNode l = a;
    a = b = c = d = NULL;

    displayLinkedList(l);
    displayLinkedListReverseOrder(l);
}
