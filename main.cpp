#include <bits/stdc++.h>
using namespace std;

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// define infinite
#define INF 0x3f3f3f3f

int E = 20;
map<int, string> Stations = {
    {1, "Sector 51"},
    {2, "Sector 50"},
    {3, "Sector 76"},
    {4, "Sector 101"},
    {5, "Sector 81"},
    {6, "Noida NSEZ"},
    {7, "Sector 83"},
    {8, "Sector 137"},
    {9, "Sector 142"},
    {10, "Sector 143"},
    {11, "Sector 144"},
    {12, "Sector 145"},
    {13, "Sector 146"},
    {14, "Sector 147"},
    {15, "Sector 148"},
    {16, "Knwldg Park II"},
    {17, "Pari Chowk"},
    {18, "Noida Alpha 1"},
    {19, "Noida Delta 1"},
    {20, "GNIDA Office"},
    {21, "Depot Station"}};

void printLine()
{

    for (int i = 0; i < 50; i++)
    {
        cout << '-';
    }
    cout << endl;
}
void printLine1()
{

    for (int i = 0; i < 130; i++)
    {
        cout << '-';
    }
    cout << endl;
}
void Display_Stations()
{
    cout << "\n\n~~~Noida Metro Stations~~~\n\n\n";
    printLine();
    cout << "Station Name\t\t\t\tStation ID" << endl;
    printLine();
    for (auto it : Stations)
    {
        cout << it.second << "\t\t|\t\t" << it.first << endl;
        printLine();
    }
}

class Dijkstra
{
public:
    // To add an edge
    void addEdge(vector<iPair> adj[], int u, int v, int wt)
    {
        adj[u].push_back(make_pair(v, wt));
        adj[v].push_back(make_pair(u, wt));
    }

    vector<int> shortestPath(int V, vector<iPair> adj[], int src)
    {
        // Create a priority queue to store vertices that
        // are being preprocessed.
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        // Create a vector for distances and initialize all
        // distances as infinite (INF)
        vector<int> dist(V, INF);
        // Insert source itself in priority queue and initialize
        // its distance as 0.P>
        pq.push(make_pair(0, src));
        dist[src] = 0;
        /* Looping till priority queue becomes empty (or all
        distances are not finalized) */
        while (!pq.empty())
        {
            // The first vertex in pair is the minimum distance
            // vertex, extract it from priority queue.
            // vertex label is stored in second of pair (it
            // has to be done this way to keep the vertices
            // sorted distance (distance must be first item
            // in pair)
            int u = pq.top().second;
            pq.pop();

            // Get all adjacent of u.
            for (auto x : adj[u])
            {
                // Get vertex label and weight of current
                // adjacent of u.
                int v = x.first;
                int weight = x.second;

                // If there is shorted path to v through u.
                if (dist[v] > dist[u] + weight)
                {
                    // Updating distance of v
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        return dist;
    }
    void Prepare(vector<iPair> adj[])
    { // function to add edges to the graph
        addEdge(adj, 1, 2, 3);
        addEdge(adj, 2, 3, 2.8);
        addEdge(adj, 3, 4, 0.9);
        addEdge(adj, 4, 5, 1.1);
        addEdge(adj, 5, 6, 0.850);
        addEdge(adj, 6, 7, 2.5);
        addEdge(adj, 7, 8, 1.5);
        addEdge(adj, 8, 9, 1.1);
        addEdge(adj, 9, 10, 1);
        addEdge(adj, 10, 11, 1.7);
        addEdge(adj, 11, 12, 0.700);
        addEdge(adj, 12, 13, 0.800);
        addEdge(adj, 13, 14, 0.550);
        addEdge(adj, 14, 15, 0.9);
        addEdge(adj, 15, 16, 0.9);
        addEdge(adj, 16, 17, 1.2);
        addEdge(adj, 17, 18, 2.2);
        addEdge(adj, 18, 19, 2.1);
        addEdge(adj, 19, 20, 3);
        addEdge(adj, 20, 21, 2.2);
    }
};
int menu()
{
    int V = 21;
    vector<iPair> adj[V];
    Dijkstra d;

    d.Prepare(adj);

    while (true)
    {
        cout << "\n\n------ WELCOME TO NOIDA METRO MANAGEMENT ------" << endl;
        cout << "1. Display Map" << endl;
        cout << "2. Minimum Distance between 2 Stations" << endl;
        cout << "3. Minimum fare required to travel between 2 stations" << endl;
        cout << "4. Exit\n" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Display_Stations();
            break;
        }
        case 2:
        {
            int src, dest;
            cout << "Enter your station number: ";
            cin >> src;
            cout << "Enter destination station number: ";
            cin >> dest;

            vector<int> res = d.shortestPath(V, adj, src);
            cout << "Distance between " << src << " and " << dest << " is: " << res[dest] <<" Km"<< endl;
            break;
        }
        case 3:
        {
            int src, dest;
            cout << "Enter your station number: ";
            cin >> src;
            cout << "Enter destination station number: ";
            cin >> dest;
            int fixed_cost = 8; // we take fixed cost of travelling 1 km as $8
            vector<int> res = d.shortestPath(V, adj, src);
            cout << "Minimum fare to travel between " << src << " and " << dest << " is: " << res[dest] * fixed_cost <<" Rupees"<< endl;
            break;
        }
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main()
{
    menu();
    return 0;
}
