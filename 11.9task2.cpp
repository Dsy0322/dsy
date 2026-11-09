#include <iostream>
#include <string>
using namespace std;
typedef char DataType;
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
        return false;
    LinkStack* p = top;
    val = p->data;
    top = top->next;
    delete p;
    return true;
}
bool GetTop(LinkStack* top, DataType& val)
{
    if (IsEmpty(top))
        return false;
    val = top->data;
    return true;
}
bool IsValid(string s)
{
    LinkStack* st = InitStack();
    bool flag = true;
    int i = 0;
    char ch;
    while (i < s.size() && flag == true)
    {
        ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            Push(st, ch);
        }
        else if (ch == ')')
        {
            char topCh;
            if (!IsEmpty(st) && GetTop(st, topCh) && topCh == '(')
            {
                Pop(st, topCh);
            }
            else
            {
                flag = false;
            }
        }
        else if (ch == ']')
        {
            char topCh;
            if (!IsEmpty(st) && GetTop(st, topCh) && topCh == '[')
            {
                Pop(st, topCh);
            }
            else
            {
                flag = false;
            }
        }
        else if (ch == '}')
        {
            char topCh;
            if (!IsEmpty(st) && GetTop(st, topCh) && topCh == '{')
            {
                Pop(st, topCh);
            }
            else
            {
                flag = false;
            }
        }
        i++;
    }
    if (IsEmpty(st) && flag == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string str;
    cout << "请输入括号字符串：";
    cin >> str;
    if (IsValid(str))
    {
        cout << "匹配" << endl;
    }
    else
    {
        cout << "不匹配" << endl;
    }
    return 0;
}