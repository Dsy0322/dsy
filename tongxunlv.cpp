//项目名称： 简单的通讯录管理程序
//项目功能： 实现通讯录的增删改查功能

#include <iostream>
using namespace std;

//定义联系人结构体
struct Contact
{
        char name[50]; //联系人姓名
        char phone[12]; //联系人电话
        struct Birthday //联系人生日
        {
                int year; //年
                int month; //月
                int day; //日
        } birthday;
        int age; //联系人年龄
};

//定义通讯录结点结构体
struct Node
{
        Contact data; //联系人信息
        Node* next; //指向下一个结点的指针
};

/*函数功能： 初始化一个空的通讯录链表
* 函数形参： 无
* 函数返回值： 返回一个空的通讯录链表头指针，Node*类型
*/
Node* InitAddressBook()
{
        Node* head = new Node; //创建一个新的结点
        if(head == NULL) //判断是否创建成功
                cout << "内存分配失败！" << endl;
        else
                head->next = NULL; //将头结点的 next 指针置为空
        return head; //返回头结点指针
}

/*函数功能： 采用头插法创建一个通讯录链表
* 函数形参： 通讯录链表头指针 Node* head，联系人信息 Contact data
* 函数返回值： 创建成功返回 true,否则返回 false，bool 类型
*/
bool CreateAddressBookHead(Node* head, Contact data)
{
        Node* node = new Node; //创建一个新的结点
        if (node == NULL) //判断是否创建成功
        {
                cout << "内存分配失败！" << endl;
                return false; //创建失败返回 false
        }
        node->data = data; //将联系人信息赋值给新结点
        node->next = head->next; //将新结点的 next 指针指向头结点的下一个结点
        head->next = node; //将头结点的 next 指针指向新结点
        return true; //创建成功返回 true
}

/*函数功能： 采用尾插法创建一个通讯录链表
* 函数形参： 通讯录链表头指针 Node* head，联系人信息 Contact data
* 函数返回值： 创建成功返回 true,否则返回 false，bool 类型
*/
bool CreateAddressBookTail(Node* head, Contact data)
{
        static Node* tail = head; //定义一个尾指针，初始指向头结点
        Node* node = new Node; //创建一个新的结点
        if (node == NULL) //判断是否创建成功
        {
                cout << "内存分配失败！" << endl;
                return false; //创建失败返回 false
        }
        node->data = data; //将联系人信息赋值给新结点
        node->next = NULL; //将新结点的 next 指针置为空
        tail->next = node; //将尾结点的 next 指针指向新结点
        tail = node; //将尾指针指向新结点
        return true; //创建成功返回 true
}

/*函数功能： 输入单个联系人信息
* 函数形参： 无
* 函数返回值： 返回联系人信息，Contact 类型
*/
Contact InputContact()
{
        Contact data;
        //cout << "请输入联系人姓名： " << endl;
        cin >> data.name;
        //cout << "请输入联系人电话： " << endl;
        cin >> data.phone;
        //out << "请输入联系人生日（年 月 日）： " << endl;
        cin >> data.birthday.year >> data.birthday.month >> data.birthday.day;
        data.age = 2026 - data.birthday.year; //计算年龄
        return data;
}

/*函数功能： 输出单个联系人信息
* 函数形参： 联系人信息 Contact data
* 函数返回值： 无，void 类型
*/
void OutputContact(Contact data)
{
        cout << "姓名： " << data.name << endl;
        cout << "电话： " << data.phone << endl;
        cout << "生日： " << data.birthday.year << "年" << data.birthday.month << "月" <<
data.birthday.day << "日" << endl;
        cout << "年龄： " << data.age << endl;
}

/*函数功能： 输出通讯录中所有联系人信息
* 函数形参： 通讯录链表头指针 Node* head
* 函数返回值： 无，void 类型
*/
void OutputAddressBook(Node* head)
{
        Node* node = head->next;
        while (node)
        {
                OutputContact(node->data);
                node = node->next;
                }
}

/*函数功能： 按姓名查找通讯录中指定联系人信息
* 函数形参： 通讯录链表头指针 Node* head，联系人姓名 char name[]
* 函数返回值： 查找成功，返回地址，否则返回空，Node*类型
*/
Node* SearchContactByName(Node* head, char* name)
{
        Node* node = head->next;
        while (node)
        {
                if(strcmp(node->data.name, name) == 0)
                        return node; //查找成功，返回结点地址
                node = node->next;
        }
        return NULL; //查找失败，返回空
}

/*函数功能： 按电话查找通讯录中指定联系人信息
* 函数形参： 通讯录链表头指针 Node* head，联系人电话 char phone[]
* 函数返回值： 查找成功，返回地址，否则返回空，Node*类型
*/
Node* SearchContactByPhone(Node* head, char* phone)
{
        Node* node = head->next;
        while (node)
        {
                if (strcmp(node->data.phone, phone) == 0)
                        return node; //查找成功，返回结点地址
                node = node->next;
        }
        return NULL; //查找失败，返回空
}

/*函数功能： 在指定联系人的后面插入一个新的联系人
* 函数形参： 通讯录链表头指针 Node* head，指定联系人地址 Node* target，联系人信息 Contact data
* 函数返回值： 插入成功，返回 true，否则返回 false，bool 类型
*/
bool InsertContactAfter(Node* head, Node* target, Contact data)
{
        Node* node = new Node; //创建一个新的结点
        if (node)
        {
                node->data = data;  //数据域赋值
                node->next = target->next;  //指针域赋值
                target->next = node; //将指定结点的 next 指针指向新结点
                return true; //插入成功，返回 true
        }
        return false;
}

/*函数功能： 查找指定联系人的前驱结点
* 函数形参： 通讯录链表头指针 Node* head，指定联系人地址 Node* target
* 函数返回值： 查找成功，返回前驱，否则返回空，Node*类型
*/
Node* SearchPreNode(Node* head, Node* target)
{
        for(Node* pre = head;pre->next != NULL; pre = pre->next)
                if(pre->next == target)
                        return pre; //查找成功，返回前驱结点地址
        return NULL; //查找失败，返回空
}

/*函数功能： 在指定联系人的前面插入一个新的联系人
* 函数形参： 通讯录链表头指针 Node* head，指定联系人地址 Node* target，联系人信息 Contact data
* 函数返回值： 插入成功，返回 true，否则返回 false，bool 类型
*/
bool InsertContactBefore(Node* head, Node* target, Contact data)
{
        Node* pre = SearchPreNode(head, target); //查找指定联系人的前驱结点
        if (pre)  //查找成功
        {
                Node* node = new Node; //创建一个新的结点
                if (node)
                {
                        node->data = data;  //数据域赋值
                        node->next = target;  //指针域赋值
                        pre->next = node; //将前驱结点的 next 指针指向新结点
                        return true; //插入成功，返回 true
                }
        }
        return false; //插入失败，返回 false
}

/*函数功能： 删除指定联系人
* 函数形参： 通讯录链表头指针 Node* head，指定联系人 Node* target
* 函数返回值： 删除成功，返回 true，否则返回 false，bool 类型
*/
bool DeleteContact(Node* head, Node* target)
{
        Node* pre = SearchPreNode(head, target); //查找指定联系人的前驱结点
        if (pre)  //查找成功
        {
                pre->next = target->next; //将前驱结点的 next 指针指向指定结点的下一个结点
                delete target; //释放指定结点的内存空间
                return true; //删除成功，返回 true
        }
        return false; //删除失败，返回 false
}

/*函数功能： 删除指定联系人的后继
* 函数形参： 通讯录链表头指针 Node* head，指定联系人 Node* target
* 函数返回值： 删除成功，返回 true，否则返回 false，bool 类型
*/
bool DeleteContactNext(Node* head, Node* target)
{
        if (target->next)  //判断指定结点是否有后继结点
        {
                Node* node = target->next; //保存指定结点的后继结点
                target->next = node->next; //将指定结点的 next 指针指向后继结点的下一个结点
                delete node; //释放后继结点的内存空间
                return true; //删除成功，返回 true
        }
        return false; //删除失败，返回 false
}

/*函数功能： 打印用户选择菜单
* 函数形参： 无
* 函数返回值： 返回用户的选择，int 类型
*/
int PrintMenu()
{
        int choice;
        cout << "========================================================通讯录管理程序========================================================" << endl;
        cout << "1. 添加联系人" << endl;
        cout << "2. 删除联系人" << endl;
        cout << "3. 查找联系人" << endl;
        cout << "4. 修改联系人" << endl;
        cout << "5. 显示所有联系人" << endl;
        cout << "6. 退出程序" << endl;
        cout << "==========================================================================================================================" << endl;
        cout << "请输入您的选择（1-6）： " << endl;
        cin >> choice;
        return choice;
}

int main()
{

        return 0;

}
