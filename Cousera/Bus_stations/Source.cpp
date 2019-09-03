#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
	vector<string> bus;
	map<int, vector<string>> buses;

	int counter = 1;
	int q;
	cin >> q;

	for (int i = 0; i < q; i++)
	{

		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			string stop;
			cin >> stop;

			bus.push_back(stop);
		}

		if (buses.empty())
		{
			buses[0] = bus;
			cout << "New bus 1" << endl;
			bus.clear();
		}
		else
		{
			bool valid = false;
			bool validn = false;
			for (const auto item : buses)
			{
				if (bus == item.second)
				{
					cout << "Already exists for " << item.first + 1 << endl;
					bus.clear();
					valid = true;
				}
			}
			for (const auto item : buses)
			{
				if (valid != true && validn != true)
				{
					buses[counter] = bus;
					cout << "New bus " << counter + 1 << endl;
					bus.clear();
					valid = false;
					validn = true;
					counter++;
				}
				
			}

		}
	}
	system("pause");
	return 0;
}