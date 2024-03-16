#include <bits/stdc++.h>
using namespace std;
class BigInt
{
public: 
    BigInt()
    {
        _data.push_back(0);
    }
    
    BigInt(long long x)
    {
        while(x)
        {
            _data.push_back(x % _base);
            x /= _base;
        }
        
        if(_data.empty()) _data.push_back(0);
    }
    
    BigInt(unsigned long long x)
    {
        while(x)
        {
            _data.push_back(x % _base);
            x /= _base;
        }
        
        if(_data.empty()) _data.push_back(0);
    }
 
    BigInt(int x) : BigInt((long long)x) {}
    BigInt(unsigned int x) : BigInt((unsigned long long)x) {}
    BigInt(short x) : BigInt((long long)x) {}
    BigInt(unsigned short x) : BigInt((unsigned long long)x) {}
    BigInt(char x) : BigInt((long long)x) {}
    BigInt(unsigned char x) : BigInt((unsigned long long)x) {}
 
    BigInt(std::string &s)
    {
        for(int i = (int)s.size(); i > 0; i -= 9)
            if(i < 9)
                _data.push_back(atoi(s.substr(0, i).data()));
            else
                _data.push_back(atoi(s.substr(i - 9, 9).data()));
        
        while(_data.size() > 1 && _data.back() == 0)
            _data.pop_back();
    }
    
    BigInt(const char *s)  
    {
        std::string d = s;
        
        for(int i = (int)d.size(); i > 0; i -= 9)
            if(i < 9)
                _data.push_back(atoi(d.substr(0, i).data()));
            else
                _data.push_back(atoi(d.substr(i - 9, 9).data()));
        
        while(_data.size() > 1 && _data.back() == 0)
            _data.pop_back();
    }
    
    BigInt(const BigInt& b)
    {
        _data.resize(b._data.size());
        std::copy(b._data.begin(), b._data.end(), _data.begin());
    }
    
    void ToString(char *s) const
    {
        sprintf(s, "%d", _data.empty() ? 0 : _data.back());
        for(int i = (int)_data.size() - 2; i >= 0; i--)
            sprintf(s, "%s%09d", s, _data[i]);
    }
    
    std::string ToString() const
    {
        char *buff = (char*)malloc(20);
        
        sprintf(buff, "%d", _data.empty() ? 0 : _data.back());
        std::string res = buff;
        
        for(int i = (int)_data.size() - 2; i >= 0; i--)
        {
            sprintf(buff, "%09d", _data[i]);
            res += buff;
        }
            
        free(buff);
        
        return res;
    }
    
    friend const BigInt operator+(BigInt &i);
    friend const BigInt& operator++(BigInt &i);
    friend const BigInt& operator--(BigInt &i);
    friend const BigInt operator++(BigInt &i, int);
    friend const BigInt operator--(BigInt &i, int);
    
    friend const BigInt operator+(const BigInt &c, const BigInt &b);
    friend const BigInt operator-(const BigInt &c, const BigInt &b);
    friend const BigInt operator*(const BigInt &a, const BigInt &b);
    friend const BigInt operator/(const BigInt &a, const BigInt &b);
    friend const BigInt operator%(const BigInt &a, const BigInt &b);
    
    friend BigInt& operator+=(BigInt &a, const BigInt &b);
    friend BigInt& operator-=(BigInt &a, const BigInt &b);
    friend BigInt& operator*=(BigInt &a, const BigInt &b);
    friend BigInt& operator/=(BigInt &a, const BigInt &b);
    friend BigInt& operator%=(BigInt &a, const BigInt &b);
    
    friend bool operator==(const BigInt &a, const BigInt &b);
    friend bool operator<=(const BigInt &a, const BigInt &b);
    friend bool operator>=(const BigInt &a, const BigInt &b);
    friend bool operator<(const BigInt &a, const BigInt &b);
    friend bool operator>(const BigInt &a, const BigInt &b);
    friend bool operator!=(const BigInt &a, const BigInt &b);
    
    /*operator long long() const
    {
        long long res = 0, b = 1;
        for(size_t i = 0; i < _data.size(); i++)
        {
            res += b * _data[i];
            b *= BigInt::_base;
        }
        return res;
    }
    
    operator unsigned long long()
    {
        unsigned long long res = 0, b = 1;
        for(size_t i = 0; i < _data.size(); i++)
        {
            res += b * _data[i];
            b *= BigInt::_base;
        }
        return res;
    }*/
    
    friend std::istream& operator>>(std::istream &is, BigInt &i)
    {
        std::string s;
        is >> s;
        i = BigInt(s);
        return is;
    }
    
    friend std::ostream& operator<<(std::ostream &os, const BigInt &i)
    {
        os << i.ToString();
        return os;
    }
    
private:
    static const int _base = 1000 * 1000 * 1000;
    std::vector<int> _data;
    
    int _cmp(const BigInt &a, const BigInt &b) const //a - b, 1 if a > b
    {
        if(a._data.size() > b._data.size()) return 1;
        if(a._data.size() < b._data.size()) return -1;
        
        for(int i = (int)a._data.size() - 1; i >= 0; i--)
        {
            if(a._data[i] > b._data[i]) return 1;
            if(a._data[i] < b._data[i]) return -1;
        }
        
        return 0;
    }
    
    BigInt _div_short(const BigInt &c, int b, int &mod) const
    {
        mod = 0;
        BigInt a = c;
        for(int i = (int)a._data.size() - 1; i >= 0; i--) 
        {
            long long cur = a._data[i] + mod * 1ll * BigInt::_base;
            a._data[i] = int(cur / b);
            mod = int(cur % b);
        }
        
        while (a._data.size() > 1 && a._data.back() == 0)
            a._data.pop_back();
        
        return a;
    }
    
    bool _is_zero() const
    {
        return _data.size() == 1 && _data[0] == 0;
    }
};
 
const BigInt operator+(const BigInt &i) 
{
    return BigInt(i);
}
 
const BigInt& operator++(BigInt &i) 
{
    int j = 0;
    i._data[0]++;
    
    while(i._data[j] >= BigInt::_base)
    {
        if(j == (int)i._data.size() - 1) i._data.push_back(1); else i._data[j + 1]++;
        i._data[j] -= BigInt::_base;
        j++;
    }
    
    return i;
}
 
const BigInt operator++(BigInt &i, int) 
{
    BigInt old = BigInt(i);
    
    int j = 0;
    i._data[0]++;
    
    while(i._data[j] >= BigInt::_base)
    {
        if(j == (int)i._data.size() - 1) i._data.push_back(1); else i._data[j + 1]++;
        i._data[j] -= BigInt::_base;
        j++;
    }
    
    return old;
}
 
//TODO: Optimize
const BigInt& operator--(BigInt &i) 
{
    if(!i._is_zero()) i = i - 1;
    return i;
}
 
//TODO: Optimize
const BigInt operator--(BigInt &i, int) 
{
    BigInt old = BigInt(i);
    if(!i._is_zero()) i = i - 1;
    return old;
}
 
const BigInt operator+(const BigInt &c, const BigInt &b)
{
    BigInt a = c;
        
    int carry = 0;
    for(size_t i = 0; i < std::max(a._data.size(), b._data.size()) || carry; i++) 
    {
        if(i == a._data.size()) a._data.push_back(0);
        a._data[i] += carry + (i < b._data.size() ? b._data[i] : 0);
        carry = a._data[i] >= BigInt::_base;
        if(carry) a._data[i] -= BigInt::_base;
    }   
        
    return a;       
}
 
const BigInt operator-(const BigInt &c, const BigInt &b)
{
    if(c < b) throw std::invalid_argument("a - b, a must b greater or equal zero");
    BigInt a = c;
        
    int carry = 0;
    for(size_t i = 0; i < b._data.size() || carry; i++) 
    {
        a._data[i] -= carry + (i < b._data.size() ? b._data[i] : 0);
        carry = a._data[i] < 0;
        if(carry) a._data[i] += BigInt::_base;
    }
        
    while(a._data.size() > 1 && a._data.back() == 0)
        a._data.pop_back();
            
    return a;       
}
 
const BigInt operator*(const BigInt &a, const BigInt &b)
{
    BigInt c;
    c._data.resize(a._data.size() + b._data.size());
        
    for(size_t i = 0; i < a._data.size(); i++)
        for(int j = 0, carry = 0; j < (int)b._data.size() || carry; j++) 
        {
            long long cur = c._data[i + j] + a._data[i] * 1ll * (j < (int)b._data.size() ? b._data[j] : 0) + carry;
            c._data[i + j] = int(cur % BigInt::_base);
            carry = int(cur / BigInt::_base);
        }
            
    while(c._data.size() > 1 && c._data.back() == 0)
        c._data.pop_back();
            
    return c;       
}
 
//TODO: Division by zero
const BigInt operator/(const BigInt &a, const BigInt &b)
{
    if(b._is_zero()) throw std::invalid_argument("division by zero");
    BigInt l = 0, r = a + 1, m;
    int t;
    while(r - l > 1)
    {
        //m = (r + l) / 2;
        m = a._div_short(r + l, 2, t);
        if(b * m <= a) l = m; else r = m;
    }
    return l;
}
 
//TODO: Division by zero
const BigInt operator%(const BigInt &a, const BigInt &b)
{
    if(b._is_zero()) throw std::invalid_argument("division by zero");
    BigInt l = 0, r = a + 1, m;
    int t;
    while(r - l > 1)
    {
        //m = (r + l) / 2;
        m = a._div_short(r + l, 2, t);
        if(b * m <= a) l = m; else r = m;
    }
    return a - b * l;
}
 
BigInt& operator+=(BigInt &a, const BigInt &b)
{
    int carry = 0;
    for(size_t i = 0; i < std::max(a._data.size(), b._data.size()) || carry; i++) 
    {
        if(i == a._data.size()) a._data.push_back(0);
        a._data[i] += carry + (i < b._data.size() ? b._data[i] : 0);
        carry = a._data[i] >= BigInt::_base;
        if(carry) a._data[i] -= BigInt::_base;
    }   
    return a;
}
 
BigInt& operator-=(BigInt &a, const BigInt &b)
{
    int carry = 0;
    for(size_t i = 0; i < b._data.size() || carry; i++) 
    {
        a._data[i] -= carry + (i < b._data.size() ? b._data[i] : 0);
        carry = a._data[i] < 0;
        if(carry) a._data[i] += BigInt::_base;
    }
        
    while(a._data.size() > 1 && a._data.back() == 0)
        a._data.pop_back();
            
    return a;
}
 
BigInt& operator*=(BigInt &a, const BigInt &b)
{
    a = a * b;
    return a;
}
 
BigInt& operator/=(BigInt &a, const BigInt &b)
{
    a = a / b;
    return a;
}
 
BigInt& operator%=(BigInt &a, const BigInt &b)
{
    a = a % b;
    return a;
}
 
bool operator==(const BigInt& a, const BigInt& b)
{
    return a._cmp(a, b) == 0;
}
 
bool operator<=(const BigInt& a, const BigInt& b)
{
    return a._cmp(a, b) <= 0;
}
 
bool operator>=(const BigInt& a, const BigInt& b)
{
    return a._cmp(a, b) >= 0;
}
 
bool operator<(const BigInt& a, const BigInt& b)
{
    return a._cmp(a, b) < 0;
}
 
bool operator>(const BigInt& a, const BigInt& b)
{
    return a._cmp(a, b) > 0;
}
 
bool operator!=(const BigInt& a, const BigInt& b)
{
    return a._cmp(a, b) != 0;
}
 
BigInt binpow (BigInt a, BigInt n) 
{
  if (n == 0) 
  return 1; 
  if (n % 2 == 1) 
  return binpow (a, n-1) * a; 
   else {
     BigInt b = binpow (a, n/2);
     return b * b;
  }
}
 
BigInt gcd (BigInt a, BigInt b) {
 if (b == 0)
  return a;
 else
  return gcd (b, a % b);
}
BigInt sum(BigInt a)
{
    BigInt o;
    while (a!=-1)
    {
        o+=a;
        a--;
    }
    return o;
}
#define FORN(i,n) for (int i=0;i<n;i++)
#define ll long long
#define pb push_back
 
BigInt pows(BigInt x,BigInt y)
{
    BigInt q=1;
    for(BigInt i=0;i<y;i++)
    q*=x;
    return q;
}
BigInt abss(BigInt x)
{
    if(x<0)
    x-=x;
    return x;
}
ll simple(ll int n) {
    for ( ll int i = 2; i * i <= n; i++ ) {
        if ( n % i == 0 ) {
            return 0;
        }
    }
    return 1;
}
ll result(ll int n) {
    for ( ll int i = 2; i <= n; i++ ) {
        if ( simple(i) && n % i == 0 ) {
            return i;
        }
    }
    return 0;
}
 
bool pal(string s)
{
    for(int i=0;i<s.size()/2+1;i++)
    {
        if(s[i]!=s[s.size()-1-i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,k,t;
    cin>>t;
    while (t!=0)
    {
        cin>>n>>k;
        string s;
        int w=0;
        for (int i=0;i<n;i++)
        {
            s+='a'+w;
            w++;
            if (w==k)
            w=0;
        }
        cout<<s<<endl;
        t--;
    }
return 0;
}
