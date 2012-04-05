// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#ifndef MAKE_TREE_H_
#define MAKE_TREE_H_

#include <vector>

#include "node.h"

std::vector<node>& get_parse_tree();

void process_statement(node stmt);

node make_local_var_decl(node type, node id);

node make_assignment(node lhs, node rhs);

node make_print_stmt(node expr);

node make_scan_stmt(node id);

node make_plus_expr(node a, node b);
node make_minus_expr(node a, node b);
node make_mult_expr(node a, node b);
node make_div_expr(node a, node b);
node make_negation(node expr);

node make_type_int();

node make_id(int id);
node make_num(int num);

#endif /*MAKE_TREE_H_*/
