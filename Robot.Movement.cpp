#include<iostream> 
#include<vector> 
#include<algorithm> 

using namespace std; 

class Solution{
public: 
    int sumDistance(vector<int>& nums, string s, int d) {
      const int MOD = 1e9+7; 
      int n = nums.size(); 
      vector<long long> final_pos(n); 
      for(int i=0; i<n; ++i){
        if(s[i]=='R') final_pos[i] = nums[i]+d; 
        else final_pos[i]= nums[i]-d; 
      }
      sort(final_pos.begin(), final_pos.end()); 
      long long total_sum =0; 
      long long prefix_sum =0; 
      for(int i=0; i<n; ++i){
        total_sum = (total_sum + i*final_pos[i]-prefix_sum)%MOD; 
        prefix_sum =(prefix_sum + final_pos[i])%MOD;  
        
      }
      return (total_sum+MOD)%MOD; 
      
    }
};
int main(){
  vector<int> nums = {-2,0,2};
  string s = "RLL"; 
  int d = 3; 
  Solution sol; 
  cout << sol.sumDistance(nums, s, d) <<endl; 
  return 0; 
}
