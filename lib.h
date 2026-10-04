#ifndef LIB_H
#define LIB_H
#include<string>
using namespace std;
class Book {
private:
	string bar, name;//条形码 书名
	bool canBorrow;
	string borrowId;//借书人名
public:
	Book();
	Book(string b, string n);
	void setCan(bool b);
	bool getCan() const;//函数执行过程中不修改任何数据成员，只读取
	void setBorrowId(string id);
	string getBorrowId() const;
	string getBar() const;
	string getName() const;
	void show() const;//显示书籍信息 面向屏幕
};
class Student {
private:
	string id, name;
	int maxBor, nowBor;
public:
	Student();
	Student(string i, string n);
	string getId() const;
	int getNow() const;
	int getMax() const;
	void setNow(int x);
	bool borrow(Book* b);//接收图书的内存地址 修改图书对象的借阅状态
	bool giveBack(Book* b);
};
const int MAX_BOOK = 1000;
const int MAX_STU = 1000;
class Library {
private:
	Book books[MAX_BOOK];
	int bCnt;//当前实际有多少本书
	Student students[MAX_STU];
	int sCnt;//当前实际有多少个学生
public:
	Library();
	void addBook(string bar, string name);
	void addStu(string id, string name);
	Book* findBook(string bar);
	Student* findStu(string id);//返回图书或学生的内存地址
};
#endif 