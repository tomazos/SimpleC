// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#ifndef EXPR_H_
#define EXPR_H_

#include "content.h"

class expr : public content
{
public:
	expr();
	virtual ~expr();

	virtual int evaluate() = 0;
};

#endif /*EXPR_H_*/
