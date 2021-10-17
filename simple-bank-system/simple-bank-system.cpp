class Bank {
private:
    int validN;
    unordered_map<int, long long int> m;
public:
    Bank(vector<long long>& balance) {
     
        validN = balance.size();
        int i = 1;
        for(long long int &val: balance)
        {
            m[i] = val;    
            i++;
        }
        
    }
    
    bool transfer(int account1, int account2, long long money) {
        
        // cout << "validN" << validN << endl;
        
        if(account1 <= 0 || account2 <= 0)
        {
            return false;   
        }
        if(account1 > validN || account2 > validN)
        {
            return false;
        }
        
        if(money > m[account1])
        {
            return false;
        }
        
        m[account1] -= money;
        m[account2] += money;
        
        return true;
    }
    
    bool deposit(int account, long long money) {
        
        if(account <= 0 || account > validN)
        {
            return false;
        }
        
        m[account] += money;
        return true;
        
        
    }
    
    bool withdraw(int account, long long money) {
        
        if(account <= 0 || account > validN)
        {
            return false;
        }
        
        if(money < 0)
        {
            return false;
        }
        
        if(m[account] < money)
        {
            return false;
        }
        
        m[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */