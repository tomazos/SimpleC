// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#ifndef PRINT_STMT_H_
#define PRINT_STMT_H_

#include "stmt.h"

#include "node.h"

class print_stmt : public stmt
{
public:
	print_stmt(node arg);
	virtual ~print_stmt();

	virtual void execute();

private:
	node my_arg;
};

#endif /*PRINT_STMT_H_*/
