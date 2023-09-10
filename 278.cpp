// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int l = 1, r = n;
        unsigned int m;
        
        
        while (l <= r){
            m = (l+r)/2;
            if (isBadVersion(m)){
                if (isBadVersion(m-1) == 0) return m;
                
                r = m-1;
            }
            else l = m+1;
            
        }
        
        return m;
    }
};