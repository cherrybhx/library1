#include <iostream>
#include "lib.h"
using namespace std;

void menu() {
	cout << "\n1加图书 2加学生 3借书 4还书 5查书 0退出\n请输入：";
}

int main() {
	Library lib;
	int op;
	while (true) {
		menu();
		cin >> op;
		if (op == 0) {
			break;
		}
		else if (op == 1) {
			string b, n;
			cout << "条码 书名:";
			cin >> b >> n;
			lib.addBook(b, n);
		}
		else if (op == 2) {
			string id, n;
			cout << "学号 姓名:";
			cin >> id >> n;
			lib.addStu(id, n);
		}
		else if (op == 3) {
			string sid, bid;
			cout << "学号 图书条码:";
			cin >> sid >> bid;
			Student* s = lib.findStu(sid);
			Book* b = lib.findBook(bid);
			if (!s || !b) {
				cout << "不存在\n";
				continue;//回到while开头重新打印菜单，不往下跑代码
			}
			s->borrow(b);
		}
		else if (op == 4) {
			string sid, bid;
			cout << "学号 图书条码:";
			cin >> sid >> bid;
			Student* s = lib.findStu(sid);
			Book* b = lib.findBook(bid);
			if (!s || !b) {
				cout << "不存在\n";
				continue;//回到while开头重新打印菜单，不往下跑代码
			}
			s->giveBack(b);
		}
		else if (op == 5) {
			string bar;
			cout << "输出条码：\n";
			cin >> bar;
			Book* p = lib.findBook(bar);
			if (p) {
				p->show();
			}
			else {
				cout << "找不到\n";
			}
		}
	}
	return 0;
}
