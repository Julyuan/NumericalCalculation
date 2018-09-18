#pragma once

#include"point.h"

void TestPoint() {
	PointSet jly,jlyy;
	jly.Addpoint(2,0.5);
	jly.Addpoint(2.5, 0.4);
	jly.Addpoint(4, 0.25);
	std::cout << "Lagrange²âÊÔ:"<<std::endl;
	Polynomial p = jly.Lagrange();
	p.Print();

	jlyy.Addpoint(1.0,0.7651977);
	jlyy.Addpoint(1.3,0.620086);
	jlyy.Addpoint(1.6,0.4554022);
	jlyy.Addpoint(1.9,0.2818186);
	jlyy.Addpoint(2.2,0.1103623);
	std::cout << "Neville²âÊÔ:" << std::endl;
	//std::cout << jly.Neville(1.5) << std::endl;
	printf("%lf\n", jlyy.Neville(1.5));
}

