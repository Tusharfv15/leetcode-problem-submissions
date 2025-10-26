class Bank {
public:
    vector<long long>bal;
    Bank(vector<long long>&balance) {
        bal = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        int n = bal.size();
        if(account1 < 1 || account2 < 1 || account2 > n || account1 > n)return false;
        int ind1 = account1 - 1;
        int ind2 = account2 - 1;

        long long bal1 = bal[ind1];
        if(bal1 < money)return false;
        bal[ind2]+=money;
        bal[ind1]-=money;
        return true;

    }
    
    bool deposit(int account, long long money) {
        int n = bal.size();
        if(account < 1 || account > n)return false;
        int ind = account - 1;
        bal[ind]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        int n = bal.size();
        if(account <1 || account > n)return false;

        int ind = account-1;
        if(bal[ind] < money)return false;
        bal[ind]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(bal);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */