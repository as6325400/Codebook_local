//x^y % p
ll func(ll x,ll y,ll p){
	ll res = 1;
	while(y != 0){
		if(y%2==1){
			res *= x;
			res %=p;
		}
		x *= x;
		y /= 2;// 5^8 => (5^2)^4
		x %= p;//((5^2) % 7)^4
	}
	return res;
}