/*Given an array of integers arr, you are initially positioned at the first index of
 the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.



Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the
 last index of the array.

*/


#include<iostream>
#include <vector>
#include <unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
  int n = arr.size();
  if( n==1) return 0;

        unordered_map<int, vector<int>> mapping;


for(int i=0; i<n;i++) {


    mapping[arr[i]].push_back(i);
}
    queue <int> q;
    vector<bool> executed(n,false);

    q.push(0);
    executed[0]= true;

    int steps= 0;

    while(!q.empty()){

        int size = q.size();
        while(size--){

            int  p = q.front();
            q.pop();

            if(p== n-1 )return steps;

            if(p-1>= 0 &&  !executed[p-1] ){
                executed[p-1]= true;
                q.push(p-1);
            }


            if(p+1< n && !executed[p+1]){
                executed [p+1]= true;
                q.push(p+1);
            }

            if(mapping.count(arr[p])){
                for(int l : mapping[arr[p]]) {
                    if (!executed[l]) {
                        executed[l] = true;
                        q.push(l);
                    }
                }
                mapping.erase(arr[p]);
            }

    }
    steps++;

}
return -1;
}
};

int main(){

    Solution obj;

    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    int result = obj.minJumps(arr);
    cout<<result;
    return 0;

}
