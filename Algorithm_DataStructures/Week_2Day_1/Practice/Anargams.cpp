#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

void PAT(string arr[], int size)
{
	unordered_map<string, vector<string>> map;
	for (int i = 0; i < size; i++)
	{
		string value = arr[i];
		char letters[32];
		strcpy_s(letters,32, value.c_str());
		sort(letters, letters + value.size() + 1);
		string newvalue = "";
		for (int i = 0; i < value.size() + 1; i++)
		{
			newvalue += letters[i];
		}

		if (map.find(newvalue) != map.end())
		{
			map[newvalue].push_back(value);
		}
		else
		{

			
			vector<string> values;
			values.push_back(value);
			map[newvalue] = values;
		}
	}

	
	unordered_map<string, vector<string>>::iterator it;
	for (it = map.begin(); it != map.end(); it++)
	{
		vector<string> values = map[it->first];
		if (values.size() > 1)
		{
			cout << "[";
			for (int i = 0; i < values.size() - 1; i++)
			{
				cout << values[i] << ", ";
			}
			cout << values[values.size() - 1];
			cout << "]";
		}
	}
}


int main()
{
	string arr[] = { "cat", "dog", "tac",
					"god", "act" };
	int size = sizeof(arr) / sizeof(arr[0]);

	PAT(arr, size);

	return 0;
}


