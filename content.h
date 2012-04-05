// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#ifndef CONTENT_H_
#define CONTENT_H_

class content
{
public:
	content();
	virtual ~content();

	void inc_ref_count();
	
	void dec_ref_count();

private:
	int ref_count;
};

#endif /*CONTENT_H_*/
