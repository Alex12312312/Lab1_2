#include "SetLab1_2_Novoselcev.h"
#include <iostream>

Node::Node(){}

Node::Node(int value, Node* next) {
	this->value = value;
	this->next = next;
}

NodeSet::NodeSet() {
	head = f1();
}

Node* NodeSet::f1() {
	return new Node();
}

bool Node::f2() {
	return this == nullptr || this->value == NULL;
}

bool NodeSet::f3(int value) {
	Node* curElem = this->head;
	/*if (!this->f2()) {
		if (this->value == value) {
			return 1;
		}
		else {
			return 0 + (this->next)->f3(value);
		}
	}*/
	while (!curElem->f2()) {
		if (curElem->value == value) {
			return 1;
		}
		curElem = curElem->next;
	}
	return 0;
}

Node* NodeSet::f4(int value) {
	if (f3(value)) return this->head;
	else if (this->head->value == NULL) {
		this->head->value = value;
		return this->head;
	}
	Node* elem = new Node(value, this->head);
	return elem;
	
}

Node* NodeSet::f5(int count, int min, int max, int kr) {
	Node* newLine = new Node();
	if (count < 6 && count > 9) {
		return this->head;
	}
	else if (max - min < count) {
		return this->head;
	}
	for (int i = 0; i < count; i++) {
		Node* newItem = this->f4(getNum(max, min, kr));
		while (newItem == this->head) {
			newItem = this->f4(getNum(max, min, kr));
		}
		this->head = newItem;
	}
	return head;
}


int getNum(int max, int min, int kr) {
	int result = rand() % (max - min) + min;
	while (result % kr != 0) {
		result = rand() % (max - min) + min;
	}
	return result;
}

int NodeSet::f6() {
	if (this->head->f2()) {
		return 0;
	}

	int len = 0;
	Node* elem = this->head;
	while (elem != nullptr)
	{
		len++;
		elem = elem->next;
	}
	return len;
};

string NodeSet::f7(string result) {
	if (head->f2()) return "";
	else {
		string nextRes = "";
		if (!start->next->f2()) nextRes = f7(start->next, result);
		return to_string(start->value) + result + nextRes;
	};
}

Node* NodeSet::f8() {
	Node* start = head;
	if (start->f2()) {
		return start;
	}

	Node* next;
	do {
		next = start->next;
		delete(start);
		start = next;
	} while (next != nullptr);
	return nullptr;
}

//Подмножество А-В
bool NodeSet::f9(NodeSet* B) {
	if (head->f2()) return true;
	else if (B->head->f2()) return false;
	int len = this->f6();
	Node* curElem = this->head;
	for (int i = 0; i < len; i++) {
		if (!B->f3(curElem->value)) return false;
		curElem = curElem->next;
	}
	return true;
}

//Равенство двух множеств А-В
bool NodeSet::f10(NodeSet* B) {
	return this->f9(B) && B->f9(this);
}

//Объединение двух множеств
NodeSet* NodeSet::f11(NodeSet* A, NodeSet* B) {
	NodeSet* result = new NodeSet();
	Node* curElemA = A->head;
	Node* curElemB = B->head;
	int lenA = A->f6();
	int lenB = B->f6();
	for (int i = 0; i < lenA; i++) {
		result->head = result->f4(curElemA->value);
		curElemA = curElemA->next;
	}
	for (int i = 0; i < lenB; i++) {
		result->head = result->f4(curElemB->value);
		curElemB = curElemB->next;
	}
	return result;
}

//Пересечение двух множеств
NodeSet* NodeSet::f12(NodeSet* A, NodeSet* B) {
	NodeSet* result = new NodeSet();
	Node* curElemA = A->head;
	int lenA = A->f6();
	for (int i = 0; i < lenA; i++) {
		if (B->f3(curElemA->value)) result->head = result->f4(curElemA->value);
		curElemA = curElemA->next;
	}
	return result;
}

//Разность множеств
NodeSet* NodeSet::f13(NodeSet* A, NodeSet* B) {
	NodeSet* result = new NodeSet();
	Node* curElemA = A->head;
	int lenA = A->f6();
	for (int i = 0; i < lenA; i++) {
		if (!B->f3(curElemA->value)) result->head = result->f4(curElemA->value);
		curElemA = curElemA->next;
	}
	return result;
}

//Симметричная разность
NodeSet* NodeSet::f14(NodeSet* A, NodeSet* B) {
	return f11(f13(A, B), f13(B, A));
}
