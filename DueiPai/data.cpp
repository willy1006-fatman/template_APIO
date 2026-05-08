#include <chrono>
#include<bits/stdc++.h>
using namespace std;
#define IOS cin.tie(nullptr)->sync_with_stdio(0),cin.exceptions(cin.failbit);
#define lb(x) (x)&-(x)
#define all(x) (x).begin(),(x).end()
#define ll long long

uint64_t timeSinceEpochMillisec() {
	using namespace std::chrono;
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

using namespace std;

constexpr int maxN = 2,maxM = 100,maxC = 100;

int main(){
	mt19937 rng(timeSinceEpochMillisec());
	int n = 2,m = rng()%5+1,K = rng()%maxM+1;
	cout<<n<<' '<<m<<' '<<K<<"\n";
	for(int i = 0;i<n;i++)for(int j = 0;j<m;j++)
		cout<<rng()%(K+1)<<" \n"[j==m-1];
}