#include <iostream>
#include "stack.cpp"
#include "textFormater.cpp"

bool areBracketsBalanced(const string& expr) {
    
    Stack<char> st;
    char x;

    
    for (char bracket : expr) {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            st.push(bracket);
            continue;
        }

        
        if (st.isEmpty()) 
            return false;

        switch (bracket) {
            case ')':
                x = st.pop();
                if (x != '(')
                    return false;
                break;
            case ']':
                x = st.pop();
                if (x != '[')
                    return false;
                break;
            case '}':
                x = st.pop();
                if (x != '{')
                    return false;
                break;
        }
    }

    
    return st.isEmpty();
}

int balancedBrackets() {
    TextFormater tf;
    string expression;
    std::cout << "Enter expression: ";
    std::cin >> expression;

    if (areBracketsBalanced(expression))
        tf.printColored("Brackets are BALANCED\n", ColorCode::GREEN);
    else
        tf.printColored("Brackets are NOT BALANCED\n",ColorCode::RED);

    return 0;
}
