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





void bubbleSort(vector<int>&nums){
    for(int i=0;i<nums.size()-1;i++){// for 6 elements 5 passes needed
        for(int j=0;j<nums.size()-i-1;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
            }
        }
    }
}





void insertionSort(vector<int>&nums){
    for(int i=0;i<nums.size();i++){
        int j=i;
        while(j>0 and nums[j-1]>nums[j]){
            swap(nums[j],nums[j-1]);
            j--;
        }
    }
}






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
