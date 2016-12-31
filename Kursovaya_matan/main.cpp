#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

#define zzz system("PAUSE");
#define _2 1<<
#define eps 1e-8
#define uint unsigned int
#define ll long long
#define for0(i, n) for (uint i = 0; i < (n); ++i)
#define for1(i, n) for (uint i = 1; i <=(n); ++i)
#define oo <<
#define ii >>
#define coo cout oo
#define cii cin ii
#define coon coo '\n'
#define nex oo '\n'
#define spa oo ' '
#define sqr(a) ((a)*(a))

#define leftp p += left->p;
#define rightp p += right->p;
#define leftn for(int i = 0; i < left->n_size; ++i) p += left->n[i];
#define rightn for(int i = 0; i < right->n_size; ++i) p += right->n[i];
#define konec return; } else { if(n[i] == '(') ++ls; if(n[i] == ')') ++rs; } ls = rs = 0;


using namespace std;

bool intInString(char* s, int s_size)
{
    if(((s[0] == 'e') && (s_size == 1)) || ((s[0] == 'p') && (s[1] == 'i') && (s_size == 2)))
        return true;
    for(int i = 0; i < s_size; ++i)
        if(!(((s[0] == '-') && (!i)) || ((s[i] <= '9') && (s[i] >= '0'))))
            return false;
    return true;
}

bool PSP(char* s, int s_size)
{
    int ls = 0, rs = 0;
    for(int i = 0; i < s_size; ++i)
    {
        if(ls < rs)
            return false;
        if(s[i] == '(')
            ++ls;
        if(s[i] == ')')
            ++rs;
    }
    return true;
}

class v
{
public:
    char n[100];
    string p;
    int n_size;
    v* left;
    v* right;
    v* dad;
    bool was;
    void kudah(int i, int k)
    {
        char _left[i];
        char _right[n_size - i - k];
        copy(n, n + i, _left);
        copy(n + i + k, n + n_size, _right);
        left = new v(_left, i, this);
        right = new v(_right, n_size - i - k, this);
    }
    v()
    {

    }
    v(char* _n, int _n_size, v* _dad)
    {
        for(int i = 0; i < _n_size; ++i)
            n[i] = _n[i];
        n_size = _n_size;
        p.resize(0);
        dad = _dad;
        was = false;
        p = "";
        if(n[n_size - 1] == '\n')
        {
            --n_size;
        }
        if((PSP(n + 1, n_size - 2)) && (n[0] == '(') && (n[n_size - 1] == ')'))
        {
            for(int i = 1; i < n_size - 1; ++i)
                n[i - 1] = n[i];
            n_size -= 2;
            was = true;
        }
        if(intInString(n, n_size)) // const
        {
            p.resize(1);
            p = "0";
            return;
        }
        if((n[0] == 'x') && (n_size == 1)) // x
        {
            p.resize(1);
            p = "1";
            return;
        }
        int ls = 0, rs = 0;
        for(int i = n_size - 1; i >= 0; --i) // +++++++++++++++
            if((n[i] == '+') && (ls == rs))
            {
                kudah(i, 1);
                p.resize(left->p.size() + 1 + right->p.size());
                p = "";
                leftp
                p += '+';
                rightp
                konec
        for(int i = n_size - 1; i >= 0; --i) // ---------------
            if((n[i] == '-') && (n[i - 1] != '(') && (ls == rs) && (i))
            {
                kudah(i, 1);
                p.resize(left->p.size() + 1 + right->p.size());
                p = "";
                leftp
                p += "-";
                if(right->was)
                    p += "(";
                rightp
                if(right->was)
                    p += ")";
                konec
        for(int i = n_size - 1; i >= 0; --i) // ***************
            if((n[i] == '*') && (n[i + 1] != '*') && (n[i - 1] != '*') && (ls == rs))
            {
                kudah(i, 1);
                p.resize(left->p.size() + 7 + right->n_size + left->n_size + 4 + right->p.size());
                p = "(";
                leftp
                p += ")*(";
                rightn
                p += ")+(";
                leftn
                p += ")*(";
                rightp;
                p += ")";
                konec
        for(int i = n_size - 1; i >= 0; --i) // //////////////
            if((n[i] == '/') && (ls == rs))
            {
                kudah(i, 1);
                p.resize(left->p.size() + 21 + 2 * right->n_size + left->n_size + right->p.size());
                p = "((";
                leftp;
                p += ")*(";
                rightn
                p += ")-(";
                leftn
                p += ")*(";
                rightp
                p += "))/((";
                rightn
                p += ")**2)";
                konec
        for(int i = n_size - 1; i >= 0; --i) // ** ** ** **
            if((n[i] == '*') && (n[i + 1] == '*') && (ls == rs))
            {
                kudah(i, 2);
                p.resize(left->p.size() + 19 + 2 * right->n_size + left->n_size + right->p.size());
                p = "e**(ln(";
                leftn
                p += ")*(";
                rightn
                p += "))*(ln(";
                leftn
                p += ")*(";
                rightp
                p += ")+(";
                rightn
                p += ")*(";
                leftp
                p += ")/(";
                leftn
                p += "))";
                konec
        if((n[0] == 'l') && (n[1] == 'n') && (ls == rs)) // ln ln ln ln
        {
            kudah(0, 2);
            p.resize(right->n_size + 5 + right->p.size());
            p = "(";
            rightp
            p += ")/(";
            rightn
            p += ")";
            return;
        }
        if((n[0] == 's') && (n[1] == 'i') && (ls == rs)) // sin sin sin
        {
            kudah(0, 3);
            p.resize(right->n_size + 10 + right->p.size());
            p = "(";
            rightp
            p += ")*(cos(";
            rightn
            p += "))";
            return;
        }
        if((n[0] == 'c') && (n[1] == 'o') && (ls == rs)) // cos cos cos
        {
            kudah(0, 3);
            p.resize(right->n_size + 13 + right->p.size());
            p = "(-(";
            rightp
            p += "))*(sin(";
            rightn
            p += "))";
            return;
        }
        if((n[0] == 't') && (n[2] == 'n') && (ls == rs)) // tan tan tan
        {
            kudah(0, 3);
            p.resize(right->n_size + 13 + right->p.size());
            p = "(";
            rightp
            p += ")/(cos(";
            rightn
            p += ")**2)";
            return;
        }
        if((n[0] == 'c') && (n[2] == 't') && (ls == rs)) // cot cot cot
        {
            kudah(0, 3);
            p.resize(right->n_size + 16 + right->p.size());
            p = "(-(";
            rightp
            p += "))/(sin(";
            rightn
            p += ")**2)";
            return;
        }
        if((n[0] == 'a') && (n[2] == 'i') && (ls == rs)) // asin asin
        {
            kudah(0, 4);
            p.resize(right->n_size + 10 + right->p.size());
            p = "(";
            rightp
            p += ")/(1-(";
            rightn
            p += ")**2)**(1/2)";
            return;
        }
        if((n[0] == 'a') && (n[2] == 'o') && (ls == rs)) // acos acos
        {
            kudah(0, 4);
            p.resize(right->n_size + 10 + right->p.size());
            p = "(-(";
            rightp
            p += "))/(1-(";
            rightn
            p += ")**2)**(1/2)";
            return;
        }
        if((n[0] == 'a') && (n[1] == 't') && (ls == rs)) // atan atan
        {
            kudah(0, 4);
            p.resize(right->n_size + 10 + right->p.size());
            p = "(";
            rightp
            p += ")/(1+(";
            rightn
            p += ")**2)";
            return;
        }
        if((n[0] == 'a') && (n[3] == 't') && (ls == rs)) // acot acot
        {
            kudah(0, 4);
            p.resize(right->n_size + 12 + right->p.size());
            p = "(-(";
            rightp
            p += "))/(1+(";
            rightn
            p += ")**2)";
            return;
        }
    }
};

int main()
{
    cin.tie();
    ios_base::sync_with_stdio(0);

    freopen("deriv.in", "r", stdin);
    freopen("deriv.out", "w", stdout);
    char s[100];
    int s_size = 0;
    char c;
    while(scanf("%c", &c) > 0)
    {
        if((cin.eof()) || (c == '\n'))
        {
            s[s_size] = c;
            ++s_size;
            v start(s, s_size, NULL);
            coo start.p nex;
            s_size = 0;
        }
        else
            if(c != ' ')
            {
                s[s_size] = c;
                ++s_size;
            }
    }



    return 0;
}
