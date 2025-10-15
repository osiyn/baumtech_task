#include <iostream>
#include <vector>
#include <algorithm>

int min_sum(std::vector<std::vector<int>>& triangle) {
    int n = triangle.size();
    
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            triangle[i][j] += std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    
    return triangle[0][0];
}

int main() {
    std::vector<std::vector<int>> triangle1 = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
    int res1 = min_sum(triangle1);
    std::cout << "Result 1: " << res1 << std::endl;

    std::vector<std::vector<int>> triangle2 = {{-1}, {2,3}, {1,-1,-3}, {4,2,1,3}};
    int res2 = min_sum(triangle2);
    std::cout << "Result 2: " << res2 << std::endl;

    return 0;
}