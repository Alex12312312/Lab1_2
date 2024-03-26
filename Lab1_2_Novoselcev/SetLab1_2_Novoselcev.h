#pragma once
#include <string>

using namespace std;
int getNum(int, int, int);
struct Node {
	int value = NULL;
	Node* next = NULL;
	Node();
	Node(int, Node*);
public:
	bool f2();
};
class NodeSet {
	public:
		NodeSet();
	Node* head = NULL;
	static Node* f1();

	bool f3(int);

	Node* f4(int);

	Node* f5(int, int, int, int);

	int f6();

	string f7(string);

	Node* f8();

	bool f9(NodeSet*);

	bool f10(NodeSet*);

	static NodeSet* f11(NodeSet*, NodeSet*);

	static NodeSet* f12(NodeSet*, NodeSet*);

	static NodeSet* f13(NodeSet*, NodeSet*);

	static NodeSet* f14(NodeSet*, NodeSet*);

};