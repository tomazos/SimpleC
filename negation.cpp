// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#include "negation.h"

node make_negation(node a)
{
	return node(new negation(a));
}

negation::negation(node a) :
	my_a(a)
{
}

negation::~negation()
{
}

int negation::evaluate()
{
	expr& a = dynamic_cast<expr&> (my_a.get_content());

	return - a.evaluate();
}

