#include <iostream>
#include <string>
#include <vector>

#include "../include/instruction.hpp"

using namespace std;

typedef vector<string> vcs;

vcs get_input() {
    string arr[] = {
        "mv a4, a3",
        "add x1, x2, x0",
        "sub x3, x2, x0",
        "li t0, 1",
//        "j code_end",
        "j 9",
//        "wrong"
    };
    vcs vs(arr, arr + sizeof(arr)/sizeof(arr[0]));
    return vs;
}

vector<Instruction*> get_instructions() {
    vector<Instruction*> instructions;

    string reg = "[a|x][0-9]";

    instructions.push_back(new Instruction("mv", vcs{reg, reg}));
    instructions.push_back(new Instruction("add", vcs{reg, reg, reg}));
    instructions.push_back(new Instruction("sub", vcs{reg, reg, reg}));
    instructions.push_back(new Instruction("li", vcs{"t[0-9]", "[0-9]"}));
    instructions.push_back(new Instruction("j", vcs{"[0-9]"}));

    return instructions;
}

vector<string> get_errors() {
    InstructionMatcher* matcher = new InstructionMatcher(get_instructions());

    vector<string> errors;
    vector<string> lines = get_input();

    for (int i = 0; i < lines.size(); i++) {
        string error = matcher->get_error(lines[i]);
        if (error != "")
            errors.push_back(to_string(i + 1) + ": " + error);
    }

    return errors;
}

int main() {
    vector<string> errors = get_errors();

    if (errors.size())
        for (string error : errors)
            cout << error << endl;
    else cout << "Successfully Parsed!" << endl;

    return 0;
}
