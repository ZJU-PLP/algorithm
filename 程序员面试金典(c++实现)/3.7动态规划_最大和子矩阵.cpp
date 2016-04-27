#include<iostream>
#include<vector>
using namespace std;
/*
将从第i行到第j行的每一行中相同列的加起来，可以得到一个一维数组如下：
     (ai1+……+aj1, ai2+……+aj2, ……,ain+……+ajn)
     由此我们可以看出最后所求的就是此一维数组的最大子段和问题
*/
class SubMatrix {
public:
    int sumOfSubMatrix(vector<vector<int> > mat, int n) {
        // write code here
        int value[200]={0};
        int maxv=0;
        for(int i=0;i<n;i++)      //起点行
        {
            for(int j=0;j<n;j++)  //清空记录值数组
            {
                value[j]=0;
            }
            for(int j=i;j<n;j++)  //从起始行往下一次累加
            {
                int sum=0;
                for(int k=0;k<n;k++)  //遍历每行（包含合并行）的每一列
                {
                    value[k]+=mat[j][k];
                }
                sum = MaxSum(value,n);
                if(sum>maxv)
                {
                    maxv=sum;
                }
            }
        }
        return maxv;
    }
     
	int MaxSum(int vec[], int n)
	{
		int maxv=0;
		int val=0;
		for(int i=0;i<n;i++)
		{
			if(val>0)
			{
				val+=vec[i];
			}
			else
			{
				val=vec[i];
			}
 
			if(val>maxv)
			{
				maxv=val;
			}
		}
		return maxv;
	}
};
