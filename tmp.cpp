#include <bits/stdc++.h>

using namespace std;
int main() {

    multimap<string,string> m;
//    m["aa"] = "k";
    m.insert({"a","k"});
    m.insert({"a","k"});
    cout<<m.size();

    return 0;
}