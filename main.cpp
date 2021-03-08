#include "StackList.h"
#include "StackArray.h"

using namespace std;

bool check_balance_brackets(std::string &text, int maxDeep = 30) {
  StackArray<char> stackArray = StackArray<char>(text.size());

  bool isBalanceBrackets = true;


  for (std::size_t i = 0; (i < text.size()) && (isBalanceBrackets == true); ++i) {

    char cText = text.at(i);

    switch (cText) {
      case '(':
      case '[':
      case '{':
        stackArray.push(cText);
        break;

      case ')':
        if (stackArray.pop() != '(') {
          isBalanceBrackets = false;
        }
        break;

      case ']':
        if (stackArray.pop() != '[') {
          isBalanceBrackets = false;
        }
        break;

      case '}':
        if (stackArray.pop() != '{') {
          isBalanceBrackets = false;
        }
        break;
    }
  }
  isBalanceBrackets = isBalanceBrackets && stackArray.isEmpty();

  return isBalanceBrackets;
}


//  Функция перевода арифметического выражения из инфиксной формы в постфиксную

int prec(char c) {
  if (c == '^')
    return 3;
  else if (c == '*' || c == '/')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

void infixToPostfix(const std::string &basicString, std::string &new_string, size_t stackSize = 30) {
  StackArray<char> st = StackArray<char>(basicString.size());
  st.push('N');
  int l = basicString.length();
  for (int i = 0; i < l; i++) {

    if ((basicString[i] >= 'a' && basicString[i] <= 'z') ||
        (basicString[i] >= 'A' && basicString[i] <= 'Z'))
      new_string += basicString[i];

    else if (basicString[i] == '(')

      st.push('(');

    else if (basicString[i] == ')') {
      while (st.top() != 'N' && st.top() != '(') {
        char c = st.top();
        st.pop();
        new_string += c;
      }
      if (st.top() == '(') {
        char c = st.top();
        st.pop();
      }
    } else {
      while (st.top() != 'N' && prec(basicString[i]) <=
                                prec(st.top())) {
        char c = st.top();
        st.pop();
        new_string += c;
      }
      st.push(basicString[i]);
    }

  }

  while (st.top() != 'N') {
    char c = st.top();
    st.pop();
    new_string += c;
  }

  cout << new_string << endl;
}

//Функция вычисления значения арифметического выражения в постфиксной форме

int evaluatePostfix(const string infix, size_t stackSize = 30) {
  StackArray<int> stackArray = StackArray<int>(infix.size());
  for (char symbol : infix) {
    if (symbol >= '0' && symbol <= '9') {
      int x = (int) symbol - 48;
      stackArray.push(x);
    }
    if (symbol == '-') {
      int first = stackArray.pop();
      int second = stackArray.pop();
      stackArray.push(second - first);
    }

    if (symbol == '/') {
      int first = stackArray.pop();
      int second = stackArray.pop();
      stackArray.push(second / first);
    }

    if (symbol == '*') {
      int first = stackArray.pop();
      int second = stackArray.pop();
      stackArray.push(first * second);
    }
    if (symbol == '+') {
      int first = stackArray.pop();
      int second = stackArray.pop();
      stackArray.push(first + second);
    }
  }
  return stackArray.pop();
}

void test() {

  StackList<int> stack_node;


  stack_node.push(4);
  stack_node.push(8);
  stack_node.push(9);
  stack_node.push(8);

  std::cout << "Size:\t" << stack_node.getSize() << '\n';

  std::cout << stack_node.pop() << '\n';
  std::cout << stack_node.pop() << '\n';
  std::cout << stack_node.pop() << '\n';
  std::cout << stack_node.pop() << '\n';

}

void test_2() {
  StackArray<int> stack_array(5);
  std::cout << "Size:\t" << stack_array.getSize() << '\n';

  stack_array.push(1);
  stack_array.push(2);
  stack_array.push(3);
  stack_array.push(4);
  stack_array.push(5);

  std::cout << stack_array.pop() << '\n';
  std::cout << stack_array.pop() << '\n';
  std::cout << stack_array.pop() << '\n';
  std::cout << stack_array.pop() << '\n';
  std::cout << stack_array.pop() << '\n';
}

int main() {
  test();

  test_2();
  //5.1
  string text01 = "()";
  cout << text01 << ": " << (check_balance_brackets(text01) ? "right" : "wrong") << endl;

  string text02 = "(([]))";
  cout << text02 << ": " << (check_balance_brackets(text02) ? "right" : "wrong") << endl;

  string text03 = "(([{}[]([])]))";
  cout << text03 << ": " << (check_balance_brackets(text03) ? "right" : "wrong") << endl;
  //5.2
  std::string exp = "A+B*C+D";
  std::string exp_2 = "(A+B)*(C+D)";
  std::string exp_3 = "A*B+C*D";
  std::string new_string;
  std::string new_string_2;
  std::string new_string_3;
  infixToPostfix(exp, new_string);
  infixToPostfix(exp_2, new_string_2);
  infixToPostfix(exp_3, new_string_3);
  //5.3
  std::cout << evaluatePostfix("463-*86-2/+");
  return 0;
}
