pair<long long, long long> getMinMax(long long a[], int n) {
    ll maxi=-1;long long mini=1e18;
   for(int i=0;i<n;i++){
       mini=min(mini,a[i]);
       maxi=max(maxi,a[i]);
   }
   return {mini,maxi};
}