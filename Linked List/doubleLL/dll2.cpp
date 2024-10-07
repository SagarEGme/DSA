#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convert2Dll(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i], nullptr, prev);
        prev->next = newNode;
        prev = newNode;
    }
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

Node *deleteHead(Node *head)
{
    Node *temp = head;
    temp = head->next;
    delete head;
    return temp;
}

Node *deleteTail(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *prev = temp->back;
    delete temp;
    prev->next = nullptr;
    return head;
}

Node *deleteAtKthPlace(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }
    if (temp->back == nullptr)
        return deleteHead(head);
    else if (temp->next == nullptr)
        return deleteTail(head);
    Node *prev = temp->back;
    Node *front = temp->next;
    prev->next = temp->next;
    front->back = temp->back;
    delete (temp);
    return head;
}

Node *deleteEl(Node *head, int el)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == el)
            break;
        temp = temp->next;
    }
    if (temp->next == nullptr)
        return deleteTail(head);
    else if (temp->back == nullptr)
        return deleteHead(head);
    else
    {

        Node *prev = temp->back;
        Node *front = temp->next;
        prev->next = front;
        front->back = prev;
    }
    return head;
}

int main()
{
    vector<int> arr = {12, 3, 4, 5, 6};
    Node *head = convert2Dll(arr);
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteAtKthPlace(head, 5);
    head = deleteEl(head,6);
    print(head);
    return 0;
}