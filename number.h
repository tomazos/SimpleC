// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#ifndef NUMBER_H_
#define NUMBER_H_

#include "expr.h"

class number : public expr
{
public:
	number(int n);
	virtual ~number();

	virtual int evaluate();

private:
	int my_n;
};

#endif /*NUMBER_H_*/
