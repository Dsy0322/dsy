#include <iostream>
using namespace std;
typedef int DataType;
struct LinkStack
{
    DataType data;    
    LinkStack* next;
};
LinkStack* InitStack()
{
    return nullptr;
}
bool IsEmpty(LinkStack* top)
{
    return top == nullptr;
}
void Push(LinkStack*& top, DataType val)
{
    LinkStack* newNode = new LinkStack;
    newNode->data = val;
    newNode->next = top; 
    top = newNode;      
}
bool Pop(LinkStack*& top, DataType& val)
{
    if (IsEmpty(top))
    {
        return false;
    }
    LinkStack* p = top;  
    val = p->data;      
    top = top->next;    
    delete p;          
    return true;
}
bool GetTop(LinkStack* top, DataType& val)
{
    if (IsEmpty(top))
    {
        return false;
    }
    val = top->data;
    return true;
}
int main()
{
    LinkStack* top = InitStack(); 
    Push(top, 10);
    Push(top, 20);
    Push(top, 30);
    int x;
    if (GetTop(top, x))
    {
        cout << "栈顶元素：" << x << endl; 
    }
    Pop(top, x);
    cout << "出栈元素：" << x << endl;   
    if (GetTop(top, x))
    {
        cout << "新栈顶：" << x << endl;  
    }
    if (IsEmpty(top))
    {
        cout << "栈为空" << endl;
    }
    else
    {
        cout << "栈不为空" << endl;
    }
    return 0;
}