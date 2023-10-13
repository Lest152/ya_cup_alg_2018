#include <vector>       // for vector
#include <array>
#include <iostream>     // for cout/cin, streamsize
#include <sstream>      // for istringstream
#include <algorithm>    // for copy, copy_n
#include <iterator>     // for istream_iterator<>, ostream_iterator<>
#include <limits>       // for numeric_limits

using namespace std;



void division()
{
	string res = "Yes";
	int n;

	vector<vector<int>> input;
	
	int i { 0 };
	cin >> n;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (i < n) {
		string line;
		getline(cin, line);
		if (cin) {
			istringstream iss { line };
			vector<int> v;
			copy(istream_iterator<int>(iss), {}, back_inserter(v));
			input.push_back(v);
		}
		i++;
	}

	if(n > 2) {
		struct point {
			float x;
			float y;
		};

		vector<point> points;
		
		for (int i { 0 }; i < n; i++) {
			points.push_back({});
			if (input[i][0] == 0) {		//Круг
				points[i].x = input[i][1];
				points[i].y = input[i][2];
			}
			else {	//Прямоугольник
				points[i].x = (float)(input[i][1] + input[i][5]) / 2;
				points[i].y = (float)(input[i][2] + input[i][6]) / 2;
			}

			if (i >= 2)
				if ((points[0].x - points[i].x) / (points[0].y - points[i].y) != (points[0].x - points[1].x) / (points[0].y - points[1].y)) {
					res = "No";
					break;
				}
					
		}

		
	}
	
	cout << res << endl;
}

int main()
{
	division();
}