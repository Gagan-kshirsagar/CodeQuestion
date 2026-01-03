int numOfWays(int n) {
    long long aba = 6, abc = 6;
    long long mod = 1e9 + 7;

    for(int i = 0; i < n; i++){
        long long next_aba = (3 * aba + 2 * abc) % mod;
        long long next_abc = (2* aba + 2 * abc) % mod;
        aba = next_aba;
        abc = next_abc;
    }

    return (aba + abc) % mod;

}