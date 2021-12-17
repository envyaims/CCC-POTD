#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif
using namespace std;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c,d; cin>>a>>b>>c>>d;
	auto good = [&](int x, int y){
		return x >= a && x <= b && y >= c && y <= d;
	};
	int ans = 0;
	for(int xv = 0; xv < 500; xv++){
		for(int yv = 0; yv < 500; yv++){
			int curx = 0, cury = 0, xvol = xv, yvol = yv;
			int topy = 0;
			for(int ops = 0; ops < 500; ops++){
				curx += xvol;
				cury += yvol;
				topy = max(topy,cury);
				if(xvol > 0){
					xvol = max(0,xvol-1);
				}
				else xvol = min(xvol+1,0);
				yvol--;
				if(good(curx,cury)){
					ans = max(ans,topy);
					break;
				}
			}
		}
	}
	printf("%d",ans);
	
	
}
