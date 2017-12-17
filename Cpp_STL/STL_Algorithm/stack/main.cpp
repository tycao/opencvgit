#include <iostream>
#include "stack_defined.h"


int main(int argc, char *argv[])
{
    try
    {
        Stack<int> st;

        // push 3 elements into the stack above
        st.push(1);
        st.push(2);
        st.push(3);

        // pop and print 2 elements from the stack
        std::cout << st.pop() << std::endl;
        std::cout << st.pop() << std::endl;

        // modify top element
        st.top() = 77;

        // push two elements into the stack
        st.push(4);
        st.push(5);

        // pop one element without processing it
        st.pop();

        /*
         * pop and print 3 elements
         * - ERROR: one more element undefined
        */
        std::cout << st.pop() << std::endl;
        std::cout << st.pop() << std::endl;
        std::cout << st.pop() << std::endl;
    }
    catch (const Stack<int>::ReadEmptyStack& e)
    {
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    return 0;
}
