// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#include "scan_stmt.h"

#include <iostream>

#include "identifier.h"
#include "symtable.h"

node make_scan_stmt(node id)
{
	return node(new scan_stmt(id));
}

scan_stmt::scan_stmt(node id) :
	my_id(id)
{
}

scan_stmt::~scan_stmt()
{
}

void scan_stmt::execute()
{
	int i;

	identifier& id = dynamic_cast<identifier&> (my_id.get_content());

	std::cout << id.get_symbol() << " = ";

	std::cin >> i;

	std::cout << i << std::endl;

	symtable::store_value(id.get_id(), i);
}

