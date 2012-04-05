// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#ifndef SYMTABLE_H_
#define SYMTABLE_H_

#include <vector>
#include <string>
#include <map>

class symtable
{
public:
	static int put_symbol(std::string symbol);
	
	static std::string get_symbol(int id);

	static void store_value(int id, int val);
	
	static int retrieve_value(int id);

	static void declare(int id);
	
private:
	static std::vector<std::string> symbols;
	static std::map<int, int> values;
};

#endif /*SYMTABLE_H_*/
