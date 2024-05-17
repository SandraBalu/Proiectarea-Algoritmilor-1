#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

// Function to calculate the promotional price for two products
double promo2(int a, int b) {
  if (a < b)
    return b + (double)(a / 2.0);

  return a + (double)(b / 2.0);
}

// Function to calculate the promotional price for three products
double promo3(int a, int b, int c) {
  int Min = min(a, min(b, c));
  return (double)(a + b + c - Min);
}

int main() {
  ifstream fin("oferta.in");
  ofstream fout("oferta.out");

  double minCost[2 + 10000];

  int price[2 + 10000];

  int n, k;
  fin >> n >> k;

  for (int i = 1; i <= n; i++)
    fin >> price[i];

  minCost[0] = 0.0;
  minCost[1] = (double)price[1];

  // Calculate the minimum cost for i products
  for (int i = 2; i <= n; i++) {
    minCost[i] = min(minCost[i - 1]
        + (double)price[i], minCost[i - 2] + promo2(price[i], price[i - 1]));

    // If possible, consider the last three products for promo3
    if (i >= 3)
      minCost[i] = min(minCost[i], minCost[i - 3]
      + promo3(price[i], price[i - 1], price[i - 2]));
  }
  fout << fixed << setprecision(1) << minCost[n];
  return 0;
}
