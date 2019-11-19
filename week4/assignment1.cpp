#include <iostream>

using namespace std;

static const int mod = 1091;
static const int gen = 983;
static const int student_id = 119; // 학번 마지막 3자리를 적으세요

int f(int g)
{
    int plus;
    cout << "Your first value is " << g << "\n"
         << endl;
    cout << "plus input: ";
    cin >> plus;
    do
    {
        g = (g + 17) % mod;
        if (plus > 0)
            --plus;
        else if (plus < 0)
            ++plus;
    } while (plus);
    cout << g << endl;
    for (int i = 0; i <= plus; ++i)
    {
        g = (g + 31) % mod;
    }
    cout << g << endl;

    if (g == student_id)
    {
        g = f(student_id);
    }
    else
    {
        g = (g + 1) % mod;
    }

    if (g == 0)
        g = 1090;

    cout << "Current value is " << g << "\n"
         << endl;
    cout << "Input mult : ";

    int mult;
    cin >> mult;
    for (int i = 0; i < mult; ++i)
    {
        g = (g * gen) % mod;
    }
    return g;
}

int main()
{
    int result = f(gen);
    if (result == student_id)
    {
        cout << "Get Your Studnet ID " << result << " !!" << endl;
    }
    else
    {
        cout << "FAIL.. Get ID is " << result << endl;
    }
    cout << endl;
}
