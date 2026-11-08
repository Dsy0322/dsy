#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
struct Node
{
    DataType data;
    struct Node* next;
};
typedef struct Node Node;
Node* InitList()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}
void CreateHead(Node* head, DataType arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = head->next;
        head->next = newNode;
    }
}
void CreateTail(Node* head, DataType arr[], int n)
{
    int i;
    Node* rear = head;
    for (i = 0; i < n; i++)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        rear->next = newNode;
        rear = newNode;
    }
}
int IsEmpty(Node* head)
{
    if (head->next == NULL)
        return 1;
    else
        return 0;
}
int GetLength(Node* head)
{
    int count = 0;
    Node* p = head->next;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
void PrintList(Node* head)
{
    Node* p = head->next;
    if (IsEmpty(head))
    {
        printf("链表为空！\n");
        return;
    }
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main()
{
    Node* L1 = InitList();
    int arr1[] = { 1,3,5,7 };
    printf("====头插法建立链表，数组{1,3,5,7}====\n");
    CreateHead(L1, arr1, 4);
    PrintList(L1);
    printf("链表长度：%d\n", GetLength(L1));
    printf("是否为空：%s\n", IsEmpty(L1) ? "是" : "否");
    Node* L2 = InitList();
    int arr2[] = { 2,4,6,8 };
    printf("\n====尾插法建立链表，数组{2,4,6,8}====\n");
    CreateTail(L2, arr2, 4);
    PrintList(L2);
    printf("链表长度：%d\n", GetLength(L2));
    return 0;
}