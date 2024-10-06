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
Node* convertToLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head; // create a mover pointer as we shouldn't tamper the original head as
    for(int i=1;i<arr.size();i++){ // if we loose the initial pointer we can't access the list data.
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

//printing by traversal;
void print(Node *head)
{
    while (head != NULL)
    {

        cout << head->data <<" ";
        head= head->next;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    // Node *y = new Node(arr[0]);
    // y->next = new Node(arr[1]);        Instead of this we can
    // y->next->next = new Node(arr[2]);  simply convert arr to LL.
    Node* head = convertToLL(arr);
    print(head);
    return 0;
}