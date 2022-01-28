#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

//int fcfs(vector<vector<int>> vect,int n) {
//    int total = 0;
//    int sum = 0;
//    for (int i = 0; i < n; i++)
//    {
//        total += vect[i][1];
//        cout <<"total "<< total <<" ";
//        sum = sum +( total - vect[i][0]);
//        cout <<"value "<< total - vect[i][0]<<" ";
//        cout <<"sum "<< sum << " ";
//        cout << "\n";
//        
//    }
//    cout << "\n";
//    return (sum / n);
//}
int fcfs(vector<vector<int>> vect, int n) {
    cout<<vect.size();
    int t = 0;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            t = max(vect[i][0], t);
            
            total += t -  vect[i][0]+vect[i][1];
            t += vect[i][1];
            cout <<"total "<< total <<" ";        
        }
        cout << "\n";
        return (total / n);
    }

bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] < v2[1];
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> vect;

    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < 2; j++)
        {
            int temp;
            cin >> temp;
            row.push_back(temp);
        }
        vect.push_back(row);
    }
    sort(vect.begin(), vect.end(), sortcol);
    cout << fcfs(vect, n);

	
}