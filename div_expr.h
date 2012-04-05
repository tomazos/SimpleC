// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#ifndef DIV_EXPR_H_
#define DIV_EXPR_H_

#include "expr.h"

#include "node.h"

class div_expr : public expr
{
public:
	div_expr(node num, node det);
	virtual ~div_expr();
	virtual int evaluate();

private:
	node my_num, my_det;
};

#endif /*DIV_EXPR_H_*/
