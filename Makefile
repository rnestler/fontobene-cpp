INC:= $(PWD)

all: test_parser

test_parser: test/parser.cpp fontobene/fontobene.h
	g++ -Wall -std=c++17 -I$(INC) test/parser.cpp -o test_parser

test: test_parser
	./test_parser

clean:
	rm -f test_parser
