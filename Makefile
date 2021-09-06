
build:
	g++ utility.cpp -c
	g++ parser.cpp -o parser --std=c++11

clean:
	rm utility.o
	rm parser
