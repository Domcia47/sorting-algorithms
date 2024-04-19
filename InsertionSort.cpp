#include <vector>
#include <iostream>
#include <chrono>

template <class T>
void sort(std::vector<T>& v) {
    int v_size = v.size(),j;
    T curr;
    for (int i = 1; i < v_size; i++) {
        curr = v[i];
        j = i - 1;
 
        // Move elements of v[0..i-1],
        // that are greater than key, 
        // to one position ahead of their
        // current position
        while (j >= 0 && v[j] > curr) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = curr;
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