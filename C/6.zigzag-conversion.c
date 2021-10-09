/*
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (28.11%)
 * Total Accepted:    225.6K
 * Total Submissions: 802.5K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * P Y A I H R N 
 * A P L S I I G
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I      N
 * A   L S    I G
 * Y A   H R
 * P     I
 * 
 */
char* convert(char* s, int numRows) {

    if (numRows <= 1)
    {
        return s;
    }

    int length = 0;
    while (s[length] != '\0')
    {
        length++;
    }

    char *result = (char *)malloc(sizeof(char) * (length + 1));
    int indexOfResult = 0;

    int indexOfString = 0;
    int lastIndexOfString = 0;

    int currentRow = 0; // 目前所在的Row
    int moveDirection = 0; // 0->往下 1->往上

    while (indexOfResult < length && currentRow < numRows)
    {
        result[indexOfResult] = s[indexOfString];

        lastIndexOfString = indexOfString;
        if (moveDirection == 0)
        {
            // 往下走到同列下一個
            indexOfString = indexOfString + (numRows - (currentRow + 1)) * 2;
        }
        else
        {
            // 往上走到同列下一個
            indexOfString = indexOfString + currentRow * 2;
        }

        if (indexOfString >= length)
        {
            currentRow++;
            indexOfString = currentRow;
            moveDirection = 0;
        }
        else
        {
            moveDirection = moveDirection ? 0 : 1;
        }

        if (indexOfString != lastIndexOfString) // 在第一列和最後一列的時候變方向會動不了，因此這時indexOfResult也不能動
        {
            indexOfResult++;     
        }        
        
    }

    result[length] = '\0';
    return result;

}


// int main(int argc, char ** argv)
// {

//     char *result1 = convert("PAYPALISHIRING", 14);
 

//     printf("%s", result1);

//     return 0;
// }


