#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>

class RandomizedSet {
private:
    std::vector<int> elements;
    std::unordered_map<int, size_t> indices;

public:
    bool insert(int val) {
        if (indices.find(val) != indices.end()) {
            return false; // Element already exists
        }
        
        elements.push_back(val);
        indices[val] = elements.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        auto it = indices.find(val);
        if (it == indices.end()) {
            return false; // Element doesn't exist
        }
        
        size_t index = it->second;
        indices[elements.back()] = index; // Update index for last element
        elements[index] = elements.back(); // Replace current element with last element
        elements.pop_back(); // Remove last element
        indices.erase(it); // Erase entry from map
        return true;
    }
    
    int getRandom() {
        if (elements.empty()) {
            throw std::out_of_range("Set is empty");
        }
        
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, elements.size() - 1);
        
        return elements[dis(gen)];
    }
};

int main() {
    RandomizedSet randomizedSet;
    randomizedSet.insert(1);
    randomizedSet.insert(2);
    randomizedSet.insert(3);
    randomizedSet.insert(4);

    std::cout << "Random element: " << randomizedSet.getRandom() << std::endl;

    randomizedSet.remove(2);
    std::cout << "Random element after removal: " << randomizedSet.getRandom() << std::endl;

    return 0;
}
