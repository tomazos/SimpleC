// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#include "div_expr.h"

#include "node.h"

#include <string>

node make_div_expr(node num, node det)
{
	return node(new div_expr(num, det));
}

div_expr::div_expr(node num, node det) :
	my_num(num),
	my_det(det)
{
}

div_expr::~div_expr()
{
}

int div_expr::evaluate()
{
	expr& num = dynamic_cast<expr&>(my_num.get_content());
	expr& det = dynamic_cast<expr&>(my_num.get_content());

	int d = det.evaluate();

	if (d == 0)
		throw std::string("Divide by zero error");
	
	int n = num.evaluate();

	return n/d;
}

