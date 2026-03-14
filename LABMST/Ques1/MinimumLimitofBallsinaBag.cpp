class Solution{
public:
	int minimumSize(vector<int>&a,int b){
		int low=1,high=0;
		for(int e:a){
			high=max(high,e);
		}
		int f=high;
		while(low<=high){
			int mid=low+(high-low)/2;
			long long h=0;
			for(int e:a){
				h+=(e-1)/mid;
			}
			if(h<=b){
				f=mid;
				high=mid-1;
			}
			else{
				low=mid+1;
			}
		}
		return f;
	}
};