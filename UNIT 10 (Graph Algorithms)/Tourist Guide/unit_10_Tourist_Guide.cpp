//Tourist Guide

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> components;
vector<vector<int>> paths;
vector<bool> reached;

void FormComponent(int node, int currentComponent)
{
    components[node] = currentComponent;
    
    for (int i = 0; i < paths[node].size(); ++i)
    {
        if (components[paths[node][i]] == -1)
            FormComponent(paths[node][i], currentComponent);
    }
}

void Search(int current)
{
    reached[current] = true;
    
    for (int i = 0; i < paths[current].size(); ++i)
    {
        if (!reached[paths[current][i]])
            Search(paths[current][i]);
    }
}

int main()
{
    int t = 1; //t stands for the city map number
    string temp, other, sep = "";
    while (cin >> n, n)
    {
        cout << sep;
        sep = "\n";
        
        map<string, int> m;
        vector<string> order(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            m[temp] = i;
            order[i] = temp;
        }
        
        int R;  //number of city
        cin >> R;
        
        paths.assign(n, vector<int>());
        
        while (R--)
        {
            cin >> temp >> other;
            int f = m[temp], s = m[other];
            paths[f].push_back(s);
            paths[s].push_back(f);
        }
        
        components.assign(n, -1);
        int numComponents = 0;
        for (int i = 0; i < n; ++i)
        {
            if (components[i] == -1)
                FormComponent(i, numComponents++);
        }
        
        vector<string> special;
        reached.resize(n);
        
        for (int i = 0; i < n; ++i)
        {
            if (paths[i].size() == 0)
                continue;
            
            int currentComponent = components[i];
            
            for (int j = 0; j < n; ++j)
                reached[j] = false;
            reached[i] = true;
            Search(paths[i][0]);
            
            for (int j = 0; j < n; ++j)
                if (!reached[j] && components[j] == currentComponent)
                {
                    special.push_back(order[i]);
                    break;
                }
        }
        
        sort(special.begin(), special.end());
        cout << "City map #" << t++ << ": " << special.size() << " camera(s) found\n";
        //t stands for the city map number
        //special.size() stands for the total number of cameras
        
        for (int i = 0; i < special.size(); ++i){
            cout << special[i] << '\n';
        }
    }
}

/*
6
sugarloaf
maracana
copacabana
ipanema
corcovado
lapa
7
ipanema copacabana
copacabana sugarloaf
ipanema sugarloaf
maracana lapa
sugarloaf maracana
corcovado sugarloaf
lapa corcovado
5
guanabarabay
downtown
botanicgarden
colombo
sambodromo
4
guanabarabay sambodromo
downtown sambodromo
sambodromo botanicgarden
colombo sambodromo
0
*/