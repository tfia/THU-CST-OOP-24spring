#include <iostream>
#include <string>
#include "Fraction.h"
#include "calculate.h"

int main(){
    int n;
    std::cin >> n;
    for (int i=0;i<n;++i){
        char expressionType;
        int x, y, z;
        std::string dataType;

        std::cin >> expressionType >> x >> y >> z >> dataType;
        if (dataType == "int"){
            std::cout << calculate<int>(expressionType, x, y, z) << std::endl;
        }
        else if (dataType == "fraction"){
            std::cout << calculate<Fraction>(expressionType, x, y, z) << std::endl;
        }
    }
    return 0;
}