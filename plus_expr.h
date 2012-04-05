// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#ifndef PLUS_EXPR_H_
#define PLUS_EXPR_H_

#include "expr.h"

#include "node.h"

class plus_expr : public expr
{
public:
	plus_expr(node a, node b);
	virtual ~plus_expr();

	virtual int evaluate();

private:
	node my_a, my_b;
};

#endif /*PLUS_EXPR_H_*/
