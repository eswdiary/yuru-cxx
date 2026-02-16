#include <iostream>

class My_code {
    public:
        My_code();
        int main();
};

int My_code::main() {
    return 0;
}

int main() {
    return My_code::main();
}