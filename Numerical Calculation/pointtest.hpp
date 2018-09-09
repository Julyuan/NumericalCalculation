#pragma once

#include"point.h"

void TestPoint() {
	PointSet jly;
	jly.Addpoint(2,0.5);
	jly.Addpoint(2.5, 0.4);
	jly.Addpoint(4, 0.25);

	Polynomial p = jly.Lagrange();
	p.Print();
}

