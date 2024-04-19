#include <iostream>
#include <ctime>

int main(int argc, const char *argv[]){
    int n, max, random;
    std::string arg = argv[1];
    std::string arg2 = argv[2];
    n = std::stoi(arg);
    max = std::stoi(arg2);

    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (int i=0;i<n;i++){
        random = rand()%max + 1;
        std::cout<<random<<std::endl;
    }

}