#include <bits/stdc++.h>

using namespace std;

class pos{
public:
    string s;
    int x;
    int y;
    pos(string str=NULL,int a=0,int b=0):s(str),x(a),y(b){} //constructor
};

string getString(char x)
{
    return string(1, x);
}

void traverse(pos p,vector<unordered_multimap<string,pos>> graph[]){
//    cout<<p.s<<"("<<p.x<<","<<p.y<<") ";
    cout<<p.s<<" ";
    if(p.x == -1 && p.y == -1){
        return;
    }else{
        for(auto it1 = graph[p.x][p.y].begin(); it1 != graph[p.x][p.y].end(); it1++){
            if(it1 -> first == (p.s)){
                pos a,b;
                a = it1->second;
//                if(it1->second.second.x != -1)graph[p.x][p.y].erase(it1);
                traverse(a,graph);
                traverse(b,graph);
                break;
            }
        }
    }
}

int main() {
    unordered_map<string,vector<string>> mp;
    unordered_multimap<string,pos> tmp_map,tmp_map1,tmp_map2;
    int i,j,k,t,l,n,size,x,y,x1,x2,y1,y2;
    vector<string> tmp;
    string s,a,b,c,tmp_string,str;
    a = ".";
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
    s = b;
    l = s.length();
    vector<unordered_multimap<string,pos>> graph[l];
    for(i = 0; i < l; i++){
        graph[i] = vector<unordered_multimap<string,pos>>(l-i);
    }

    //1st row of length 1 in pyramid
    string literal = "$";
    for(i = 0; i < l; i++){
        if(mp.find(getString(s[i])) != mp.end()){
            tmp = mp[getString(s[i])];
//            cout<<"Found: "<<s[i]<<tmp.size()<<endl;
            for(j = 0; j < tmp.size(); j++){
                //str is in VLR fromat for DFS traversal
                str = tmp[j]+s[i]+literal;
                graph[0][i].insert({tmp[j],pos(str,-1,-1)}); // $ for sign of literal
            }
        }
    }

    //for remaining sized strings
    for(k = 1; k < l; k++){
        for(i = 0; i < l-k; i++){
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
//                                cout<<"Found: "<<tmp_string<<tmp.size()<<endl;
                                for(j = 0; j < tmp.size(); j++){
                                    //str is in VLR fromat for DFS traversal
                                    //pos object defines how the object is formed
                                    str = tmp[j]+itt1->second.s + itt2->second.s;
                                    graph[k][i].insert({tmp[j],pos(str,x1,y1)});
                                }
                            }
                        }
                    }
                }
                x1++;
                x2--;
                y2++;
            }
        }
    }

    for(i = l-1; i >= 0; i--){
//        g[i] = unordered_multimap<string,pair<pos,pos>>(i);
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
    cout<<"\nParse Trees : "<<endl;

    //traversal
    //in every node of pyramid, each literal is having the data of its path from base in "VLR" format
    i=1;
    for(auto itt = graph[l-1][0].begin(); itt != graph[l-1][0].end(); itt++,i++){
        cout<<i<<": "<<itt->second.s<<endl;
    }
    return 0;
}