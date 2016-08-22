#include <iostream>
#include <complex>

int main() {
    //[](input_paramter_declaration)->returned_type {body_of_the_lambda_expression}(parameters)
    int result = []() -> int {return 4;}();
    std::cout<<result<<std::endl;
    
    int r = [](int input) -> int {return 2 * input;} (10);
    std::cout<<r<<std::endl;


    auto func = [](auto input) {return input * input; };
    std::cout<< func(10)<<std::endl;
    
return 0;
}
