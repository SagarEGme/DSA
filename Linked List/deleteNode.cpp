#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// conversion of array to LL;
Node *convertToLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head; // create a mover pointer as we shouldn't tamper the original head as
    for (int i = 1; i < arr.size(); i++)
    { // if we loose the initial pointer we can't access the list data.
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

Node *deleteNode(Node *head)
{
    Node *temp = head;
    if (temp == NULL || temp->next == NULL)
        return NULL;
    while (temp->next->next != NULL)
    {
        temp = temp->next; // we go on increasing temp value till it reaches
        // second last node
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertToLL(arr);
    head = deleteNode(head);
    print(head);
    return 0;
}