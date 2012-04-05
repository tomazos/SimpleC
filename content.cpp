// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#include "content.h"

content::content() :
	ref_count(0)
{
}

content::~content()
{
}

void content::inc_ref_count()
{
	ref_count++;
}
	
void content::dec_ref_count()
{
	ref_count--;
	
	if (ref_count == 0)
		delete this;
}
