#include "GlobalInclude.cpp"
/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:

    string minWindow(string s, string t) 
    {
        // 用來判斷是否已找到一個window substring符合要求，詳細後述。
        int remainCountOfMatch = t.length();

        // 先用hashmap存target字串裡面所有種類字元出現的次數
        unordered_map<char, int> elementMapOfT;
        for (char element : t)    
        {
            elementMapOfT[element] += 1;
        }

        // 準備一個hashmap，用來存放目前的source subString裡面的字元出現的次數
        // 只會記屬於target字元集合的字元
        unordered_map<char, int> elementMapOfResult; 

        // 用Queue來儲存上述那些字元的index，也就是有match到target字元集合的那些字元才會被記下來
        // 這樣Slide Window的時候才會快
        queue<int> matchIndexList;

        // 儲存目前找到的substring之資訊(開頭，結尾，長度)
        int minLength = INT_MAX;
        pair <int, int> resultSubstrIndex = {-1, -1};

        // Doing slide window
        int index = 0;
        while (index < s.length())
        {
            char element = s[index];

            // 一開始先用index從左往右上，有match到的字元就記下來
            if (elementMapOfT[element] > 0)
            {
                // remainCountOfMatch是用來判斷所找到的字串是否符合要求。
                // 因為我們有記目標字元集合當中每個字元出現的次數(elementMapOfT)
                // 也有記目前substring中屬於target字元集合的字元出現的次數(elementMapOfResult)
                // 換言之只要目前還沒有找到足夠的目標字元 (elementMapOfResult[element] < elementMapOfT[element])
                // 那就把remainCountOfMatch-1，表示"還剩下這些數目的字元要找"
                // (elementMapOfResult[element] >= elementMapOfT[element])的情況則表示這個字元找到了夠多次，已經match完了
                // 就不用再-1了
                if (elementMapOfResult[element] < elementMapOfT[element])
                {
                    remainCountOfMatch -= 1;
                }

                elementMapOfResult[element] += 1;

                // 但是只要有Match到就要把這些字元的Index Push進Queue裡面，之後會用到。
                matchIndexList.push(index);
            }
            
            // 找到一組substring的情況
            if (remainCountOfMatch == 0)
            {
                // 取得這個substring的left Index和right Index
                int left = matchIndexList.front();
                int right = matchIndexList.back();
                
                while (left <= right)
                {
                    // 判斷這個substring的長度是否為最短，是就記錄下來
                    int localLength = right - left + 1;
                    if (localLength < minLength)
                    {
                        minLength = localLength;
                        resultSubstrIndex = {left, right};
                    }

                    // 關鍵一步: slide window, 從已知的substring移動left index和right index
                    // 然後用一樣的方式判斷移動後的子字串是否依然符合條件
                    // 符合的話因為是while迴圈就會再做一次判斷
                    // 這裡用Queue的價值就顯示出來了: 因為Queue是FIFO
                    // 所以每次就是取Queue的front -> 判斷完後把Queue pop掉
                    // 如此就可以確保每次拿到的都是match target字元集合且為正確的left index 
                    char leftElement = s[left];
                    elementMapOfResult[leftElement] -= 1;
                    matchIndexList.pop();
                    left = matchIndexList.front();
                    
                    // 判斷子字串是否符合條件。
                    // left index移動到下一個match target字元集合的Index了->
                    // elementMapOfResult[element] 少了1 ->
                    // 如果 elementMapOfResult[element] 因此 < elementMapOfT[element]
                    // (也就是可供match的字元數不夠了)
                    // 那就把remainCountOfMatch加回來，break掉，繼續移動right index做下一次搜尋。
                    if (elementMapOfResult[leftElement] < elementMapOfT[leftElement])
                    {
                        remainCountOfMatch += 1;
                        break;
                    }
                }
            }

            index++;
        }

        if (resultSubstrIndex.first == -1 && resultSubstrIndex.second == -1)
        {
            return "";
        }

        string result = s.substr(resultSubstrIndex.first, minLength);

        return result;
    }
};
// @lc code=end
int main(int argc, char *argv[])
{
    Solution solution;
    string result = solution.minWindow("ADOBECODEBANC", "ACC");
    cout << result;
    return 0;
}

