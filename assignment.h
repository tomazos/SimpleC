// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#ifndef ASSIGNMENT_H_
#define ASSIGNMENT_H_

#include "stmt.h"

#include "node.h"

class assignment : public stmt
{
public:
	assignment(node lhs, node rhs);
	virtual ~assignment();
	
	virtual void execute();
	
private:
	node my_lhs;
	node my_rhs;
};

#endif /*ASSIGNMENT_H_*/
