#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<bitset>
#include<stack>
#include<utility>
#include<iomanip>
#include<vector>
#include<math.h>
#include<string>
#include<stdio.h>
#include<limits>
using namespace std;
typedef long long ll;
#define MAXN 100005

// Smallest prime factor
long long spf[MAXN];
// Sieve of eratosthenes
// for computing primes
void sieve()
{
	long long i, j;
	spf[1] = 1;
	for (i = 2; i < MAXN; i++)
		spf[i] = i;
	// Loop for markig the factors
	// of prime number as non-prime
	for (i = 2; i < MAXN; i++) {
		if (spf[i] == i) {
			for (j = i * 2;
				j < MAXN; j += i) {
				if (spf[j] == j)
					spf[j] = i;
			}
		}
	}
}
// Function to factorize the
// number N long longo its prime factors
vector<pair<long long, long long> > getFact(long long x)
{
	// Prime factors along with powers
	vector<pair<long long, long long> > factors;
	// Loop while the X is not
	// equal to 1
	while (x != 1) {
		// Smallest prime
		// factor of x
		long long z = spf[x];
		long long cnt = 0;
		// Count power of this
		// prime factor in x
		while (x % z == 0)
			cnt++, x /= z;
		factors.push_back(
			make_pair(z, cnt));
	}
	return factors;
}
// Function to count the pairs
long long pairsWithKth(long long a[], long long n, long long k)
{
	// Precomputation
	// for factorisation
	sieve();
	long long answer = 0;
	// Data structure for storing
	// list L for each element along
	// with frequency of occurence
	map<vector<pair<long long, long long> >, long long>	count_of_L;
	// Loop to iterate over the
	// elements of the array
	for (long long i = 0; i < n; i++) {
		// Factorise each element
		vector<pair<long long, long long> >
			factors = getFact(a[i]);
		sort(factors.begin(), factors.end());
		vector<pair<long long, long long> > L;
		// Loop to iterate over the
		// factors of the element
		for (auto it : factors) {
			if (it.second % k == 0)
				continue;
			L.push_back(
				make_pair(
					it.first,
					it.second % k));
		}
		vector<pair<long long, long long> > Lx;
		// Loop to find the required prime
		// factors for each element of array
		for (auto it : L) {
			// Represents how much remainder
			// power needs to be added to
			// this primes power so as to make
			// it a multiple of k
			Lx.push_back(
				make_pair(
					it.first,
					(k - it.second + k) % k));
		}
		// Add occurences of
		// Lx till now to answer
		answer += count_of_L[Lx];
		// Increment the counter for L
		count_of_L[L]++;
	}
	return answer;
}
// Driver Code
long long a[MAXN];
int main()
{
	long long n;
	long long k;

	cin >> n >> k;
	long long a[n];
	for (long long i = 0; i < n; i++)cin >> a[i];
	cout << pairsWithKth(a, n, k);
	return 0;
}