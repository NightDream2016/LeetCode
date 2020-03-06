#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
    public:
    bool checkValidIpNum(string *s)
    {
	    bool result = true;

        if (s->length() <= 0 || s->length() > 3)
        {
            return false;
        }

        if (s->at(0) == '0' && s->length() > 1)
        {
            result = false;
        }

        if (stoi(*s) > 255 || stoi(*s) < 0)
        {
            result = false;
        }

        return result;
    }

    vector<string> ipAddressResult(string s, int currentIpNumIndex)
    {
        vector<string> solutions;

        if (currentIpNumIndex >= 3)
        {
            if (checkValidIpNum(&s))
            {
                solutions.push_back(s);
            }
        }
        else
        {
            for (int i = 1; i <= min(3, (int)s.length()); i++)
            {
                string firstSubStr = s.substr(0, i);

                if (checkValidIpNum(&firstSubStr))
                {
                    if (s.length() - i > 0)
                    {
                        string secondSubStr = s.substr(i, s.length() - i);
                        vector<string> nextIndexSolutions = ipAddressResult(secondSubStr, currentIpNumIndex + 1);

                        for (string &nextIndexSolution : nextIndexSolutions)
                        {
                            string newSolution = firstSubStr + "." + nextIndexSolution;
                            solutions.push_back(newSolution);
                        }
                    }
                }
            }
        }

	    return solutions;
    }

    vector<string> restoreIpAddresses(string s) { return ipAddressResult(s, 0); }
};

int main(int argc, char *argv[])
{
    Solution solution;

    vector<string> solutionResult = solution.restoreIpAddresses("010010");

    for (string result : solutionResult)
    {
	    std::cout << result << std::endl;
    }
    return 0;
}