#include <iostream>
#include <set>
#include <stack>
#include <string>


using namespace std;

// Transition node (linked list)
struct TransitionNode {
    int toState;
    char inputChar; // 0 = epsilon
    TransitionNode* next;

    TransitionNode(int to, char ch) : toState(to), inputChar(ch), next(nullptr) {}
};

class NFA {
public:
    int startState;
    int acceptState;
    TransitionNode* transitions[10];  // max 10 states

    NFA(int start, int accept) : startState(start), acceptState(accept) {
        for (int i = 0; i < 10; i++)
            transitions[i] = nullptr;
    }

    void addTransition(int from, int to, char ch) {
        TransitionNode* node = new TransitionNode(to, ch);
        node->next = transitions[from];
        transitions[from] = node;
    }

    // Epsilon closure
    set<int> epsilonClosure(const set<int>& states) {
        set<int> closure = states;
        stack<int> st;
        for (int s : states) st.push(s);

        while (!st.empty()) {
            int s = st.top();
            st.pop();
            TransitionNode* node = transitions[s];
            while (node) {
                if (node->inputChar == 0 && closure.find(node->toState) == closure.end()) {
                    closure.insert(node->toState);
                    st.push(node->toState);
                }
                node = node->next;
            }
        }
        return closure;
    }

    // Move
    set<int> move(const set<int>& states, char ch) {
        set<int> result;
        for (int s : states) {
            TransitionNode* node = transitions[s];
            while (node) {
                if (node->inputChar == ch)
                    result.insert(node->toState);
                node = node->next;
            }
        }
        return result;
    }

    // Simulate NFA
    bool simulate(const string& input) {
        set<int> currentStates = epsilonClosure({startState});
        for (char ch : input) {
            currentStates = move(currentStates, ch);
            currentStates = epsilonClosure(currentStates);
        }
        return currentStates.find(acceptState) != currentStates.end();
    }

    // Print NFA transitions
    void printGraph() {
        cout << "\nNFA Transition Graph:\n";
        for (int i = 0; i < 10; i++) {
            if (!transitions[i]) continue;
            cout << "State " << i << ":\n";
            TransitionNode* node = transitions[i];
            while (node) {
                cout << "  --";
                if (node->inputChar == 0) cout << "ε";
                else cout << node->inputChar;
                cout << "--> State " << node->toState << "\n";
                node = node->next;
            }
        }
        cout << "Start State: " << startState << endl;
        cout << "Accept State: " << acceptState << endl;
    }

    // Show state info for tokens
    void showTokenInfo(const string& token) {
        if (token == "a") {
            cout << "Input: a -> State 8 -> State 9 (accepting)\n";
        } else if (token == "b") {
            cout << "Input: b -> State 4 -> State 5 -> State 6 (loop to start)\n";
        } else if (token == "a|b") {
            cout << "Input: a|b -> Either State 2 ('a' path) or State 4 ('b' path)\n";
        } else if (token == "(a|b)*") {
            cout << "Input: (a|b)* -> Loop between states 1,2,3,4,5,6,7 (repetition)\n";
        } else if (token == "(a|b)*a") {
            cout << "Input: (a|b)*a -> Final accepting path ends in State 9\n";
        } else {
            cout << "Unknown token. Valid options: a, b, a|b, (a|b)*, (a|b)*a\n";
        }
    }

    ~NFA() {
        for (int i = 0; i < 10; i++) {
            TransitionNode* node = transitions[i];
            while (node) {
                TransitionNode* temp = node;
                node = node->next;
                delete temp;
            }
        }
    }
};

int main() {
    NFA nfa(0, 9);

    // (a|b)*a construction
    nfa.addTransition(0, 1, 0);
    nfa.addTransition(0, 7, 0);
    nfa.addTransition(1, 2, 0);
    nfa.addTransition(1, 4, 0);
    nfa.addTransition(2, 3, 'a');
    nfa.addTransition(4, 5, 'b');
    nfa.addTransition(3, 6, 0);
    nfa.addTransition(5, 6, 0);
    nfa.addTransition(6, 1, 0);
    nfa.addTransition(6, 7, 0);
    nfa.addTransition(7, 8, 0);
    nfa.addTransition(8, 9, 'a');

    nfa.printGraph();

    cout << "\nEnter input (a, b, a|b, (a|b)*, (a|b)*a, or custom string): ";
    string input;
    getline(cin, input);

    // Check for the special tokens
    if (input == "a" || input == "b" || input == "a|b" ||
        input == "(a|b)*" || input == "(a|b)*a") {
        nfa.showTokenInfo(input);
    } else {
        bool accepted = nfa.simulate(input);
        cout << "Final State after scanning \"" << input << "\": "
             << (accepted ? "State 9 (Accepted)" : "Not in State 9 (Rejected)") << endl;
    }

    return 0;
}
