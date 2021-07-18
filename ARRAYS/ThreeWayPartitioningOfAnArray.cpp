//Practice link : https://practice.geeksforgeeks.org/problems/three-way-partitioning/1#
//Video Solution : https://www.youtube.com/watch?v=3D7Sn733hII

class Solution
{
public:
    //Function to partition the array around the range such
    //that array is divided into three parts.
    void threeWayPartition(vector<int> &array, int a, int b)
    {
        int l = 0, r = array.size() - 1;
        for (int i = 0; i <= r; i++)
        {
            if (array[i] < a)
            {
                swap(array[i], array[l]);
                l++;
            }
            else if (array[i] > b)
            {
                swap(array[i], array[r]);
                r--;
                i--;
            }
        }
    }
};

/*
TC:O(N)
SC:O(1)
*/