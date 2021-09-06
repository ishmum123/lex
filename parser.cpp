#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef vector<string> vcs;
typedef map<string, vcs> msv;
typedef pair<string, vcs> psv;

template <typename T> 
T compare(T x, T y) {
   return x == y;
}

vcs get_input() {
    string arr[] = {
        "mv a4, a3",
        "add x1, x2, x0",
        "sub x3, x2, x0",
        "li t0, 1",
        "j code_end",
        "wrong"
    };
    vcs vs(arr, arr + sizeof(arr)/sizeof(arr[0]));
    return vs;
}

msv get_syntax_map() {
    msv m;

    m.insert(psv("mv", vcs{"a3", "a4"}));
    m.insert(psv("add", vcs{"x1", "x2", "x3"}));
    m.insert(psv("sub", vcs{"x3", "x2", "x0"}));
    m.insert(psv("li", vcs{"t0", "1"}));
    m.insert(psv("j", vcs{"1"}));

    return m;
}

int main() {
    vcs v = get_input();
    msv m = get_syntax_map();

    for (string s : v) {
        string ins = s.substr(0, s.find(" "));
        msv::iterator rez = m.find(ins);
        if (rez != m.end()) cout << m.find(ins)->second[0] << endl;
        else cout << "Could not find token '" << ins << "'" << endl;
    }

    return 0;
}
