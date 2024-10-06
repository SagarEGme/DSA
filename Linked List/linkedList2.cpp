//Check if element is present.
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

Node* convertToLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head; 
    for(int i=1;i<arr.size();i++){ 
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

// bool checkElement(Node* head,int elem){
//     Node* temp = head;
//     while(temp!= NULL){
//         if(temp->data == elem){
//             return true;
//         }
//         temp = temp->next;
//     }
//     return false;
// }

int lengthOfLL(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp!= NULL){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertToLL(arr);
    // cout<<checkElement(head,0);
    cout<<lengthOfLL(head);
    return 0;
}