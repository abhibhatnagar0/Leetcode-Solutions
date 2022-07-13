class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
            if(left==0 || right==0) return 0;
        //if left right have different bits ...ans=0
        //ie all flipped bits
        if((int)log2(left)!= (int)log2(right)) return 0;
        // 00111001
        // 01000000 (this no will be in btw of my range)..hence ans=0
        // 01000011 
        
        
        int count=0;
            // when all bits at a idx of numbers btw left and right are 1, then only ans will have 1 at that idx
            //when both left and right have 1 at a idx, all numbers btw them ll have the same

        //when nos have same bits 
        while(left!=right){
                left>>=1;
                right>>=1;
                count++;
        }
        //count gives no of flipped bits (from right)
        //left now will have fixed bits possessed by all nos in range
            return left<<count; 
    }
    //while loop will run max of 32 times
};