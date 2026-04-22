#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

//max of 1 mill
int maxNumber = 1000000;

//define non primes/primes
vector<int> classOfEratosthenes(int limit)
{
    //find non primes
    vector<bool> prime(limit + 1, true);
    int p = 2;
    prime[0] = prime[1] = false;
    for(int p = 2; p*p <= maxNumber; ++p)
    {
        if(prime[p])
        {
            for(int i = p*p; i <= maxNumber; i += p)
            {
                prime[i] = false;
            }
        }
    }
    //find primes
    vector<int> primeNumbers;
    for(int p = 2; p <= maxNumber; ++p)
    {
        if(prime[p])
        {
            primeNumbers.push_back(p);
        }
    }
    //export primes
    return primeNumbers;
}

//check for circularity
bool circularPrime(int n, const unordered_set<int>& primesSet)
{
    string s = to_string(n);
    int nRolls = s.length();
    for(int i = 0; i < nRolls; ++i)
    {
        std::rotate(s.begin(), s.begin() + 1, s.end());
        int newN = stoi(s);

        if(primesSet.find(newN) == primesSet.end())
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> primes = classOfEratosthenes(maxNumber);
    unordered_set<int> primeSet(primes.begin(), primes.end());
    int res = 0;
    for(int n : primes)
    {
        if(circularPrime(n, primeSet))
        {
            ++res;
            cout << "n= " << n << " , res= " << res << endl;
        }
    }
    cout << "DONE" << endl;
    return 0;
}