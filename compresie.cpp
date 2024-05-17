#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void writeToFile(int result);

int maxIdenticalSize(const vector<int>& a, const vector<int>& b) {
    int n = a.size();
    int m = b.size();

    // Calculate the sum of elements in each array
    int sum_a = 0, sum_b = 0;
    for (int i = 0; i < n; ++i) {
        sum_a += a[i];
    }
    for (int i = 0; i < m; ++i) {
        sum_b += b[i];
    }

    // If the sums are not equal, arrays cannot become identical
    if (sum_a != sum_b) {
        return -1;
    }

    int len = 0, i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            // Found matching elements, move to the next pair
            len++;
            i++;
            j++;
        } else {
            // Try to find a sequence of adjacent elements
			// that sum to the same value
            int sum1 = a[i], sum2 = b[j];
            while (sum1 != sum2) {
                if (sum1 < sum2) {
                    sum1 += a[++i];
                } else {
                    sum2 += b[++j];
                }
            }
            // Found a sequence, move to the next pair
            len++;
            i++;
            j++;
        }
    }

    return len;
}

int main() {
    ifstream fin("compresie.in");
    ofstream fout("compresie.out");

    int n, m;
    fin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    fin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        fin >> b[i];
    }
    fin.close();

    // Calculate the maximum identical size
    int result = maxIdenticalSize(a, b);

    fout << result << "\n";
    fout.close();

    return 0;
}


