// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#include "stdio.h"

#include "parser.h"
#include "make_tree.h"
#include "node.h"
#include "stmt.h"
#include "stddef.h"
#include <iostream>
#include "errno.h"

extern FILE* yyin;

int yyparse ();

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "USAGE: simplec <source>" << std::endl;
		exit(1);
	}

	yyin = fopen(argv[1], "r");

	if (errno != 0)
	{
		perror("simplec");
		exit(errno);
	}
	yyparse();
	std::vector<node>& pt = get_parse_tree();
	
	for (std::vector<node>::const_iterator it = pt.begin(); it != pt.end(); ++it)
	{
		stmt& s = dynamic_cast<stmt&> (it->get_content());
		
		s.execute();
	}
	
	return 0;
}
