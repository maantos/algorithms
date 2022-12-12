#include <iostream>
#include <vector>

void merge(std::vector<int> &A, int p, int q, int r) {
    const int n1 = q - p+1;
    const int n2 = r - q;

    std::vector<int> L1 = std::vector<int>(n1+1, 0);
    std::vector<int> L2 = std::vector<int>(n2+1, 0);

        for (int i = 0; i < n1; i++) {
            L1[i] = A[p +i];
        }
        for (int j = 0; j < n2; j++) {
            L2[j] = A[q + j+1];
        }
        L1[n1] = INT32_MAX;
        L2[n2] = INT32_MAX;

        int i =0, j=0;

        for (int k = p; k <= r; k++) {
            if (L1[i] <= L2[j]) {
                A[k] = L1[i];
                i++;
            }
            else {
                A[k] = L2[j];
                j++;
            }
        }   
}
void merge_sort(std::vector<int>&A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2; 
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    std::vector<int> a = { 2,14 ,5 ,8, 7, 6, 12};
    merge_sort(a, 0, a.size()-1);
    for (auto x : a) std::cout << x << std::endl;

}