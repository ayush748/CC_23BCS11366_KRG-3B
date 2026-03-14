class Solution{
public:
	int maxSum(vector<int>&a,int b){
		long long c=1000000007;
		vector<int>d(32,0);
		for(int e:a){
			for(int f=0;f<32;f++){
				if((e&(1<<f))!=0){
					d[f]++;
				}
			}
		}
		long long g=0;
		for(int h=0;h<b;h++){
			long long i=0;
			for(int f=0;f<32;f++){
				if(d[f]>0){
					i|=(1LL<<f);
					d[f]--;
				}
			}
			g=(g+(i*i)%c)%c;
		}
		return (int)g;
	}
};