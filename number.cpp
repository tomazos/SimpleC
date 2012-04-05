// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#include "number.h"

#include "node.h"

node make_num(int num)
{
	return node(new number(num));
}

number::number(int n) :
	my_n(n)
{
}

number::~number()
{
}

int number::evaluate()
{
	return my_n;
}

