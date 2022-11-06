// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

void merge(std::vector<int> &A, int p, int q, int r) {
    const int n1 = q - p+1;
    const int n2 = r - q;

    std::vector<int> L1 = std::vector<int>(n1+1, 0);
    std::vector<int> L2 = std::vector<int>(n2+1, 0);

        for (int i = 0; i < n1; i++) {
            L1[i] = A[p +i-1];
        }
        for (int j = 0; j < n2; j++) {
            L2[j] = A[q + j];
        }
        L1[n1] = INT32_MAX;
        L2[n2] = INT32_MAX;

        int i =0, j=0;

        for (int k = p; k < r; k++) {
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
        //std::cout << "-----------------" << std::endl;
        //std::cout << "before merge: " << std::endl;
        //for (auto& x : A) { std::cout << x << " "; }
        merge(A, p, q, r);
        //std::cout << "\n-----------------" << std::endl;
        //std::cout << "after merge: " << std::endl;
        //for (auto& x : A) { std::cout << x << " "; }
        //std::cout << "p: " << p << " q: " << q << " r:" << r  << std::endl;
    }
}

int main()
{
    //std::vector<int> vec = std::vector<int>{8,7,6,5,4,3,2,1};
    //merge_sort(vec, 0, vec.size());
    //std::cout << "After Merge:" << std::endl;
    //for (auto& x : vec) { std::cout << x << " ";}
    std::vector<int> a = { 2,14 ,5 ,8, 7, 6, 12};
    merge_sort(a, 0, a.size());
    for (auto x : a) std::cout << x << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
