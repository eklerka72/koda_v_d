#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <queuep/queuep.h>
#include <doctest/doctest.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>


TEST_CASE("QueueR()") {
	QueueR temp;
	temp.is_empty();
}


TEST_CASE("") {
	QueueR q;
	q.push(7);
	CHECK(q.is_empty() == false);
	q.print();
}

TEST_CASE("") {
	// QueueP a;
	QueueR que(7);
	que.push(100);
	que.push(1);
	que.push(13);
	que.push(24);
	que.print();
	// CHECK(b.is_empty() == false);
	// a = b;
	// CHECK(a.is_empty() == false);
	// a.print();
	// QueueP c(13);
	// c.push_back(24);
	// c.push_back(7);
	// a = c;
	// a.print();
}