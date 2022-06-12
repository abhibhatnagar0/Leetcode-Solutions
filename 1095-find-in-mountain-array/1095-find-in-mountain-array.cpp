/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &MountainArr) {
        int n= MountainArr.length();
        int s=0,e=n-1;
            int peak_index = peakIndexInMountainArray(MountainArr);
            
            int a=bs1(MountainArr,target,0,peak_index);
            int b=bs2(MountainArr,target,peak_index+1,n-1);
            
        if(a!=-1&&b!=-1)
            return min(a,b);
        if(a!=-1)
            return a;
        if(b!=-1)
            return b;
        return -1;
              
    }
        int peakIndexInMountainArray(MountainArray &MountainArr) {
        int n=MountainArr.length();
            int s=0,e=n-1;
            
            while(s<e){
                    int m=s+(e-s)/2;
                    if(MountainArr.get(m)<MountainArr.get(m+1)) s=m+1;
                    else{
                            if(MountainArr.get(m)<MountainArr.get(m)) return m; 
                            else e=m-1;
                    }
            }
            //s==e==m
            return s;     
    }
//FOR CHECKING IN PORTION OF ARRAY THAT IS IN ASCENDING ORDER
int bs1(MountainArray &a,int k,int l,int r){
    int m;
    while(l<=r){
        m=l+(r-l)/2;
        int val=a.get(m);
        if(val==k)
            return m;
        else if(val>k)
            r=m-1;
        else
            l=m+1;
    }
    return -1;
}
//FOR CHECKING IN PORTION OF ARRAY THAT IS IN DESCENDING ORDER
int bs2(MountainArray &a,int k,int l,int r){
    int m;
    while(l<=r){
        m=l+(r-l)/2;
        int val=a.get(m);
        if(val==k)
            return m;
        else if(val>k)
            l=m+1;
        else
            r=m-1;
    }
    return -1;
}
};