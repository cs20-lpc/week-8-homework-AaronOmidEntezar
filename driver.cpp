#include <iostream>
#include <string>
#include "StackFactory.hpp"

using namespace std;

template <typename T>
void showTopAndLength(Stack<T>* s, const string& name) {
    cout << name << " length = " << s->getLength();
    if (!s->isEmpty()) {
        cout << ", top = " << s->peek();
    }
    cout << endl;
}

template <typename T>
void basicOperationTest(Stack<T>* s, const string& name, const T& a, const T& b, const T& c) {
    cout << "\n--- " << name << " basic test ---\n";

    cout << "Initially empty? " << (s->isEmpty() ? "true" : "false") << endl;

    s->push(a);
    s->push(b);
    s->push(c);

    s->print();
    showTopAndLength(s, name);

    cout << "Pop once\n";
    s->pop();
    s->print();
    showTopAndLength(s, name);

    cout << "Rotate RIGHT (top to bottom)\n";
    s->rotate(Stack<T>::RIGHT);
    s->print();
    showTopAndLength(s, name);

    cout << "Rotate LEFT (bottom to top)\n";
    s->rotate(Stack<T>::LEFT);
    s->print();
    showTopAndLength(s, name);

    cout << "Clearing stack\n";
    s->clear();
    s->print();
    cout << "Empty after clear? " << (s->isEmpty() ? "true" : "false") << endl;
}

void exceptionTest() {
    cout << "\n--- Exception test ---\n";

    Stack<int>* linked = StackFactory<int>::GetStack();
    Stack<int>* array  = StackFactory<int>::GetStack(2);

    try {
        linked->pop();
    }
    catch (string& e) {
        cout << "LinkedListStack pop on empty: " << e << endl;
    }

    try {
        linked->peek();
    }
    catch (string& e) {
        cout << "LinkedListStack peek on empty: " << e << endl;
    }

    try {
        linked->rotate(Stack<int>::LEFT);
    }
    catch (string& e) {
        cout << "LinkedListStack rotate on empty: " << e << endl;
    }

    try {
        array->push(10);
        array->push(20);
        array->push(30);
    }
    catch (string& e) {
        cout << "ArrayStack overflow: " << e << endl;
    }

    delete linked;
    delete array;
}

void similarityTest() {
    cout << "\n--- Similarity test: LinkedListStack vs ArrayStack ---\n";

    Stack<int>* linked = StackFactory<int>::GetStack();
    Stack<int>* array  = StackFactory<int>::GetStack(10);

    for (int i = 1; i <= 5; i++) {
        linked->push(i);
        array->push(i);
    }

    linked->pop();
    array->pop();

    linked->push(99);
    array->push(99);

    linked->rotate(Stack<int>::RIGHT);
    array->rotate(Stack<int>::RIGHT);

    linked->rotate(Stack<int>::LEFT);
    array->rotate(Stack<int>::LEFT);

    cout << "LinkedListStack final state:\n";
    linked->print();
    cout << "ArrayStack final state:\n";
    array->print();

    cout << "Linked top = " << linked->peek()
         << ", Array top = " << array->peek() << endl;
    cout << "Linked length = " << linked->getLength()
         << ", Array length = " << array->getLength() << endl;

    delete linked;
    delete array;
}

int main() {
    Stack<int>* linkedInt = StackFactory<int>::GetStack();
    Stack<int>* arrayInt  = StackFactory<int>::GetStack(10);

    basicOperationTest(linkedInt, "LinkedListStack<int>", 10, 20, 30);
    basicOperationTest(arrayInt,  "ArrayStack<int>",      10, 20, 30);

    delete linkedInt;
    delete arrayInt;

    Stack<string>* linkedString = StackFactory<string>::GetStack();
    Stack<string>* arrayString  = StackFactory<string>::GetStack(10);

    basicOperationTest<string>(linkedString, "LinkedListStack<string>", string("red"), string("green"), string("blue"));
    basicOperationTest<string>(arrayString,  "ArrayStack<string>",      string("red"), string("green"), string("blue"));

    delete linkedString;
    delete arrayString;

    Stack<char>* linkedChar = StackFactory<char>::GetStack();
    Stack<char>* arrayChar  = StackFactory<char>::GetStack(10);

    basicOperationTest(linkedChar, "LinkedListStack<char>", 'A', 'B', 'C');
    basicOperationTest(arrayChar,  "ArrayStack<char>",      'A', 'B', 'C');

    delete linkedChar;
    delete arrayChar;

    exceptionTest();
    similarityTest();

    return 0;
}