// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#include "print_stmt.h"

#include "identifier.h"

#include <iostream>
#include <sstream>

node make_print_stmt(node arg)
{
	return node(new print_stmt(arg));
}	

print_stmt::print_stmt(node arg) :
	my_arg(arg)
{
}

print_stmt::~print_stmt()
{
}

void print_stmt::execute()
{
	std::stringstream ss;

	identifier& arg = dynamic_cast<identifier&> (my_arg.get_content());

	ss << arg.get_symbol() << " = " << arg.evaluate() << std::endl;

	std::cout << ss.str();
}

