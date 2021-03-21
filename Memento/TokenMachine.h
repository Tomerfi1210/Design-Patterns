#pragma once
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

struct Token
{
    int value;

    Token(int value) : value(value) {}
};

struct Memento
{
    vector<shared_ptr<Token>> tokens;
};

struct TokenMachine
{
    vector<shared_ptr<Token>> tokens;

    Memento add_token(int value)
    {
        return add_token(make_shared<Token>(value));
    }

    // adds the token to the set of tokens and returns the
    // snapshot of the entire system
    Memento add_token(const shared_ptr<Token>& token)
    {
        // todo
        tokens.emplace_back(token);
        Memento m;
        for (auto& t : tokens)
            m.tokens.emplace_back(make_shared<Token>(t->value));

        return m;
    }

    // reverts the system to a state represented by the token
    void revert(const Memento& m)
    {
        tokens.clear();
        for (auto& t : m.tokens)
            tokens.emplace_back(make_shared<Token>(t->value));
    }
};

int main()
{
    TokenMachine tm;
    cout << "Made a token with value=111 and kept a reference\n";
    auto token = make_shared<Token>(111);
    cout << "Added this token to the list\n";
    tm.add_token(token);
    auto m = tm.add_token(222);
    cout << "Changed this token's value to 333 :)\n";
    token->value = 333;
    tm.revert(m);

    cout << tm.tokens.size() << endl;
    cout << tm.tokens[0]->value << endl;
}