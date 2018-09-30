#pragma once

#include"point.h"

void TestPoint() {
	PointSet jly,jlyy;
	jly.Addpoint(2,0.5);
	jly.Addpoint(2.5, 0.4);
	jly.Addpoint(4, 0.25);
	std::cout << "µã¼¯¶ÁÈë²âÊÔ:" << std::endl;
	jly.PrintPointSet();
	std::cout << "Lagrange²âÊÔ:"<<std::endl;
	Polynomial p = jly.Lagrange();
	p.Print();

	jly.Clear();
	std::cout << "ÇåÀí²âÊÔ" << std::endl;
	jly.PrintPointSet();

	jly.Addpoints({ 1,2,3,4,5,6 });
	std::cout << "initializer_list²âÊÔ" << std::endl;
	jly.PrintPointSet();

	jlyy.Addpoint(1.0,0.7651977);
	jlyy.Addpoint(1.3,0.620086);
	jlyy.Addpoint(1.6,0.4554022);
	jlyy.Addpoint(1.9,0.2818186);
	jlyy.Addpoint(2.2,0.1103623);
	std::cout << "Neville²âÊÔ:" << std::endl;
	//std::cout << jly.Neville(1.5) << std::endl;
	printf("%lf\n", jlyy.Neville(1.5));

	
}

