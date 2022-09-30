    /* VECTOR STL */
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v {10,5,15};
    for(int &i : v){
        i=10;
    }
    for (auto i = v.begin(); i!=v.end(); i++){
        cout<<*i;
    }
    return 0;
}

//----------------------------------

#include <iostream>
#include <vector>
using namespace std;

void func(vector<int> &v1){
    v1.push_back(1);
    v1.push_back(2);
}
int main() {
    vector<int> v {10,5,15};
    func(v);
    for(int i : v){
        cout<<i<<endl;
    }
    return 0;
}



        /*---RECURSION---*/
    //PRINTING ALL SUBSTRING OF AN ARRAY

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &v){
    for(auto i : v ){
        cout<<i;
    }
    cout<<endl;
}

void func(vector<int> &v, int i, vector<int> &per){
    if(i==v.size()){
        print(per);
        return;
    }
    per.push_back(v.at(i));
    func(v,i+1,per);

    per.pop_back();
    func(v, i+1,per);
}

int main(){
    vector<int> v1 = {3,1,2};
    vector<int> per;
    int i=0;
    func(v1,i,per);
    return 0;
}


//     //PRINTING ALL SUBSTRING OF AN ARRAY WHOSE SUM IS EQUAL TO N , repetation is allowed..
// /* 
//     arr = [2,3,6,7]
//     n = 7
//     res =  [[2,2,3],[7]]
// */

#include<iostream>
#include<vector>

using namespace std;

void allSubSum(int target, vector<int> &arr,  int i , vector<int> &temp){
        //base condition
    if( i == arr.size()){
        if(target == 0){
            for(auto i : temp)
                cout<<i;
            cout<<endl;
        }
        return;
    }
        //logic
    if(arr[i] <= target){
        temp.push_back(arr[i]);
        allSubSum(target-arr[i], arr, i, temp);
        temp.pop_back();
    }
    allSubSum(target, arr, i+1, temp);
}
int main(){
    vector<int> v1 = {2,3,6,7};
    int tSum = 7, i=0;
    vector<int> v2;
    allSubSum(tSum,v1,i,v2);
    return 0;
}


//     //PRINTING ALL SUBSTRING OF AN ARRAY WHOSE SUM IS EQUAL TO N , repetation is allowed..
// /* 
//     arr = [1,2,3,4,6,7]
//     n = 7
//     res =  [[1,2,4],[3,4],[1,6],[7]]
// */

#include<iostream>
#include<vector>
using namespace std;

void subArrSum(int target, vector<int> &arr, vector<int> &allSubArr, int i){
    if(i == arr.size()){
        if(target==0){
            for(auto i : allSubArr){
                cout<<i;
            }
            cout<<endl;
        }
        return;
    }
    if(arr[i]<=target){
        allSubArr.push_back(arr[i]);
        subArrSum(target-arr[i], arr, allSubArr, i+1);
        allSubArr.pop_back();
    }
    subArrSum(target,arr,allSubArr,i+1);
}

int main(){

    vector<int> v1 = {1,2,3,4,6,7};
    int tSum = 7;
    vector<int> res;
    int i = 0;
    subArrSum(tSum, v1, res, i);
    return 0;
}
