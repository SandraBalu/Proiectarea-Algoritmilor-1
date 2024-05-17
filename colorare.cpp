
#include <fstream>
#include <vector>
#define MOD 1000000007

using namespace std;

ifstream fin("colorare.in");
ofstream fout("colorare.out");

// Function to perform fast exponentiation
long long power(long long x, long long n) {
    long long pow = 1;
    if (n == 0) {
        return 1;
    }

    while (n > 0) {
        if (n % 2 == 1) {
            pow *= x;
            pow %= MOD;
        }

        x *= x;
        x %= MOD;
        n/=2;
    }

    return pow;
}


// Function to calculate number of ways to color a sequence based
// on the previous and current sequence types

long long solution(char ch_ant, char ch, long long k) {
    if (ch_ant == 'H' && ch == 'H') {
        return power(3, k )% MOD;
    } else if (ch_ant == 'V' && ch == 'V') {
        return  power(2, k) % MOD;
    } else if (ch_ant == 'H' && ch == 'V') {
        return power (2, k - 1) % MOD;
    } else if (ch_ant == 'V' && ch == 'H') {
        return 2 * power(3, k - 1) % MOD;
    }
}

int main() {
    long long n, k_ant, k, total = 1;
    char ch_ant, ch;

    fin >> n;
    fin>>k>>ch_ant;

    if (ch_ant == 'V') {
        total *= (3 * power(2, k - 1));
        total %= MOD;
    } else {
        total *= (2 * power(3, k));
        total %= MOD;
    }

    for (long long i = 1; i < n; i++) {
        fin>>k>>ch;
        total*=solution(ch_ant, ch, k);
        total %= MOD;
        ch_ant = ch;
    }

    fout<<total % MOD;

    fin.close();
    fout.close();
    return 0;
}
