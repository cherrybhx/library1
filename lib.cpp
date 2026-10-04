#include "lib.h"
#include<iostream>
using namespace std;
Book::Book() :bar(""), canBorrow(true), borrowId("") {}//类外实现默认构造函数，：后面是初始化列表
Book::Book(string b, string n) :bar(b), name(n), canBorrow(true), borrowId("") {}
void Book::setCan(bool b) { canBorrow = b; }
bool Book::getCan()const { return canBorrow; }
string Book::getBorrowId() const { return borrowId; }
string Book::getBar() const { return bar; }
string Book::getName() const { return name; }
void Book::setBorrowId(string id) { borrowId = id; }
void Book::show() const {
	cout << "条形码：" << bar;
	cout << " 书名:" << name;
	if (canBorrow)
	{
		cout << " 可借阅" << endl;
	}
	else
		cout << " 已借出，借书人：" << borrowId << endl;
}
Student::Student() :id(""), name(""), maxBor(3), nowBor(0) {}//学生最多借三本
Student::Student(string i, string n) :id(i), name(n), maxBor(3), nowBor(0) {}
string Student::getId() const { return id; }
int Student::getNow()const { return nowBor; }
int Student::getMax()const { return maxBor; }
void Student::setNow(int x) { nowBor = x; }
bool Student::borrow(Book* b) {
	if (nowBor >= maxBor) {
		cout << "达到最大借书数\n";
		return false;
	}
	if (!b->getCan()) {
		cout << "该书已被借出" << endl;
		return false;
	}
	b->setCan(false);//修改成已经借出
	b->setBorrowId(id);
	nowBor++;
	cout << "借书成功" << endl;
	return true;
}
bool Student::giveBack(Book* b) {
	b->setCan(true);
	b->setBorrowId("");
	nowBor--;
	cout << "还书成功" << endl;
	return true;
}
Library::Library() :bCnt(0), sCnt(0) {}
void Library::addBook(string bar, string name) {
	books[bCnt] = Book(bar, name);
	bCnt++;
}
void Library::addStu(string id, string name) {
	students[sCnt] = Student(id, name);
	sCnt++;
}
Book* Library::findBook(string bar) {
	for (int i = 0; i < bCnt; i++) {
		if (books[i].getBar() == bar) {
			return &books[i];
		}
	}
	return nullptr;
}
Student* Library::findStu(string id) {
	for (int i = 0; i < sCnt; i++) {
		if (students[i].getId() == id) {
			return &students[i];
		}
	}
	return nullptr;
}


