# simplec 1.0d1 - demonstration of compiler construction with yacc & lex
#
# Copyright (C) 2007   Andrew Tomazos <andrew@tomazos.com>
#
# This software is available under the licensing terms set forth in the
# attached LICENSE file.

OBJECTS := $(patsubst %.c,%.o, $(wildcard *.c))
OBJECTS += $(patsubst %.cpp,%.o, $(wildcard *.cpp))
OBJECTS += parser.o lexer.o



AUTOGENS := parser.c parser.h lexer.c parser.output test_output tags

PROGNAME := simplec

VERSION := $(shell cat VERSION)

PACKAGE := $(PROGNAME)-$(VERSION)

default: tags test

package: clean ../$(PACKAGE).tar.gz

../$(PACKAGE).tar.gz:
	cd .. && cp -r $(PROGNAME) $(PACKAGE) && tar zcvf $(PACKAGE).tar.gz $(PACKAGE) && rm -rf $(PACKAGE)

test: $(PROGNAME)
	./$(PROGNAME) test_program < test_input > test_output
	diff test_output test_expected
	@echo test passed.

run: $(PROGNAME)
	./$(PROGNAME)

all: $(PROGNAME)

clean:
	rm -f $(OBJECTS) $(PROGNAME) $(AUTOGENS)

$(PROGNAME): $(OBJECTS)
	g++ -ggdb -Wall $^ -o $@

%.o: %.c
	g++ -ggdb -Wall -Wno-sign-compare -c $< -o $@

%.o: %.cpp
	g++ -ggdb -Wall -Wno-sign-compare -c $< -o $@

lexer.c: lexer.yy parser.h
	flex -o $@ $<

parser.c parser.h: parser.y
	bison -t -rall --locations -d -o $@ $<

main.c: parser.h

tags: $(wildcard *.c) $(wildcard *.cpp)
	ctags -R .

.PHONY: all run clean

