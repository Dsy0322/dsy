#include <iostream>
using namespace std;
#define MAXSIZE 100  
typedef struct {
    int data[MAXSIZE];
    int length;
} SqList;
void InitList(SqList& L) {
    L.length = 0;
}
void CreateList(SqList& L, int n) {
    if (n < 0 || n > MAXSIZE) {
        cout << "创建失败，个数非法！" << endl;
        return;
    }
    L.length = n;
    cout << "请输入" << n << "个元素：";
    for (int i = 0; i < n; i++) {
        cin >> L.data[i];
    }
}
bool IsEmpty(SqList L) {
    return L.length == 0;
}
int GetLength(SqList L) {
    return L.length;
}
void PrintList(SqList L) {
    if (IsEmpty(L)) {
        cout << "顺序表为空！" << endl;
        return;
    }
    cout << "顺序表元素：";
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}
bool GetElem(SqList L, int position, int& e) {
    if (position < 1 || position > L.length) {
        return false;
    }
    e = L.data[position - 1];
    return true;
}
int Search_Seq(SqList L, int value) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == value) {
            return i + 1;
        }
    }
    return 0;
}
int Search_Bin(SqList L, int value) {
    int low = 0, high = L.length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (L.data[mid] == value) {
            return mid + 1;
        }
        else if (L.data[mid] < value) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return 0;
}
bool ListInsert(SqList& L, int position, int x) {
    if (L.length >= MAXSIZE) {
        cout << "顺序表已满，无法插入！" << endl;
        return false;
    }
    if (position < 1 || position > L.length + 1) {
        cout << "插入位置非法！" << endl;
        return false;
    }
    for (int i = L.length; i >= position; i--) {
        L.data[i] = L.data[i - 1];
    }
    L.data[position - 1] = x;
    L.length++;
    return true;
}
bool ListDelete_Pos(SqList& L, int position, int& e) {
    if (IsEmpty(L)) {
        cout << "顺序表为空，不能删除！" << endl;
        return false;
    }
    if (position < 1 || position > L.length) {
        cout << "删除位置非法！" << endl;
        return false;
    }
    e = L.data[position - 1];
    for (int i = position; i < L.length; i++) {
        L.data[i - 1] = L.data[i];
    }
    L.length--;
    return true;
}
void ListDelete_AllVal(SqList& L, int value) {
    int j = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] != value) {
            L.data[j++] = L.data[i];
        }
    }
    L.length = j;
}
int main() {
    SqList L;
    InitList(L);
    int n, op, pos, x, e, val;
    cout << "=====顺序表菜单=====" << endl;
    cout << "2 创建顺序表" << endl;
    cout << "3 判断空表" << endl;
    cout << "4 获取长度" << endl;
    cout << "5 输出顺序表" << endl;
    cout << "6 获取指定位置元素" << endl;
    cout << "71 顺序查找 | 72 二分查找" << endl;
    cout << "8 指定位置前插入元素" << endl;
    cout << "9 删除指定位置元素" << endl;
    cout << "10 删除所有值为value的元素" << endl;
    cout << "0 退出" << endl;
    while (true) {
        cout << "\n请输入操作：";
        cin >> op;
        if (op == 0) break;
        switch (op) {
        case 2:
            cout << "输入创建元素个数：";
            cin >> n;
            CreateList(L, n);
            break;
        case 3:
            if (IsEmpty(L)) cout << "顺序表为空" << endl;
            else cout << "顺序表非空" << endl;
            break;
        case 4:
            cout << "顺序表长度 = " << GetLength(L) << endl;
            break;
        case 5:
            PrintList(L);
            break;
        case 6:
            cout << "输入要获取的位置：";
            cin >> pos;
            if (GetElem(L, pos, e))
                cout << "该位置元素值：" << e << endl;
            else
                cout << "位置错误" << endl;
            break;
        case 71:
            cout << "输入查找值：";
            cin >> val;
            pos = Search_Seq(L, val);
            if (pos) cout << "顺序查找，位置：" << pos << endl;
            else cout << "未找到" << endl;
            break;
        case 72:
            cout << "输入查找值：";
            cin >> val;
            pos = Search_Bin(L, val);
            if (pos) cout << "二分查找，位置：" << pos << endl;
            else cout << "未找到（注意二分查找要求顺序表升序）" << endl;
            break;
        case 8:
            cout << "输入插入位置、插入元素：";
            cin >> pos >> x;
            if (ListInsert(L, pos, x)) cout << "插入成功" << endl;
            break;
        case 9:
            cout << "输入删除位置：";
            cin >> pos;
            if (ListDelete_Pos(L, pos, e)) cout << "删除元素：" << e << endl;
            break;
        case 10:
            cout << "输入要删除的值：";
            cin >> val;
            ListDelete_AllVal(L, val);
            cout << "已删除所有等于" << val << "的元素" << endl;
            break;
        }
    }
    return 0;
}