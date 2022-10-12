#include "queuep.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>


QueueP::Node::Node(int _num, std::unique_ptr<Node> _next) {
	num = _num;
	next = std::move(_next);
}

QueueP::~QueueP()
{
	while (first)
		first = std::move(first->next);
}

QueueP::QueueP() {
	first = nullptr;
}

QueueP::QueueP(int _num) {
	first = std::unique_ptr<Node>(new Node(_num, nullptr));
}

QueueP::QueueP(const QueueP& que) {
	auto que_get = que.first.get();
	if (que.first != nullptr) {
		first = std::unique_ptr<Node>(new Node(que_get->num, nullptr));
		auto tempget = first.get();
		while (que_get->next != nullptr) {
			que_get = que_get->next.get();
			tempget->next = std::unique_ptr<Node>(new Node(que_get->num, nullptr));
			tempget = tempget->next.get();
		}
	}
}

QueueP::QueueP(QueueP&& que) {
	first = std::move(que.first);
	que.first = nullptr;
}


bool QueueP::is_empty() {
	if (first == nullptr) {
		return (true);
	}
	else {
		return (false);
	}
}


void QueueP::push(int _num) {
	if (first == nullptr || _num < first.get()->num) {
		first = std::unique_ptr<Node>(new Node(_num, std::move(first)));
	}
	else {
		auto tempget = first.get();
		while (tempget->next != nullptr && _num >= tempget->next.get()->num) {
			tempget = tempget->next.get();
		}
		tempget->next = std::unique_ptr<Node>(new Node(_num, std::move(tempget->next)));
	}
}


void QueueP::print() {
	if (is_empty()) {
		return;
	}
	auto tempget = first.get();
	while (tempget) {
		std::cout << tempget->num << ' ';
		tempget = tempget->next.get();
	}
	std::cout << std::endl;
}


QueueP& QueueP::operator= (const QueueP& que) {
	this->first = nullptr;
	auto que_get = que.first.get();
	if (que.first != nullptr) {
		first = std::unique_ptr<Node>(new Node(que_get->num, nullptr));
		auto tempget = first.get();
		while (que_get->next != nullptr) {
			que_get = que_get->next.get();
			tempget->next = std::unique_ptr<Node>(new Node(que_get->num, nullptr));
			tempget = tempget->next.get();
		}
	}
	return *this;
}

QueueP& QueueP::operator=(QueueP&& que) {
	first = std::move(que.first);
	que.first = nullptr;
	return *this;
}


int QueueP::top() {
	if (first == nullptr) {
		throw std::out_of_range("Nullptr");
	}
	else {
		return first.get()->num;
	}
}

void QueueP::pop() {
	if (first == nullptr) {
		throw std::out_of_range("Nullptr");
	}
	else {
		//auto temp_get = first.get()->next.get();
		//first = std::unique_ptr<Node>(new Node(temp_get->num, std::move(temp_get->next)));
		first = std::move(first.get()->next);
	}
}

QueueP init() {
	QueueP temp;
	temp.push(100);
	temp.push(10);
	temp.push(200);
	temp.push(20);
	return temp;
}