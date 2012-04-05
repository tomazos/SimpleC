// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#include "local_var_decl.h"

#include "identifier.h"
#include "symtable.h"

node make_local_var_decl(node type, node id)
{
	return node(new local_var_decl(type, id));
}

local_var_decl::local_var_decl(node type, node id) :
	my_type(type),
	my_id(id)
{
}

local_var_decl::~local_var_decl()
{
	
}

void local_var_decl::execute()
{
	identifier& id = dynamic_cast<identifier&> (my_id.get_content());

	symtable::declare(id.get_id());
}


