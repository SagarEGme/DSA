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
 
// Brute Approach 
// TC -> 0(2n) SC -> 0(N) for stack;
Node* reverseDll(Node* head){
    Node* current = head;
    Node* prev = NULL;
    while(current != NULL){
        prev = current->back;
        current->back = current->next;
        current->next = prev;

        current = current->back; // since we need to move
        //ahead in original DLL here current->next means current->back.
        /* 
            the technique to reverse is similar to reversal of 2 numbers.
            temp = b;
            b=a
            a=temp;
        */
    }
    return prev->back; // since finally our last node will be current and prev
    //means one node ahead of last node. here since the list
    //is reversed node ahead of prev is acutally back of prev.

}
// Node* reverseDll(Node* head){
//     stack<int> st;
//     Node* temp = head;
//     while(temp!=NULL){
//         st.push(temp->data);
//         temp = temp->next;
//     }
//     temp = head;
//     while(temp!=NULL){
//         temp->data = st.top();
//         st.pop();
//         temp = temp->next;
//     }
//     return head;

// }

int main()
{
    vector<int> arr = {12, 3, 4, 5, 6};
    Node *head = convert2Dll(arr);
    head = reverseDll(head);
    print(head);
    return 0;
}