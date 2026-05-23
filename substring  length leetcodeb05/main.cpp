#include <iostream>
#include<string>
#include<unordered_set>

using namespace std;

class solution{
public:
    int  lengthOfLongestSubstring(string s) {
        unordered_set< char> arr;

        int left = 0;
        int count= 0;

        for(int i= 0; i<s.size();i++){
            while(arr.count(s[i])){
                arr.erase(s[left]);
                left++;
            }
            arr.insert(s[i]);
            count = max(count, i-left+1);
    }
return count;
    }

};

int main(){
    solution obj;
    int result = obj.lengthOfLongestSubstring("cbaddhdhffh");

    cout<< result;

    return 0;
}