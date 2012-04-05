// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#include "plus_expr.h"

node make_plus_expr(node a, node b)
{
	return node(new plus_expr(a, b));
}

plus_expr::plus_expr(node a, node b) :
	my_a(a),
	my_b(b)
{
}

plus_expr::~plus_expr()
{
}

int plus_expr::evaluate()
{
	expr& a = dynamic_cast<expr&> (my_a.get_content());
	expr& b = dynamic_cast<expr&> (my_b.get_content());

	return a.evaluate() + b.evaluate();
}

