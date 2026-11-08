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
    return s.top == -1;
}bool IsFull(Stack& s)
{
    return s.top == s.maxsize - 1;
}bool Push(Stack& s, DataType val)
{
    if (IsFull(s))
    {
        return false;
    }
    s.top++;
    s.elements[s.top] = val;
    return true;
}bool Pop(Stack& s, DataType& val)
{
    if (IsEmpty(s))
    {
        return false;
    }
    val = s.elements[s.top];
    s.top--;
    return true;
}void DestroyStack(Stack& s)
{
    delete[] s.elements;
    s.elements = nullptr;
    s.top = -1;
    s.maxsize = 0;
}void DecToBase(int number, int base)
{
    if (base < 2 || base > 9)
    {
        cout << "进制base只能是2~9！" << endl;
        return;
    }
    if (number == 0)
    {
        cout << "转换结果：0" << endl;
        return;
    }
    Stack st;
    InitStack(st, 20);
    while (number != 0)
    {
        int rem = number % base;
        Push(st, rem);
        number = number / base;
    }
    cout << "转换结果：";
    int temp;
    while (!IsEmpty(st))
    {
        Pop(st, temp);
        cout << temp;
    }
    cout << endl;

    DestroyStack(st);
}int main()
{
    int n, b;
    cout << "请输入十进制整数：";
    cin >> n;
    cout << "请输入目标进制(2~9)：";
    cin >> b;
    DecToBase(n, b);
    return 0;
}