// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

std::string infx2pstfx(std::string inf) {
    TStack <char, 100> stack;
    int vari, i = 0;
    std::string str;
  while (i < inf.size) {
    vari = priority(inf[i]);
    if (vari == 4) {
      str.push_back(inf[i] + ' ');
    } else {
      if (vari == 0 || isEmpty()) {
        stack.push(inf[i]);
      } else if (vari > priority(stack.get())) {
          stack.push(inf[i]);
      } else if ((vari == 1) && (stack.get != '(')) {
          str.push_back(stack.get() + ' ');
          stack.pop();
      } else if (inf[i] != ' ') {
          int perem = priority(stack.get());
          while ((perem >= priority(inf[i])) && (!stack.isEmpty())) {
            str.push_back(stack.get());
            str.push_back(' ');
            stack.pop();
          }
          stack.push(inf[i]);
      }
      i++;
  }
  while (!stack.isEmpty()) {
        str.push_back(stack.get());
        str.push_back(' ');
        stack.pop();
    }
    if (str[str.size() - 1] == ' ') {
        str.erase(str.size() - 1);
    }
    return str;
}

int eval(std::string pref) {
  TStack <int, 100> stack;
  int x, y;
  for (int i = 0; i < prior.size(); i++) {
      if (priority(prior[i]) < 4) {
          y = stack.get();
          stack.pop();
          x = stack.get();
          stack.pop();
          stack.push(count(x, y, prior[i]));
      } else if (prior[i] != ' ' && priority(prior[i]) == 4) {
          stack.push(prior[i] - '0');
      }
  }
  return stack.get();
}

int priority(char alt) {
    switch (alt) {
    case '(': return 0;
    case ')': return 1;
    case '-': case '+': return 2;
    case '*': case '/': return 3;
    default: return 4;
    }
}

int count(int i, int j, char sum) {
    switch (sum) {
    case '-': return i - j;
    case '+': return i + j;
    case '*': return i * j;
    case '/': return i / j;
    default: return 0;
    }
}
