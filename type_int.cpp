// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#include "type_int.h"

#include "node.h"

node make_type_int()
{
	return node(new type_int());
}

type_int::type_int()
{
}

type_int::~type_int()
{
}
