/*
    LINK: https://leetcode.com/discuss/interview-question/1636493/Amazon-or-OA-or-Max-Length-of-Valid-Server-Cluster

    SIMILAR PROBLEM: https://leetcode.com/problems/maximum-number-of-robots-within-budget/description/

*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// ChargingTimes = BootingPower
// RunningCosts = ProcessingPower
class Solution {
public:
    int maxLengthValidSubArray(vector<int>& processingPower,vector<int>& bootingPower, int maxPower) {
        int ans=0,n=bootingPower.size();
        int i=0;//left pointer
        int cost=0ll;//Store the  sum of running costs among the k robots.
        // Here k is the size of the sliding window, which is j-i+1
        
        int maxCharge=0;
        // A multiset [ in Descending Order] so that the beginning element is the largest element of the window
        multiset<int,greater<int>>ds;
        
        for(int j=0;j<n;j++){
            
            cost+=processingPower[j];//Calculating the sum of the running costs of the sliding window
            ds.insert(bootingPower[j]);//Inserting each element if bootingPower to our multiset
            maxCharge=*(ds.begin());//The maxElement will be the largest charge cost of the window
            int total=maxCharge+((j-i+1)*cost);//The total cost of running the window [ k robots]
            
            while(total>maxPower){//Window is INVALID when total exceeds maxPower
                //We start removing elements from the beginning of the window
                cost-=processingPower[i];
                
                auto x=ds.find(bootingPower[i]);//The element that is to be removed, we are finding it in our multiset
                if(x!=ds.end())
                   ds.erase(x);//Removing that element
                
                maxCharge=*(ds.begin());//Since its a multiset the fisrt element will be the maximum
                
                total=maxCharge+((j-i+1)*cost);//Computing new total
                i++;//Moving the left pointer
            }
            ans=max(ans,j-i+1);//Claculating the size of the window [k]
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> bootingPower = {2, 1, 4, 3};
    vector<int> processingPower = {4, 2, 2, 1};
    int maxPower = 13;

    int result = test.maxLengthValidSubArray(processingPower, bootingPower, maxPower);
    cout << "Maximum Servers: " << result << endl;

    return 0;
}