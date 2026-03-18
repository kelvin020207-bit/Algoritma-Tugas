#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

int main() {
    int n, m, x;

    std::cout << "Masukkan jumlah elemen himpunan A: ";
    std::cin >> n;
    std::vector<int> A(n);
    std::cout << "Masukkan elemen A:\n";
    for (int i = 0; i < n; ++i) std::cin >> A[i];

    std::cout << "Masukkan jumlah elemen himpunan B: ";
    std::cin >> m;
    std::vector<int> B(m);
    std::cout << "Masukkan elemen B:\n";
    for (int i = 0; i < m; ++i) std::cin >> B[i];

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    std::vector<int> intersection;
    std::set_intersection(
        A.begin(), A.end(),
        B.begin(), B.end(),
        std::back_inserter(intersection)
    );

    std::cout << "A ∩ B = ";
    for (int v : intersection) std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}
