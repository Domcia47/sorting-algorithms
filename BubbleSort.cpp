#include <vector>
#include <iostream>
#include <chrono>
int comparisons=0; 

template <class T>
void sort(std::vector<T>& v) {
    bool issorted=true;
    int v_size = v.size();
    for (int i = 0; i < v_size - 1; ++i) {
        for (int j = 0; j < v_size - i - 1; ++j) {
            
            comparisons++;
            if (v[j] > v[j + 1]) {
                issorted=false;
                std::swap(v[j], v[j + 1]);
            }
        }
        if(issorted){
            break;
        }
        issorted=true;
    }
}

int main(){
    std::vector<int> v;
    int val;
    
    while (std::cin >> val) 
        v.push_back(val);
    
    auto start = std::chrono::high_resolution_clock::now();
    sort(v);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    for(const auto& i : v)
        std::cout << i << std::endl;
    
    //std::cout<< "Liczba operacji wyniosła: "<< comparisons <<std::endl;

    std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;

}
