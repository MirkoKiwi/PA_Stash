#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

class Solution {
public:
    // Function to print the DP table
    void printDPTable(const vector<vector<int>>& dp, const string& str1, const string& str2) {
        cout << "DP Table:" << endl;
        
        // Print header with characters from str2
        cout << "    ";
        cout << "  ";
        for (char c : str2) {
            cout << c << " ";
        }
        cout << endl;
        
        // Print the table with row labels
        for (int i = 0; i <= str1.length(); i++) {
            if (i == 0) {
                cout << "  ";
            } else {
                cout << str1[i-1] << " ";
            }
            
            for (int j = 0; j <= str2.length(); j++) {
                cout << setw(2) << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        // Dynamic programming
        int m = str1.length();
        int n = str2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Fill the dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } 
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // Print the DP table
        printDPTable(dp, str1, str2);
        
        // Construct the shortest common substring by working backwards through the dp table
        string result = "";
        int i = m;
        int j = n;
        while (i > 0 && j > 0) {
            // If current characters are same, add it once
            if (str1[i - 1] == str2[j - 1]) {
                result += str1[i-1];
                i--; 
                j--;
            }
            // If not same, take the direction of larger value
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                result += str1[i - 1];
                i--;
            } 
            else {
                result += str2[j - 1];
                j--;
            }
        }
        
        // Add remaining characters from str1
        while (i > 0) {
            result += str1[i - 1];
            i--;
        }
        
        // Add remaining characters from str2
        while (j > 0) {
            result += str2[j - 1];
            j--;
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    vector<pair<string, string>> testCases = {
        {"abac", "cab"},
        {"aaaaaaaa", "aaaaaaaa"},
        {"abcdef", "xyz"},
        {"brute", "groot"},
        {"AGGTAB", "GXTXAYB"}
    };
    
    for (auto& tc : testCases) {
        cout << "Test Case:" << endl;
        cout << "str1: \"" << tc.first << "\", str2: \"" << tc.second << "\"" << endl;
        
        string result = sol.shortestCommonSupersequence(tc.first, tc.second);
        
        cout << "Shortest Common Supersequence: \"" << result << "\"" << endl;
        cout << "Length: " << result.length() << endl;
        cout << "-------------------------------------------" << endl << endl;
    }
    
    return 0;
}