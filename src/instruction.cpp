#include <sstream>
#include <regex>
#include <algorithm>

#include "../include/instruction.hpp"
#include "../include/utility.hpp"

using namespace std;

InstructionMatcher::InstructionMatcher(vector<Instruction*> instructions) : instructions(instructions) {
    vector<string> lines = get_lines(SYNTAX_FILE);
}

InstructionMatcher::~InstructionMatcher() {
    for (Instruction* i : instructions)
        delete i;
}


string InstructionMatcher::get_error(string line) {
    if (line[0] == '#')
        return "";

    string cmd = line.substr(0, line.find(" "));

    for (Instruction* instruction : instructions)
        if (instruction->match_cmd(cmd))
            return instruction->match_args(line.substr(line.find(" "), line.size()));

    return "Invalid Instruction Type";
}

bool Instruction::match_cmd(string cmd) {
    return cmd == this->cmd;
}

string Instruction::match_args(string argstr) {
    argstr.erase(remove(argstr.begin(), argstr.end(), ' '), argstr.end());

    istringstream argstream(argstr);

    string arg;
    vector<string> args;

    while (getline(argstream, arg, ','))
        args.push_back(arg);

    if (args.size() != regeces.size())
        return "Invalid number of arguments";

    for (int i = 0; i < args.size(); i++)
        if (!regex_match(args[i], regex(regeces[i])))
            return "Argument '" + args[i] + "' does not match the required pattern";

    return "";
}

