// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#ifndef NEGATION_H_
#define NEGATION_H_

#include "expr.h"

#include "node.h"

class negation : public expr
{
public:
	negation(node a);
	virtual ~negation();
	
	virtual int evaluate();

private:
	node my_a;
};

#endif /*NEGATION_H_*/
