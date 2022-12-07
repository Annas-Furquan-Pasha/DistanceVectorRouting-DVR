#include <iostream>
#include <climits>
#include <vector>
#define INF INT_MAX
using namespace std;

//All pair shortest path algorithm(Floyd Warshall) to find shortest distance to every other node.
void Floyd_Warshall(vector<vector<int>> Graph, int mNodes)
{
    for(int i=0; i<mNodes; i++)
    {
        cout << "Distance from Node '"<< i << "' to :" << endl;
        for(int j=0; j< mNodes; j++)
        {
            int tem =j;
            for(int k=0; k<mNodes; k++)
            {
                if(Graph[i][k] != INF && Graph[k][j] != INF && Graph[i][k] + Graph[k][j] < Graph[i][j])
                {
                    Graph[i][j] = Graph[i][k] + Graph[k][j];
                    tem = k;
                }
            }
            cout << "Node '" << j << "' is " << Graph[i][j] << " units through Node " << tem << endl;
        }
        cout << endl;
    }
}

int main()
{
    int mNodes=0;

    cout << "Enter number of nodes : ";
    cin >> mNodes;

    cout << "Enter adjacency matrix : " << endl;
    vector<vector<int>> Graph(mNodes);

    for(int i=0; i< mNodes; i++)
    {
        for(int j=0; j<mNodes; j++)
        {
            int x;  // temperory taking input
            cin >> x;
            if(i != j && x == 0)
                x = INF;
            Graph[i].push_back(x); // updating to original matrix
        }
    }
    cout << endl;

    Floyd_Warshall(Graph, mNodes);
}