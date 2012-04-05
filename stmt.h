// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#ifndef STMT_H_
#define STMT_H_

#include "content.h"

class stmt : public content
{
public:
	stmt();
	virtual ~stmt();
	
	virtual void execute() = 0;
};

#endif /*STMT_H_*/
