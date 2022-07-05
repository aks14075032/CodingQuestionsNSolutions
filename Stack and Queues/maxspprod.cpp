/*
You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:

LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (i>j). If multiple A[j]'s are present in multiple positions, the LeftSpecialValue is the maximum value of j.
RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (j>i). If multiple A[j]'s are present in multiple positions, the RightSpecialValue is the minimum value of j.
Write a program to find the maximum special product of any integer in the array.

NOTE:  As the answer can be large, output your answer modulo 109 + 7.



Problem Constraints
1 <= N <= 105
 
1 <= A[i] <= 109



Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the maximum special product of any integer.



Example Input
Input 1:

 A = [1, 4, 3, 4]
Input 2:

 A = [10, 7, 100]


Example Output
Output 1:

 3
Output 2:

 0


Example Explanation
Explanation 1:

 For A[2] = 3, LeftSpecialValue is 1 and RightSpecialValue is 3.
 So, the ans is 1*3 = 3.
 
Explanation 2:

 There is not any integer having maximum special product > 0. So, the ans is 0.
 https://www.interviewbit.com/problems/maxspprod/

*/
int Solution::maxSpecialProduct(vector<int> &A) {
    int n = A.size();
    stack<pair<int, int> >st; 
    long long int larr[n], rarr[n];
    
    for(int i=0; i<n; i++){
        while(!st.empty() && st.top().first <= A[i]){
            st.pop();
        }
        
        if(st.empty()){
            larr[i]=0;
        }
        else{
            larr[i] = st.top().second;
        }
        st.push({A[i], i});
    }
    
    while(!st.empty())
        st.pop();
        
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && st.top().first <= A[i]){
            st.pop();
        }
        
        if(st.empty()){
            rarr[i]=0;
        }
        else{
            rarr[i] = st.top().second;
        }
        st.push({A[i], i});
    }
    long long int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans, larr[i]*rarr[i]);
    }
    return ans%1000000007;
    
}
