#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CombinationLock
{
    vector<int> combination;
    bool check_comb()
    {
        for (int i = 0; i < combination.size(); i++)
            if (std::to_string(combination[i])[0] != status[i])
                return false;
        return true;
    }
public:
    string status;

    CombinationLock(const vector<int>& combination) : combination(combination), status("LOCKED") {

    }

    void enter_digit(int digit)
    {
        string num = std::to_string(digit);
        if (status == "LOCKED")
            status = num;
        else
            status += num;
        if (combination.size() == status.size())
        {
            if (check_comb())
                status = "OPEN";
            else
                status = "LOCKED";
        }
    }
};


int main()
{
    CombinationLock c1({ 1, 2, 3 });
    c1.enter_digit(1);
    c1.enter_digit(2);
    c1.enter_digit(3);
}