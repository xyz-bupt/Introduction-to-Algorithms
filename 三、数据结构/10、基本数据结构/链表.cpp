#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;
} Node;

void insert(Node **head, int data)   //二级指针：链表头指针的地址，为了修改链表头指针
{
    Node *newNode = new Node{data, nullptr};
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(Node **head, int data)
{
    if (head == nullptr || *head == nullptr)
    {
        return;
    }

    Node *cur = *head;
    Node *prev = nullptr;

    while (cur != nullptr && cur->data != data)
    {
        prev = cur;
        cur = cur->next;
    }

    if (cur == nullptr)
    {
        return;
    }

    if (prev == nullptr)
    {
        *head = cur->next;
    }
    else
    {
        prev->next = cur->next;
    }

    delete cur;
}

Node *search(Node *head, int data)
{
    Node *cur = head;
    while (cur != nullptr)
    {
        if (cur->data == data)
        {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}

void printList(Node *head)
{
    Node *cur = head;
    while (cur != nullptr)
    {
        cout << cur->data;
        if (cur->next != nullptr)
        {
            cout << " -> ";
        }
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;

    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    cout << "Initial list: ";
    printList(head);

    int valueToFind = 2;
    Node *result = search(head, valueToFind);
    if (result != nullptr)
    {
        cout << "Found value " << valueToFind << " at node with address: " << result << endl;
    }
    else
    {
        cout << "Value " << valueToFind << " not found in the list." << endl;
    }

    int valueToDelete = 2;
    deleteNode(&head, valueToDelete);
    cout << "List after deleting " << valueToDelete << ": ";
    printList(head);

    while (head != nullptr)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}
