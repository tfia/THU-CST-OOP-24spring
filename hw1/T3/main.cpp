#include <iostream>
#include "Parser.h"

int main(int argc, char *argv[]) {
    Parser parser = Parser();

    parser.add_argument("--first", 1, "First number");
    parser.add_argument("--second", 2, "Next number");
    parser.add_argument("--third", 3, "Third number");

    char *args = new char[100];
    std::cin.getline(args, 100);

    parser.init(args);

    int a = parser.get_argument("first");
    int b = parser.get_argument("second");
    int c = parser.get_argument("third");

    std::cout << a + b * c << std::endl;

    return 0;
}