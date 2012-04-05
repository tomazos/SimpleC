// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#ifndef LOCAL_VAR_DECL_H_
#define LOCAL_VAR_DECL_H_

#include "stmt.h"

#include "node.h"

class local_var_decl : public stmt
{
public:
	local_var_decl(node type, node id);
	virtual ~local_var_decl();

	virtual void execute();

private:
	node my_type;
	node my_id;
};

#endif /*LOCAL_VAR_DECL_H_*/
