#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <queuep/queuep.h>
#include <doctest/doctest.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>

TEST_CASE("QueueR()") {
	QueueP temp;
	CHECK(temp.is_empty() == true);
}


TEST_CASE("") {
	QueueP q(7);
	CHECK(q.is_empty() == false);
	q.print();
}

TEST_CASE("") {
	QueueP que;
	que.push(100);
	que.push(1);
	que.push(24);
	que.push(13);
	que.print();
	QueueP que2(que);
	que.print();
	que2.print();

	QueueP emp(1);
	QueueP emp2(emp);
	emp.print();
	emp2.print();

	que2 = emp;
	que2.print();
	emp.print();
	que2 = que;
	que.print();
	que2.print();
	QueueP que3;
	que3.push(18);
	que3.push(180);
	que3.push(1);
	que2 = que3;
	que3.print();
	que2.print();

	que2.pop();
	que2.print();
	CHECK(que2.top() == 18);

}

TEST_CASE("") {

	QueueP p(init());
	p.print();
	QueueP x;
	x = (init());
	x.print();
}