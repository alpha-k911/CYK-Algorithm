#include <bits/stdc++.h>

using namespace std;

string getString(char x)
{
    return string(1, x);
}

int main() {
    unordered_map<string,vector<string>> mp;
    unordered_multimap<string,string> tmp_map,tmp_map1,tmp_map2;
    int i,j,k,t,l,n,size,x,y,x1,x2,y1,y2;
    vector<string> tmp;
    string s,a,b,c,tmp_string,str;
    a = ".";

    //input start
    cout<<"Input (Provide each transition as provided in example in input.txt):"<<endl;
    cin>>a>>b;
    while(a != "^^^"){
        if(mp.find(b) == mp.end()){
            mp[b] = vector<string>();
            mp[b].push_back(a);
        }else{
            mp[b].push_back(a);
        }
        cin>>a>>b;
    }
    //input end

    //matrix declaration
    s = b;
    l = s.length();
    vector<unordered_multimap<string,string>> graph[l];
    for(i = 0; i < l; i++){
        graph[i] = vector<unordered_multimap<string,string>>(l-i);
    }

    //filling first row
    //1st row of length 1 in pyramid
    string literal = "$";
    for(i = 0; i < l; i++){
        if(mp.find(getString(s[i])) != mp.end()){
            tmp = mp[getString(s[i])];
//            cout<<"Found: "<<s[i]<<tmp.size()<<endl;
            for(j = 0; j < tmp.size(); j++){
                //str is in VLR fromat for DFS traversal
                str = tmp[j]+s[i]+literal;
                graph[0][i].insert({tmp[j],(str)}); // $ for sign of literal
            }
        }
    }

    //filling remaining rows
    //for remaining sized strings
    for(k = 1; k < l; k++){
        for(i = 0; i < l-k; i++){

            //x1,y1,x2,y2 are pointers
            x1 = 0;
            y1 = i;
            x2 = k-1;
            y2 = i + 1;
            while(x2>=0){
                if(graph[x1][y1].size() != 0 && graph[x2][y2].size() != 0){
                    tmp_map1 = graph[x1][y1];
                    for(auto itt1 = tmp_map1.begin(); itt1 != tmp_map1.end(); itt1++){
                        tmp_map2 = graph[x2][y2];
                        for(auto itt2 = tmp_map2.begin(); itt2 != tmp_map2.end(); itt2++){
                            tmp_string = itt1->first + itt2->first;
                            //finding and adding
                            //if found
                            if(mp.find(tmp_string) != mp.end()){
                                tmp = mp[tmp_string];
                                for(j = 0; j < tmp.size(); j++){

                                    //str is in VLR fromat for DFS traversal
                                    //path object defines how the object is formed
                                    str = tmp[j]+itt1->second + itt2->second;
                                    graph[k][i].insert({tmp[j],(str)});
                                }
                            }
                        }
                    }
                }
                //changing pointers accordingly
                x1++;
                x2--;
                y2++;
            }
        }
    }

    //printing filled matrix
    for(i = l-1; i >= 0; i--){
        cout<<graph[i].size()<<endl;
        cout<<"| ";
        for(j = 0; j<l-i; j++){
            cout<<graph[i][j].size()<<" ";
            tmp_map = graph[i][j];
            for(auto itt = tmp_map.begin(); itt != tmp_map.end(); itt++){
                cout<<itt->first<<" ";
            }
            cout<<" | ";
        }
        cout<<endl;
    }
    cout<<"\nNo. Of distinct Parse Trees : "<<graph[l-1][0].size()<<endl;

    //traversal for parse tree
    //in every node of pyramid, each literal is having the data of its path from base in "VLR" format
    cout<<"\nParse Trees : "<<endl;
    i=1;
    for(auto itt = graph[l-1][0].begin(); itt != graph[l-1][0].end(); itt++,i++){
        cout<<i<<": "<<itt->second<<endl;
    }
    return 0;
}