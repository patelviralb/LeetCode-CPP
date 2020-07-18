#include <iostream>
#include <string>
#include <map>
#include <cassert>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int stringLength = s.length();
        int maxLength = 0;
        int currentLength = 0;
        int lastElementForLength = stringLength - 1;
        map<char,int> characters;
        
        for(int i = (stringLength - 1) ; i >= 0 ; --i) {
            char currentCharacter = s.at(i);
            currentLength += 1;
            if(characters.find(currentCharacter) != characters.end()) {
                if(lastElementForLength >= characters.at(currentCharacter)) {
                    currentLength = characters.at(currentCharacter) - i;
                    lastElementForLength = characters.at(currentCharacter) -1;
                }
                characters.erase(currentCharacter);
            }
            characters.insert(pair<char, int>(currentCharacter, i));
            if(currentLength > maxLength) {
                maxLength = currentLength;
            }
        }
        return maxLength;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}