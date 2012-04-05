// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#include "make_tree.h"

#include "stdio.h"

#include <vector>

typedef std::vector<node> V_node;
 
static V_node parse_tree;

std::vector<node>& get_parse_tree()
{
	return parse_tree;
}

void process_statement(node stmt)
{
	parse_tree.push_back(stmt);
}	
