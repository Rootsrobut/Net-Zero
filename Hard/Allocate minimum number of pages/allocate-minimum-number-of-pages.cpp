//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isvalid(int A[], int N, int M,int mid){
        int sum=0;
        int student=1;
        for(int i=0;i<N;i++){
            sum=sum+A[i];
            if(sum>mid){
                student++;
                sum=A[i];
            }
            if(student>M){
                return false;
            }
        }
        return true;
        
    }
    int findPages(int A[], int N, int M) 
    {
        if(N<M){
            return -1;
        }
        int max=0;
        int sum=0;
        for(int i=0;i<N;i++){
            if(max<A[i]){
                max=A[i];
            }
        }
        for(int i=0;i<N;i++){
            sum=sum+A[i];
        }
        int s=max;
        int e=sum;
        int result=-1;
        while(s<=e){
             int mid=s+(e-s)/2;
             if(isvalid(A,N,M,mid)==true){
                 result=mid;
                 e=mid-1;
             }
             else{
                 s=mid+1;
             }
        }
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends