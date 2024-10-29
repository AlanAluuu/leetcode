#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n;
	scanf("%d",&n);
	
	long long num[30000];
	int count[1000001] = {0};
	long long cnt1;
	long long max = 0;
	for (cnt1=0;cnt1<n;cnt1++)
	{
		scanf("%lld",&num[cnt1]);
		count[num[cnt1]]++;	
		if (num[cnt1]>max)
		{
			max = num[cnt1];
		}
	}	
	
	int total = 0;
//  	for (cnt1=0;cnt1<=max;cnt1++)
//  	{
//  		if (count[cnt1]>1 && count[cnt1]!=0)	
//  		{	
//  			count[cnt1+1] += count[cnt1] - 1;
//  			total += count[cnt1] - 1;	
//		}
//    }  	
    // 要知道哪些数字已经被使用
    for (cnt1 = 0; cnt1 <= 1000000; cnt1++)
    {
        if (count[cnt1] > 1)  // 如果这个数字出现多于一次
        {
            total += count[cnt1] - 1; // 需要添加的次数
            count[cnt1 + 1] += count[cnt1] - 1; // 将多余的数量加到下一个数字
        }
    }
    
    printf("%d\n", total); 
    
    return 0;
}