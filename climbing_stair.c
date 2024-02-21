int climbStairs(int n) {
    int stair[50];
    stair[0]=0;
    stair[1]=1;
    stair[2]=2;
    for(int i=3;i<=n;i++)
    {
        stair[i]=stair[i-1]+stair[i-2];
    }
    return stair[n];

}
