#include <string>
#include <vector>

#ifndef SYNTAX_FILE
#define SYNTAX_FILE "grammar.sntx"
#endif

using namespace std;

class Instruction {
    private:
        const vector<string> regeces;
        const string cmd;
    public:
        Instruction(string cmd, vector<string> regeces) : cmd(cmd), regeces(regeces) {}
        bool match_cmd(string cmd);
        string match_args(string argstr);
};

class InstructionMatcher {
    private:
        const vector<Instruction*> instructions;
    public:
        InstructionMatcher(vector<Instruction*>);
        ~InstructionMatcher();
        string get_error(string line);
};

