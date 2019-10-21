#include <bits/stdc++.h>

using namespace std;

class pos{
public:
    char s;
    int x;
    int y;
    pos(char str=NULL,int a=0,int b=0):s(str),x(a),y(b){} //constructor
};

string getString(char x)
{
    return string(1, x);
}

void traverse(pos p,vector<unordered_multimap<string,pair<pos,pos>>> graph[]){
//    cout<<p.s<<"("<<p.x<<","<<p.y<<") ";
    cout<<p.s<<" ";
    if(p.x == -1 && p.y == -1){
        return;
    }else{
        for(auto it1 = graph[p.x][p.y].begin(); it1 != graph[p.x][p.y].end(); it1++){
            if(it1 -> first == getString(p.s)){
                pos a,b;
                a = it1->second.first;
                b = it1->second.second;
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
    unordered_multimap<string,pair<pos,pos>> tmp_map,tmp_map1,tmp_map2;
    int i,j,k,t,l,n,size,x,y,x1,x2,y1,y2;
    vector<string> tmp;
    string s,a,b,c,tmp_string;
    a = ".";
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
    vector<unordered_multimap<string,pair<pos,pos>>> graph[l],tmp_graph[l];
    for(i = 0; i < l; i++){
        graph[i] = vector<unordered_multimap<string,pair<pos,pos>>>(l-i);
    }
    //1st row
    for(i = 0; i < l; i++){
        cout<<">>>>>>>>>>>>>>>>>>>>>>>>>Length: "<<1<<endl;
        if(mp.find(getString(s[i])) != mp.end()){
            tmp = mp[getString(s[i])];
            cout<<"Found: "<<s[i]<<tmp.size()<<endl;
            for(j = 0; j < tmp.size(); j++){
                graph[0][i].insert({tmp[j],{pos(s[i],-1,-1),pos('$',-1,-1)}}); // $ for sign of literal
            }
        }else{
            cout<<"Not found: "<<s[i]<<endl;
//            cout<<getString(s[i])<<endl;
        }
    }
    //2nd row
    /*for(i = 0; i < l - 1; i++){
        cout<<">>>>>>>>>>>>>>>>>>>>>>>>>Length: "<<2<<endl;
        x = i;
        y = i + 1;
        if(graph[0][x].size() != 0 && graph[0][y].size() != 0){
            tmp_map1 = graph[0][x];
            for(auto itt1 = tmp_map1.begin(); itt1 != tmp_map1.end(); itt1++){
                tmp_map2 = graph[0][y];
                for(auto itt2 = tmp_map2.begin(); itt2 != tmp_map2.end(); itt2++){
                    tmp_string = itt1->first + itt2->first;

                    //finding and adding
                    if(mp.find(tmp_string) != mp.end()){
                        tmp = mp[tmp_string];
                        cout<<"Found: "<<tmp_string<<tmp.size()<<endl;
                        for(j = 0; j < tmp.size(); j++){
                            graph[1][i].insert({tmp[j],{pos(itt1->first[0],0,i),pos(itt2->first[0],0,i+1)}});
                        }
                    }else{
                        cout<<"Not found: "<<tmp_string<<endl;
//                        cout<<tmp_string<<endl;
                    }
                }
            }
        }
    }*/

    //for remaining sized strings
    for(k = 1; k < l; k++){
        cout<<">>>>>>>>>>>>>>>>>>>>>>>>>Length: "<<k+1<<endl;
        for(i = 0; i < l-k; i++){
            cout<<">>>>>>>>>>>>>>>>>>>>>>>>>Col: "<<i+1<<endl;
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
                            if(mp.find(tmp_string) != mp.end()){
                                tmp = mp[tmp_string];
                                cout<<"Found: "<<tmp_string<<tmp.size()<<endl;
                                for(j = 0; j < tmp.size(); j++){
                                    graph[k][i].insert({tmp[j],{pos(itt1->first[0],x1,y1),pos(itt2->first[0],x2,y2)}});
                                }
                            }else{
                                cout<<"Not found: "<<tmp_string<<endl;
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
    cout<<"\nFinal : "<<graph[l-1][0].size()<<endl;

    for(j = 0; j<1; j++){
        cout<<graph[l-1][j].size()<<" ";
        tmp_map = graph[l-1][j];
        for(auto itt = tmp_map.begin(); itt != tmp_map.end(); itt++){
            cout<<itt->first<<" ( ";
            cout<<itt->second.first.s<<" , "<<itt->second.first.x<<" , "<<itt->second.first.y<<" )"<<" & ( "<<itt->second.second.s<<" , "<<itt->second.second.x<<" , "<<itt->second.second.y<<" )";
            cout<<endl;
        }
    }
    pos tmp_pos;
    for(j = 0; j<1; j++){
        for(auto itt = graph[l-1][j].begin(); itt != graph[l-1][j].end(); itt++){
            queue<pos> q;
            cout<<itt->first<<" ";
//            graph[l-1][j].erase(itt);
            traverse(itt->second.first,graph);
            traverse(itt->second.second,graph);
            /*q.push(itt->second.first);//pushing left entity
            q.push(itt->second.second);//pushing right entity
            while(q.size() != 0){
                tmp_pos = q.front();
                q.pop();
                cout<<tmp_pos.s<<" ";
                if(tmp_pos.x != -1 && tmp_pos.y != -1){
                    for(auto it1 = graph[tmp_pos.x][tmp_pos.y].begin(); it1 != graph[tmp_pos.x][tmp_pos.y].end(); it1++){
                        if(it1 -> first == getString(tmp_pos.s)){
                            q.push(it1->second.first);//pushing left entity
                            q.push(it1->second.second);//pushing right entity
//                            graph[tmp_pos.x][tmp_pos.y].erase(it1);
                            break;
                        }
                    }
                }
            }*/

            cout<<endl;
        }
    }
    cout<<"llllllll:"<<endl;
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
    return 0;
}