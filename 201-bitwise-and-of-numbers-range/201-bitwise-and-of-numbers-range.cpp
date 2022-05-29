class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
           
            
            // when all bits at a idx of numbers btw left and right are 1, then only ans will               have 1 at that idx
            //when both left and right have 1 at a idx, all numbers btw them ll have the same
         int count=0;   
        while(left!=right){
                left>>=1;
                right>>=1;
                count++;
        }
             if(left==0 || right==0) return 0;//in worst case both, left,right will become 0
                                              // means no common fixed bits
            return left<<count;
    }
};