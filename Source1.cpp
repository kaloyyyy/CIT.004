#include <iostream>
#include <string>

using namespace std;
int main()
{
    string raptor_prompt_variable_zzyz;
    int num;

    num = 0;
    raptor_prompt_variable_zzyz = "enter";
    cout << raptor_prompt_variable_zzyz << endl;
    cin >> num;
    if (num % 2 == 1)
    {
        cout << "odd" << endl;
    }
    else
    {
        cout << "even" << endl;
    }

    return 0;
}
