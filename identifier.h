// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#ifndef IDENTIFIER_H_
#define IDENTIFIER_H_

#include "expr.h"

#include <string>

class identifier : public expr
{
public:
	identifier(int id);
	virtual ~identifier();
	
	int get_id();

	virtual int evaluate();

	std::string get_symbol();
	
private:
	int my_id;
};

#endif /*IDENTIFIER_H_*/
