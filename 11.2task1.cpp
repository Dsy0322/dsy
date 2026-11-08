#include <iostream>
using namespace std;
typedef int DataType;
struct Stack
{
    int top;
    int maxsize;
    DataType* elements;
};void InitStack(Stack& s, int size)
{
    s.maxsize = size;
    s.elements = new DataType[size];
    s.top = -1;
}bool IsEmpty(Stack& s)
{
    if (s.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}bool IsFull(Stack& s)
{
    if (s.top == s.maxsize - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}bool Push(Stack& s, DataType val)
{
    if (IsFull(s) == true)
    {
        cout << "栈已满，入栈失败！" << endl;
        return false;
    }
    s.top = s.top + 1;
    s.elements[s.top] = val;
    return true;
}bool Pop(Stack& s, DataType& val)
{
    if (IsEmpty(s) == true)
    {
        cout << "栈是空的，出栈失败！" << endl;
        return false;
    }
    val = s.elements[s.top];
    s.top = s.top - 1;
    return true;
}bool GetTop(Stack& s, DataType& val)
{
    if (IsEmpty(s) == true)
    {
        cout << "栈是空的，取不到栈顶！" << endl;
        return false;
    }
    val = s.elements[s.top];
    return true;
}void DestroyStack(Stack& s)
{
    delete[] s.elements;
    s.elements = nullptr;
    s.top = -1;
    s.maxsize = 0;
}int main()
{
    Stack st;
    int num;
    InitStack(st, 4);
    Push(st, 10);
    Push(st, 20);
    Push(st, 30);
    GetTop(st, num);
    cout << "现在栈顶元素是：" << num << endl;
    Pop(st, num);
    cout << "刚刚弹出的元素：" << num << endl;
    GetTop(st, num);
    cout << "弹出之后，新的栈顶：" << num << endl;
    if (IsEmpty(st) == true)
    {
        cout << "栈现在是空" << endl;
    }
    else
    {
        cout << "栈现在不是空" << endl;
    }
    DestroyStack(st);
    return 0;
}