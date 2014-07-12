class Solution {
public:
    
    double powHelper(double x, int n)
    {
        if( n == 0)
            return 1;
        else
        {
            double re = powHelper(x,n/2);
            if( n%2 == 0)
            {
                return re*re;
            }
            else
            {
                return re*re*x;   
            }
        }
    }
    
    double pow(double x, int n) {
        if( n < 0)
        {
            return 1/powHelper(x,-n);
        }
        else
        {
            return powHelper(x,n);
        }
    }
};