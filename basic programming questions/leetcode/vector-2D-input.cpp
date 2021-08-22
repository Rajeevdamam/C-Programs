#include <iostream>
#include<vector>

using namespace std;

int main() {
    vector<vector<int>> accounts;
    int nums;
    for(int i=0;i<3;i++){
        vector<int> rows;
        for(int j=0;j<2;j++){
            cin>>nums;
            rows.push_back(nums);
        }
        accounts.push_back(rows);
    }
    cout<<accounts.size()<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<accounts[i].size();j++){
            cout<<accounts[i][j]<<" ";
        }
      cout<<"\n";
    }
    
}