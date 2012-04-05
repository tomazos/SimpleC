// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#ifndef TYPE_INT_H_
#define TYPE_INT_H_

#include "content.h"

class type_int : public content
{
public:
	type_int();
	virtual ~type_int();
};

#endif /*TYPE_INT_H_*/
