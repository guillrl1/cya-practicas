void SSP(const vector<int> X) {
  SSP(n+1)x(S+1);
  for(int j = 0; j <= S; j++)
    SSP[0][j] = false;
  for(int i = 0; i <= n; i++) 
    SSP[i][0] = true;
}