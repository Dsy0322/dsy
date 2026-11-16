#include <iostream>
#include <cstring>   // 要用strcmp比较字符串，必须加这个头文件
using namespace std;

//定义联系人生日结构体
struct Birthday //联系人生日
{
	int year; //年
	int month; //月
	int day; //日
};

//定义联系人结构体
struct Contact
{
	char name[50]; //联系人姓名
	char phone[12]; //联系人电话
	Birthday birthday; //联系人生日
	int age; //联系人年龄
};

//定义通讯录结点结构体
struct Node
{
	Contact data; //联系人信息
	Node* next; //指向下一个结点的指针
};

//在此区域完成通讯录功能的函数实现

// 函数1：初始化链表，创建头结点，返回头结点地址
Node* InitAddressBook()
{
	// 新建一个头结点
	Node* head = new Node;
	// 判断内存有没有分配失败
	if (head == NULL)
	{
		cout << "内存分配失败！" << endl;
	}
	// 空链表：头结点后面暂时没有别的结点
	head->next = NULL;
	return head;
}

// 函数2：尾插法添加联系人（加到链表最后面）
// head：头结点，data：要添加的联系人信息
bool AddContactTail(Node* head, Contact data)
{
	// p用来找最后一个结点，先从head开始
	Node* p = head;
	// 循环，找到最后一个结点（next是NULL的结点）
	while (p->next != NULL)
	{
		p = p->next;
	}
	// 新建结点，存新联系人
	Node* newNode = new Node;
	if (newNode == NULL)
	{
		cout << "内存分配失败！" << endl;
		return false;
	}
	// 把传进来的联系人信息放进新结点
	newNode->data = data;
	// 新结点是最后一个，后面没人了
	newNode->next = NULL;
	// 原来最后一个结点接上这个新结点
	p->next = newNode;
	return true;
}

// 函数3：输入一个联系人信息，返回这个联系人
Contact InputContact()
{
	Contact c;
	cout << "请输入姓名：";
	cin >> c.name;
	cout << "请输入电话：";
	cin >> c.phone;
	cout << "请输入生日 年 月 日：";
	cin >> c.birthday.year >> c.birthday.month >> c.birthday.day;
	// 自动算年龄
	c.age = 2026 - c.birthday.year;
	return c;
}

// 函数4：打印单个联系人信息
void OutputContact(Contact c)
{
	cout << "姓名：" << c.name << "  电话：" << c.phone
		 << "  生日：" << c.birthday.year << "-" << c.birthday.month << "-" << c.birthday.day
		 << "  年龄：" << c.age << endl;
}

// 函数5：显示通讯录里所有联系人
void ShowAll(Node* head)
{
	// p从第一个真正的联系人开始（head是头结点，不存数据）
	Node* p = head->next;
	// 如果p是空，说明一个联系人都没有
	if (p == NULL)
	{
		cout << "通讯录为空！" << endl;
		return;
	}
	cout << "\n====所有联系人====" << endl;
	// 一直往后走，直到p等于NULL
	while (p != NULL)
	{
		OutputContact(p->data);
		p = p->next;
	}
}

// 函数6：按姓名查找联系人，找到返回结点地址，找不到返回NULL
Node* SearchByName(Node* head, char* name)
{
	Node* p = head->next;
	while (p != NULL)
	{
		// strcmp：对比两个字符串，一样就返回0
		if (strcmp(p->data.name, name) == 0)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

// 函数7：按电话查找联系人
Node* SearchByPhone(Node* head, char* phone)
{
	Node* p = head->next;
	while (p != NULL)
	{
		if (strcmp(p->data.phone, phone) == 0)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

// 函数8：找目标结点的前一个结点（删除的时候必须用）
Node* GetPreNode(Node* head, Node* target)
{
	Node* p = head;
	while (p->next != NULL)
	{
		if (p->next == target)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

// 函数9：删除指定联系人
bool DeleteContact(Node* head, Node* target)
{
	// 拿到目标的前一个结点
	Node* pre = GetPreNode(head, target);
	if (pre == NULL)
		return false;
	// 前一个结点直接跳过要删的结点，连到下一个
	pre->next = target->next;
	// 释放内存，防止内存泄漏
	delete target;
	return true;
}

// 函数10：修改联系人信息
bool ModifyContact(Node* target)
{
	if (target == NULL)
		return false;
	cout << "请输入新的信息：" << endl;
	Contact newc = InputContact();
	// 直接覆盖原来的数据
	target->data = newc;
	return true;
}

// 函数11：打印菜单，返回用户选择的数字
int PrintMenu()
{
	int op;
	cout << "\n====通讯录管理====" << endl;
	cout << "1 添加联系人" << endl;
	cout << "2 删除联系人" << endl;
	cout << "3 查找联系人" << endl;
	cout << "4 修改联系人" << endl;
	cout << "5 显示全部" << endl;
	cout << "6 退出" << endl;
	cout << "请选择：";
	cin >> op;
	return op;
}

int main()
{
  //主函数进行测试
	// 先创建空通讯录
	Node* head = InitAddressBook();
	int choice;
	// 用来临时存输入的姓名/电话
	char buf[50];

	// 死循环，一直显示菜单，直到选6退出
	while (true)
	{
		choice = PrintMenu();
		switch (choice)
		{
		case 1:
		{
			// 输入一个联系人
			Contact c = InputContact();
			// 添加到链表尾部
			AddContactTail(head, c);
			cout << "添加成功！" << endl;
			break;
		}
		case 2:
		{
			cout << "输入要删除的姓名：";
			cin >> buf;
			// 先查找这个名字
			Node* p = SearchByName(head, buf);
			if (p != NULL)
			{
				DeleteContact(head, p);
				cout << "删除成功！" << endl;
			}
			else
			{
				cout << "找不到这个联系人！" << endl;
			}
			break;
		}
		case 3:
		{
			int sub;
			cout << "1按姓名查找  2按电话查找：";
			cin >> sub;
			if (sub == 1)
			{
				cout << "输入姓名：";
				cin >> buf;
				Node* p = SearchByName(head, buf);
				if (p)
				{
					OutputContact(p->data);
				}
				else
				{
					cout << "未找到" << endl;
				}
			}
			else if (sub == 2)
			{
				cout << "输入电话：";
				cin >> buf;
				Node* p = SearchByPhone(head, buf);
				if (p)
				{
					OutputContact(p->data);
				}
				else
				{
					cout << "未找到" << endl;
				}
			}
			break;
		}
		case 4:
		{
			cout << "输入要修改的姓名：";
			cin >> buf;
			Node* p = SearchByName(head, buf);
			if (p)
			{
				ModifyContact(p);
				cout << "修改完成！" << endl;
			}
			else
			{
				cout << "找不到联系人！" << endl;
			}
			break;
		}
		case 5:
			ShowAll(head);
			break;
		case 6:
			cout << "程序退出" << endl;
			return 0;
		default:
			cout << "输入错误！请输入1~6" << endl;
		}
	}

  return 0;
}
