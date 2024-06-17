#include<iostream>
#include<vector>
using namespace std;

//get the minimum and swap with index
void selectionSort(vector<int>&nums){
    for(int i=0;i<nums.size()-1;i++){
        int mini=i;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]<nums[mini]){
                mini=j;
            }
        }
        swap(nums[i],nums[mini]);
    }
}

//Time complexity O(n^2) all cases

// example:
// [5,3,1,4,2] i=0 mini=0
// after running inner loop mini will store index of minimum element i.e. mini=2
// then swap nums[mini] and nums[i]
// After 1st iteration
// [1,3,5,4,2] 
    
// now i=1 and mini=1;
// after inner loop mini=4
// swap arr[i] and arr[mini]
// [1,2,5,4,3]

// now i=2 and mini=2;
// after inner loop mini=4;
// swap arr[i] and arr[mini]
// [1,2,3,4,5]

// then i=3 and mini=3;
// after inner loop mini=3;
// no change;

// now i=4 and mini=4;
// after inner loop mini=4
// no change;





void bubbleSort(vector<int>&nums){
    for(int i=0;i<nums.size()-1;i++){// for 6 elements 5 passes needed
        for(int j=0;j<nums.size()-i-1;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
            }
        }
    }
}

//Time complexity O(n) O(n^2) O(n^2)





void insertionSort(vector<int>&nums){
    for(int i=0;i<nums.size();i++){
        int j=i;
        while(j>0 and nums[j-1]>nums[j]){
            swap(nums[j],nums[j-1]);
            j--;
        }
    }
}

//Time complexity O(n) O(n^2) O(n^2)





void merge(vector<int>&nums,int low,int mid,int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid and right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        nums[i]=temp[i-low];
    }
}

void mergeSort(vector<int>&nums,int low,int high){
    if(low>=high){
        return;
    }
    int mid=(low+high)/2;
    mergeSort(nums,low,mid);
    mergeSort(nums,mid+1,high);
    merge(nums,low,mid,high);
}

//Time complexity O(nlogn) O(nlogn) O(nlogn)



//take the pivot and place everything smaller to its left and everything larger to its right. After this it means that single element is at its correct position.
//Now you have to sort the left and right to that element.
// Eg. [4,6,2,5,7,9,1,3]
//here correct positon of 4 should be at index 3;
// [1,3,2,4,7,9,5,6]
//now see 4 is the partition and then sort left and right of 4

int partition(vector<int>&nums,int low,int high){
    int i=low,j=high;
    int pivot=nums[low];
    while(i<j){
        while(nums[i]<=pivot and i<=high-1){
            i++;
        }
        while(nums[j]>pivot and j>=low+1){
            j--;
        }
        if(i<j){
            swap(nums[i],nums[j]);
        }
    }
    swap(nums[low],nums[j]);
    return j;
}

void quickSort(vector<int>&nums,int low,int high){
    if(low<high){
        int pindex=partition(nums,low,high);
        quickSort(nums,low,pindex-1);
        quickSort(nums,pindex+1,high);
    }
}

//Time complexity O(nlogn) O(nlogn) O(n^2)



int main() {
    int n;
    cin>>n;
    vector<int>nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    // selectionSort(nums);
    // bubbleSort(nums);
    // insertionSort(nums);
    // mergeSort(nums,0,n-1);
    quickSort(nums,0,nums.size()-1);
    for(auto it:nums){
        cout<<it<<" ";
    }
    return 0;
}
