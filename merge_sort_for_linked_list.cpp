// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *merge(Node *h1, Node *h2)
    {
        if (h1 == NULL)
        {
            return h2;
        }

        if (h2 == NULL)
        {
            return h1;
        }

        Node *p1 = h1;
        Node *p2 = h2;
        Node *dummy = new Node(0);
        Node *p3 = dummy;
        while (p1 and p2)
        {
            if (p1->data < p2->data)
            {
                p3->next = p1;
                p1 = p1->next;
                p3 = p3->next;
            }
            else
            {
                p3->next = p2;
                p2 = p2->next;
                p3 = p3->next;
            }
        }

        while (p1)
        {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }

        while (p2)
        {
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }

        return dummy->next;
    }

    Node *FindMid(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node *mergeSort(Node *head)
    {

        if (head == NULL or head->next == NULL)
        {
            return head;
        }

        // break linked list into 2 halves to call recursion on both halves

        Node *mid = FindMid(head);

        // left part of broken list  i.e. new linked list
        Node *left = head;
        // right part of broken list i.e. new linked list
        Node *right = mid->next;

        mid->next = NULL; // mid ke next ko null kar diya toh link break ho gayi

        // now recursive calls on both halves and recursion will sort those halves
        left = mergeSort(left);
        right = mergeSort(right);

        // now both halve sorted , just merge both sorted LL
        Node *result = merge(left, right);
        return result;
    }
};

// CODE BY :- AJAY PAL IIT (BHU) VARANASI
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *merge(Node *h1, Node *h2)
    {
        if (h1 == NULL)
        {
            return h2;
        }

        if (h2 == NULL)
        {
            return h1;
        }

        Node *p1 = h1;
        Node *p2 = h2;
        Node *dummy = new Node(0);
        Node *p3 = dummy;
        while (p1 and p2)
        {
            if (p1->data < p2->data)
            {
                p3->next = p1;
                p1 = p1->next;
                p3 = p3->next;
            }
            else
            {
                p3->next = p2;
                p2 = p2->next;
                p3 = p3->next;
            }
        }

        while (p1)
        {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }

        while (p2)
        {
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }

        return dummy->next;
    }

    Node *findmid(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node *mergeSort(Node *head)
    {
        if (head == NULL or head->next == NULL)
        {
            return head;
        }

        Node *mid = findmid(head);

        Node *left = head;
        Node *right = mid->next;

        mid->next = NULL;

        left = mergeSort(left);
        right = mergeSort(right);

        Node *result = merge(left, right);
        return result;
    }
};
