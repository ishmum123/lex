build: instruction
	mkdir -p "bin"
	g++ src/parser.cpp build/instruction.o --std=c++11 -o bin/parser

instruction:
	mkdir -p "build"
	g++ src/instruction.cpp -c --std=c++11 -o build/instruction.o

clean:
	rm "build/instruction.o" "bin/parser"