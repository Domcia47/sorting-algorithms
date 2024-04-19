#include <vector>
#include <iostream>
#include <chrono>

template <class T>
void sort(std::vector<T>& v) {
    
    int v_size = v.size();
    int min;
    for (int i = 0; i < v_size-1; i++) {
        min=i;
        for (int j = i+1; j < v_size; j++){
            if (v[j] < v[min])
                min = j;
        }
        if (min != i){
            std::swap(v[min], v[i]);
        }
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
    std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;
}