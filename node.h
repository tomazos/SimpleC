// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#ifndef NODE_H_
#define NODE_H_

#include "content.h"

class node
{
public:
	node() : my_content(0) {};
	
	node(content* cnt);
	node(const node& rhs);
	node& operator=(const node& rhs);
	~node();
	
	content& get_content() const
	{
		return *my_content;
	}
	
private:
	content* my_content;
};

#endif /*NODE_H_*/
