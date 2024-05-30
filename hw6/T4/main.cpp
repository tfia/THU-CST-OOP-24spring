#include "MyPtr.h"
#include <iostream>
#include <memory>
using namespace std;

class Test {
private:
	static int count;
	int x;
public:
	Test(int _x = 0): x(_x) {
		count++;
	}
	~Test() {
		count--;
	}
	int getX() {return x;}
	int operator += (int t) {
		return x += t;
	}
	friend ostream& operator<<(ostream& out, Test& t);
	static int getCount() {return count;}
};

class Node {
private:
	int x;
	static int count;
public:
	MyWeakPtr<Node> prev;
    MySharedPtr<Node> next;
	Node(int x) : x(x) { count++; }
	~Node() { count--; }
	int getX() { return x; }
	void setX(int _x) { x = _x; }
	friend ostream& operator<<(ostream& out, Node& t);
	static int getCount() {return count;}
};

ostream& operator<<(ostream& out, Test& t) {
	out << t.x;
	return out;
}

ostream& operator<<(ostream& out, Node& t) {
	out << t.x;
	return out;
}

int Node::count = 0;
int Test::count = 0;

// 测试内存管理和引用计数
#ifdef _SUBTASK_1_
void f1() {
    MySharedPtr<Test> p1(new Test(2));
    MySharedPtr<Test> p2(new Test(1));
    MySharedPtr<Test> p3(p2);
    MySharedPtr<Test> p4(p3);
    cout << p1.use_count() << p2.use_count() << p3.use_count() << p4.use_count() << endl;
	return;
}
#endif

// 测试构造和赋值
#ifdef _SUBTASK_2_
void f2() {
    MySharedPtr<Test> p1(new Test(111111));
	MySharedPtr<Test> p2(new Test(222222));
	MySharedPtr<Test> p3(p1);
	p3 = p2;
	p1 = p2;
	MySharedPtr<Test> p4(std::move(p1));
	p1 = p4;
	p3 = std::move(p4);
	cout << p1.use_count() << p2.use_count() << p3.use_count() << p4.use_count() << endl;
	return;
}
#endif

// 测试运算符重载和弱指针
#ifdef _SUBTASK_3_
void f3() {
	MySharedPtr<Node> node1(new Node(1));
	MySharedPtr<Node> node2(new Node(2));
	node2->prev = node1;
	node1->next = node2;
	if (auto sp = node2->prev.lock()) {
		sp->setX(100);
		cout << sp->getX() << endl;
	}
	if (auto sp = node1->prev.lock()) {
		// 这里实际无法到达，因为node1->prev为空指针，转化为MySharedPtr后也为空指针
		// 但是sp会被构造出来
		sp->setX(100);
	} else {
		cout << "the converted sptr is null.\n";
	}
	int i = 0;
	for (auto sp = node1; sp; sp = sp->next) {
		cout << "x of node" << ++i << ": " << *sp << endl;
	}
}
#endif

// 综合测试
#ifdef _SUBTASK_4_
void f4() {
	cout << "start initialization.\n";
	MySharedPtr<Node> ptr[10];
	for (int i = 0; i < 10; i++) {
		ptr[i] = MySharedPtr<Node>(new Node(i));
	}
	cout << "initialization completed.\n";
	cout << "start link table connection.\n";
	ptr[0]->next = ptr[1];
	for (int i = 1; i < 9; i++) {
		ptr[i]->next = ptr[i + 1];
		ptr[i]->prev = ptr[i - 1];
	}
	ptr[9]->prev = ptr[8];
	cout << "link table connection completed.\n";
	cout << "start calculation of sum.\n";
	int sum = 0;
	for (MySharedPtr<Node> sp = ptr[9]; sp; sp = sp->prev.lock()) {
		sum += sp->getX();
	}
	cout << sum << endl;
	ptr[1]->setX(6);
	ptr[5]->setX(10);
	sum = 0;
	for (auto sp = ptr[0]; sp; sp = sp->next) {
		sum += sp->getX();
	}
	cout << sum << endl;
	cout << "calculation of sum comleted.\n";

	MySharedPtr<Node> sp2(ptr[2]);
	MyWeakPtr<Node> wp4(ptr[4]);
	MySharedPtr<Node> sp4(wp4);

	cout << "start to print use_count of every node.\n";
	for (int i = 0; i < 10; i++) {
		cout << ptr[i]->prev.use_count() << ' ' << ptr[i].use_count() << ' ' << ptr[i]->next.use_count() << endl;
	}
	cout << "print use_count of every node completed.\n";
}
#endif

int main() {
    #ifdef _SUBTASK_1_
		f1();
	#endif
	#ifdef _SUBTASK_2_
		f2();
	#endif
	#ifdef _SUBTASK_3_
		f3();
	#endif
	#ifdef _SUBTASK_4_
		f4();
	#endif
    if (Test::getCount() > 0 || Node::getCount() > 0) {
		cout << "Memory leak detected!" << endl;
	}
	else {
		cout << "Accepted!" << endl;
	}

    return 0;
}