#include <bits/stdc++.h>

using namespace std;
int main() {

    multimap<string,string> m;
//    m["aa"] = "k";
    m.insert({"a","k"});
    m.insert({"a","k"});
    cout<<m.size();
//    cout<<m["a"];

    char a = 'b';
    string p = "S A S A B A Y X B B A a $ a $ X B b $ X B b $ b $ b $ a $ a $ a $ B A X B a $ X B a $ a $ a $ a $ a $ a $ a $ a $ a $ b $ b $ a $ a $ a $ b $ a $ a $ a $ b $ ";
    string q = "S A S A B A Y X B B A a $ a $ X B b $f X B b $ b $ b $ a $ a $ a $ B A X B a $ X B a $ a $ a $ a $ a $ a $ a $ a $ a $ b $ b $ a $ a $ a $ b $ a $ a $ a $ b $ ";
    if(p==q)
    cout<<"Yes";
    cout<<to_string(a);
    return 0;
}