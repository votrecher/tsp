#include<stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;






int main()
{
    
    
    int N;
    cin >> N;
    vector<int> cross(N);
    vector<int> ygrek(N);
    for (int i = 0; i < N; i++) {
        int w, v;
        cin >> v >> w;
        cross[i] = v;
        ygrek[i] = w;
    }

    double **graph = new double* [N];
    for (int i = 0; i < N; i++)
    {
        graph[i] = new double[N];
    }
    

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            graph[i][j] = sqrt((cross[i] - cross[j]) * (cross[i] - cross[j]) + (ygrek[i] - ygrek[j]) * (ygrek[i] - ygrek[j]));
        }
    }


    int s = 0;
    vector<int> vertex;
    for (int i = 0; i < N; i++)
        if (i != s)
            vertex.push_back(i);


    double min_path = DBL_MAX;
    do {


        double current_pathweight = 0;


        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];


        min_path = min(min_path, current_pathweight);

    } while (next_permutation(vertex.begin(), vertex.end()));


    cout << min_path;

    
    for (int i = 0; i < N; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;
    return 0;
}