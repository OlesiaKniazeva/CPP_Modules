#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }

    std::stack<int> s(mstack);


    std::cout << "------------" << std::endl;

    std::cout << mstack.size() << '\n';

    if (mstack.empty()) {
      std::cout << "Empty stack" << '\n';
    }
    else {
      std::cout << "Stack isn't empty" << '\n';
    }

    std::cout << "------------" << std::endl;

    MutantStack<std::string> str_stack;
    if (str_stack.empty()) {
      std::cout << "Empty stack" << '\n';
    }
    else {
      std::cout << "Stack isn't empty" << '\n';
    }
    str_stack.push("cat");
    str_stack.push("dog");
    str_stack.push("horse");
    for (MutantStack<std::string>::iterator it = str_stack.begin();
        it != str_stack.end(); ++it) {
      std::cout << *it << '\n';
    }
    str_stack.pop();
    std::cout << "------------" << std::endl;
    for (MutantStack<std::string>::iterator it = str_stack.begin();
        it != str_stack.end(); ++it) {
      std::cout << *it << '\n';
    }

    return 0;
}
