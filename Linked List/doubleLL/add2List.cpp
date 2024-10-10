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

// TC -> 0(max(l1,l2))
// sc-> 0(max(m,n))

Node* add2LL(Node* l1, Node* l2){
    Node* dummyNode = new Node(0);
    Node* temp = dummyNode;
    int carry = 0 ;
    while(l1 || l2 || carry){
        int sum = 0;
        if(l1!=NULL){
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->data;
            l2=l2->next;
        }
        sum+=carry;
        carry = sum/10;
        Node* newNode = new Node(sum%10);

        temp->next = newNode;
        temp = temp->next;
    }
    return dummyNode->next;
}
 


int main()
{
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {12, 3, 4, 5, 6};
    Node *head1 = convert2Dll(arr1);
    Node *head2 = convert2Dll(arr2);
    Node* head = add2LL(head1,head2);
    print(head);
    return 0;
}