// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#include "node.h"

node::node(content* cnt)
{
	my_content = cnt;

	if (my_content != 0)
		my_content->inc_ref_count();
}

node::~node()
{
	if (my_content != 0)
		my_content->dec_ref_count();
}

node::node(const node& rhs)
{
	my_content = rhs.my_content;

	if (my_content != 0)
		my_content->inc_ref_count();
}

node& node::operator=(const node& rhs)
{
	my_content = rhs.my_content;

	if (my_content != 0)
		my_content->inc_ref_count();

	return *this;
}
