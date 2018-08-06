/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (24.86%)
 * Total Accepted:    532.8K
 * Total Submissions: 2.1M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 * 
 */

int lengthOfLongestSubstring(char *s)
{
    //搜尋表，記錄每種ASCII字元「上次出現時的位置」(預設為-1表示未出現過)
    short lastIndexOfChar[128];
    memset(lastIndexOfChar, -1, sizeof(short) * 128);

    //這裡的原始碼簡化很多，採用Window方式
    //(看起來是一個術語，表示一個有頭尾的子字串)對字串進行搜索。
    //Start是開始，End是結束。
    int currentSubstrStart = 0;
    int currentSubstrEnd = 0;

    // 紀錄目前為止最大長度
    int maxLength = 0;

    // 從座標0開始(0,0)(0,1)(0,2)這樣掃
    while (s[currentSubstrEnd] != '\0')
    {
        // 取得每次Window的結尾字元。
        char currentChar = s[currentSubstrEnd];
        
        // 目前Window的End字元「上次出現的位置」大於或等於Start座標
        // 範例：abca, 上次a出現的位置為0，目前結尾座標為3，而字元為a
        // 判定出現重複字串！！
        if (lastIndexOfChar[currentChar] >= currentSubstrStart)
        {
            // 目前Window的長度去掉頭尾 = 不重複的子字串長度
            // 範例：abca，Window為(0,3)，則子字串為abc，長度為3
            // 可以想成：字串的實際長度是尾-頭+1，但因為有一個字元(字串結尾)重複了
            // 所以要扣掉1，所以就剛好是尾-頭
            int norepeatStrLength = currentSubstrEnd - currentSubstrStart;

            // 紀錄長度最大值
            if (norepeatStrLength > maxLength)
            {
                maxLength = norepeatStrLength;
            }

            // 下一個Window的位置，這裡最關鍵。
            // 以字串abcdefd為例，重複的字元為d，位置為(3,6)
            // 那麼下一個Window只要從e開始－－也就是
            // 「目前Window的End字元上次出現的位置加一」 (lastIndexOfChar[currentChar]) 即可！！
            //
            // 示意圖
            // abcdefd
            // |-----| 遇到重複的Window
            //     |-| 下一個Window開始前的狀態
            // 這是為什麼？
            // 因為對於任何一個已經有重複字元的字串而言
            // 任何包含它的字串一定會有重複字元
            // 而此Window座標在所有以lastIndexOfChar[currentChar]座標值之前為開頭的子字串
            // 要嘛包含它，要嘛比我們目前找到的子字串短。
            // 所 以 都 不 用 考 慮
            //
            // 或者換個角度思考：當出現重複字元的時候
            //       a   b
            // xxxxxxoxxxoxxxxxx
            // 假設o跟o是重複字元
            // 這時任何包含它的子字串都不會是答案
            // 但是所有 [字串頭，b] 的子字串要嘛不是答案就是比[字串頭, b-1]  還小
            // 所以只要找 [a+1, 字串尾] 的子字串即可。

            currentSubstrStart = lastIndexOfChar[currentChar] + 1;
        }

        lastIndexOfChar[currentChar] = currentSubstrEnd;
        currentSubstrEnd ++;
       
    }

    int norepeatStrLength = currentSubstrEnd - currentSubstrStart;

    if (norepeatStrLength > maxLength)
    {
        maxLength = norepeatStrLength;
    }

    return maxLength;
}

int main(int argc, char ** argv)
{

    int result1 = lengthOfLongestSubstring("ohvhjdml");
    int result2 = lengthOfLongestSubstring("wwwwwwwwwww");
    int result3 = lengthOfLongestSubstring("wwwwwwwwwwwabc");
    int result4 = lengthOfLongestSubstring("abcwwwwwwwwwww");
    int result5 = lengthOfLongestSubstring("abcefghijk");
    int result6 = lengthOfLongestSubstring("abcabcabc");
    int result7 = lengthOfLongestSubstring("anviaj");
    int result8 = lengthOfLongestSubstring("pwwkew");
    int result9 = lengthOfLongestSubstring(" ");
    int result10 = lengthOfLongestSubstring("abcb");

    printf("%d %d %d %d %d %d %d %d %d %d", result1, result2, result3, result4, result5, result6, result7, result8, result9, result10);

    return 0;
}
