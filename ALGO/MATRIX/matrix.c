/* matrix multiplication and exponentiation!
   when using these, remember to cast to long long if necessary
	 (especially when multiplying the resulting matrix later on) */

#define M 2

typedef long long ll;

/* OK UVa 10229 2012-05-26 */
/* OK UVa 12470 2012-06-06 */
/* OK Projet Euler 416 2013-03-10 */
void matrixmulmod(int a[M][M],int b[M][M],int mod,int r[M][M],int n) {
	int x[M][M],i,j,k;
	for(i=0;i<n;i++) for(j=0;j<n;j++) {
		x[i][j]=0;
		for(k=0;k<n;k++) x[i][j]=(x[i][j]+(ll)a[i][k]*b[k][j])%mod;
	}
	for(i=0;i<n;i++) for(j=0;j<n;j++) r[i][j]=x[i][j];
}

/* OK UVa 10229 N<2^31 2012-05-26 */
/* OK UVa 12470 N<=10^16 2012-06-06 */
/* OK Projet Euler 416 N<=10^12 2013-03-10 */
/* remember to change N to long long if needed */
void matrixpowmod(int a[M][M],int N,int mod,int r[M][M],int n) {
	int i,j;
	int b[M][M],x[M][M];
	if(!N) {
		for(i=0;i<n;i++) for(j=0;j<n;j++) r[i][j]=(i==j);
		return;
	}
	for(i=0;i<n;i++) for(j=0;j<n;j++) x[i][j]=(i==j),b[i][j]=a[i][j];
	while(1) {
		if(N&1) matrixmulmod(x,b,mod,x,n);
		N>>=1;
		if(!N) break;
		matrixmulmod(b,b,mod,b,n);
	}
	for(i=0;i<n;i++) for(j=0;j<n;j++) r[i][j]=x[i][j];
}
