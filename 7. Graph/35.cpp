/**
 * Hamilton Path
 */

#include <bits/stdc++.h>
using namespace std;

#define V 5

void printSolution(int path[])
{
    printf("Hamilton Cycle is \n");
    for(int i=0;i<V;i++)
        printf("%d ",path[i]);
    printf("%d ", path[0]);
}

bool isSafe(int v, bool graph[V][V], int path[], int pos)
{
    if(graph[path[pos-1]][v] == 0)
        return false;

    for(int i=0;i<pos;i++)
        if(path[i] == v)
            return false;
    return true;
}

bool hamCycleUtil(bool graph[V][V], int path[], int pos)
{
    if(pos == V)
    {
        if(graph[path[pos-1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for(int v=1;v<V;v++){
        if(isSafe(v,graph,path,pos))
        {
            path[pos] = v;
            if(hamCycleUtil(graph,path,pos+1) == true)
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

bool hamCycle(bool graph[V][V])
{
    int *path = new int[V];
    for(int i=0;i<V;i++)
        path[i] = -1;

    //starting from vertex 0
    ////If there is a Hamilton cycle then path can be started from any point
    path[0] = 0;
    if(hamCycleUtil(graph,path,1) == false)
    {
        printf("No hamilton cycle");
        return false;
    }

    printSolution(path);
    return true;
}

int main()
{
    bool graph[V][V] = {
                      {0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };

    hamCycle(graph);
    return 0;
}