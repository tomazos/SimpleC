// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#include "assignment.h"

#include "identifier.h"
#include "symtable.h"
#include "expr.h"

node make_assignment(node lhs, node rhs)
{
	return node(new assignment(lhs, rhs));
}

assignment::assignment(node lhs, node rhs) :
	my_lhs(lhs),
	my_rhs(rhs)
{
}

assignment::~assignment()
{
}

void assignment::execute()
{
	identifier& lhs = dynamic_cast<identifier&> (my_lhs.get_content());
	expr& rhs = dynamic_cast<expr&> (my_rhs.get_content());
	symtable::store_value(lhs.get_id(), rhs.evaluate());
}

