
public class Solution {

    Dictionary<char, int> romanDict = new Dictionary<char, int>()
    {
        {'I', 1}, {'V', 5},
        {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000},
        {'O', 0}
    };
        
    public int RomanToInt(string s) 
    {
        char lastRoman = 'O';
        
        int result = 0;
        
        foreach (char roman in s)
        {
            if(romanDict[roman] > romanDict[lastRoman])
            {
                result -= (romanDict[lastRoman]);
                result += (romanDict[roman] - romanDict[lastRoman] );
            }
            else
            {
                result += romanDict[roman] ;
            }
            
            lastRoman = roman;
        }
        
        return result;
    }
}