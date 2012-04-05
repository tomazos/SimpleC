// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#include "identifier.h"

#include "node.h"

#include "symtable.h"

node make_id(int id)
{
	return node(new identifier(id));
}

identifier::identifier(int id) :
	my_id(id)
{
}

identifier::~identifier()
{
}

int identifier::evaluate()
{
	return symtable::retrieve_value(my_id);
}

std::string identifier::get_symbol()
{
	return symtable::get_symbol(my_id);
}

int identifier::get_id()
{
	return my_id;
}

