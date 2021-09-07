
build:
	g++ instruction.cpp -c
	g++ utility.cpp -c
	g++ parser.cpp -o parser --std=c++11

clean:
	rm instruction.o
	rm utility.o
	rm parser
