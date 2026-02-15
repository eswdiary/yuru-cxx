#include <iostream>
#include <variant>
using namespace std;

// strong-typed enum
enum class Color { red, blue, green };

// "plain" enum
enum Light { red, blue, gree };

Color& operator++(Color& c) {
    using enum Color;

    switch(c) {
        case red: return c = blue;
        case blue: return c = green;
        case green: return c = red;
    }
}

// ===

enum class Type { ptr, num };
enum class Node { ptr, num };

// too easy to access......
union Value {
    Node* node;
    int num;
};

struct Entry {
    string name;
    Type type;
    // if we never used "node" and "num" at the same time......
    // Node* node;
    // int num;

    // Value value;
    variant<Node*, int> value;

};

void entry_func (Entry* entry_ptr){
    // if (entry_ptr->type == Type::num) {
    //     cout << entry_ptr->value.num;
    // }

    if (holds_alternative<int>(entry_ptr->value)) {
        cout << get<int>(entry_ptr->value) << endl;
    }

}


// ===

int main() {
    Color c1 = Color::red;

    // explicity
    int r1 = int(++c1);

    // implicity
    int l1 = blue;

    cout << r1 << endl;
    cout << l1 << endl;

    Entry e1 { "string", Type::num, 42 };
    entry_func(&e1);
}