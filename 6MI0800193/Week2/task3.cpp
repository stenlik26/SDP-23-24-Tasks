#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

bool is_prime(int x)
{
    for (size_t i = 2; i <= x / 2; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

void generate_primes(int n, vector<int>& primes)
{
    int current_prime = 2;
    while (primes.size() < n)
    {
        if (is_prime(current_prime))
            primes.push_back(current_prime);

        current_prime++;
    }
}

void give_plates_from_stack(stack<int>& B)
{
    while (!B.empty())
    {
        cout << B.top() << " ";
        B.pop();
    }
    
}

void clear_stack(stack<int>& A)
{
    while (!A.empty())
        A.pop();
}

int main()
{
    int plates, iterations;

    vector<int> primes;

    cin >> plates;
    cin >> iterations;

    stack<int> plate_nums;
    stack<int> A;
    stack<int> B;

    for (size_t i = 0; i < plates; i++)
    {
        int pl;
        cin >> pl;
        plate_nums.push(pl);
    }

    generate_primes(iterations, primes);

    for (size_t i = 0; i < iterations; i++)
    {
        while (!plate_nums.empty())
        {
            if (plate_nums.top() % primes[i] == 0)
                B.push(plate_nums.top());
            else
                A.push(plate_nums.top());

            plate_nums.pop();
        }

        give_plates_from_stack(B);
        plate_nums = A;

        if (i == iterations - 1)
            give_plates_from_stack(A);
        else
            clear_stack(A);

    }
    cout << endl;

}
