// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#ifndef SCAN_STMT_H_
#define SCAN_STMT_H_

#include "stmt.h"

#include "node.h"

class scan_stmt : public stmt
{
public:
	scan_stmt(node id);
	virtual ~scan_stmt();

	virtual void execute();
private:
	node my_id;
};

#endif /*SCAN_STMT_H_*/
