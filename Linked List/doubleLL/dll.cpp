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
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
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
Node *insertBeforeHead(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        return newNode;
    }
    newNode->next = head;
    head->back = newNode;
    return newNode; // be careful what to return whether head or newnode. know Why?
}

Node *insertAfterTail(Node *head, int val)
{
    Node *temp = head;
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        return newNode;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // temp will be pointing at the tail of the DLL after loop completion.
    newNode->back = temp;
    temp->next = newNode;

    return head;
}

Node *insertAtKPlace(Node *head, int val, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return insertBeforeHead(head, val);
    }
    if (k == 1)
    {
        return insertBeforeHead(head, val);
    }
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node *newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

Node* insertValBeforeEl(Node* head,int val,int el){

    Node* temp = head;
    if(head == NULL || head->next == NULL || el == head->data) return insertBeforeHead(head,val);
    while(temp!=NULL){
        if(temp->data == el) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

int main()
{
    vector<int> arr = {12, 3, 4, 5, 6};
    Node *head = convert2Dll(arr);
    // head = insertBeforeHead(head, 10);
    // head = insertAfterTail(head, 10);
    // head = insertAtKPlace(head, 10, 2);
    head = insertValBeforeEl(head, 10, 12);
    print(head);
    return 0;
}