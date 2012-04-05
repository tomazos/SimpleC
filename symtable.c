// simplec 1.0d1 - demonstration of compiler construction with yacc & lex
//
// Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
//
// This software is available under the licensing terms set forth in the
// attached LICENSE file.

#include "symtable.h"

#include <map>
#include <sstream>

std::vector<std::string> symtable::symbols;

std::string symtable::get_symbol(int id)
{
	if (id < symbols.size())
		return symbols[id];
	else
		return "INVALID";
}

int symtable::put_symbol(std::string symbol)
{
	for (int i = 0; i < symbols.size(); i++)
	{
		if (0 == symbols[i].compare(symbol))
			return i;
	}
	
	symbols.push_back(symbol);
	return symbols.size() - 1;
}

std::map<int, int> symtable::values;

void symtable::store_value(int id, int val)
{
	std::map<int, int>::const_iterator i = values.find(id);

	if (i != values.end())
		values[id] = val;
	else
	{
		std::stringstream ss;
		ss << "No such element " << get_symbol(id) << " (" << id << ")";
		throw ss.str();
	}
}

int symtable::retrieve_value(int id)
{
	return values[id];
}

void symtable::declare(int id)
{
	values[id] = 0;
}

