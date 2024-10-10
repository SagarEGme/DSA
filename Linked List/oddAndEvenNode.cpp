
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

// Group even nodes at first then odd nodes. ( sorting value not the index)
// TC -> 0(n) and SC -> 0(1)
// Node *oddAndEven(Node *head)
// {
//     Node *evenStart = nullptr;
//     Node *evenEnd = nullptr;
//     Node *oddStart = nullptr;
//     Node *oddEnd = nullptr;
//     Node *current = head;
//     while (current)
//     {
//         int val = current->data;
//         if (val % 2 == 0)
//         {
//             if (!evenStart)
//             {
//                 evenStart = evenEnd = current; // 10 mins to debug
//             }
//             else
//             {
//                 evenEnd->next = current;
//                 evenEnd = evenEnd->next; // first point the next even node then shift the evenEnd pntr.
//             }
//         }
//         else
//         {
//             if (!oddStart)
//             {
//                 oddStart = oddEnd = current;
//             }
//             else
//             {
//                 oddEnd->next = current;
//                 oddEnd = oddEnd->next; // first point the next even node then shift the evenEnd pntr.
//             }
//         }
//         current = current->next;
//     }
//     evenEnd->next = oddStart;
//     oddEnd->next = nullptr;
//     if (!evenStart || !oddStart)
//         return head; // if there is no nodes.

//     return evenStart;
// }

// Based on index..
// prints even index and then odd index.
// 0(n) and 0(1)
Node *oddAndEven(Node *head)
{
    Node *evenStart = nullptr;
    Node *evenEnd = nullptr;
    Node *oddStart = nullptr;
    Node *oddEnd = nullptr;
    Node *current = head;
    int index = 1 ;
    while (current)
    {
        if (index%2 == 0)
        {
            if (!evenStart)
            {
                evenStart = evenEnd = current; // 10 mins to debug
            }
            else
            {
                evenEnd->next = current;
                evenEnd = evenEnd->next; // first point the next even node then shift the evenEnd pntr.
            }
        }
        else
        {
            if (!oddStart)
            {
                oddStart = oddEnd = current;
            }
            else
            {
                oddEnd->next = current;
                oddEnd = oddEnd->next; // first point the next even node then shift the evenEnd pntr.
            }
        }
        current = current->next;
        index++;
    }
    evenEnd->next = oddStart;
    oddEnd->next = nullptr;
    if (!evenStart || !oddStart)
        return head; // if there is no nodes.

    return evenStart;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5};
    Node *head = convert2Dll(arr1);
    head = oddAndEven(head);
    print(head);
    return 0;
}