#include <iostream>
#include <string>

using namespace std;

int const numChar = 256;

int max(int a, int b) {
	return (a > b) ? a : b;
}

void charTable(string image, int m, int badchar[numChar]) {
	for (int i = 0; i < numChar; i++)
		badchar[i] = -1;
	cout << "[ ";
	
	for (int i = 0; i < m; i++) {
		badchar[(int)image[i]] = m-1-i;
	}
	for (int i = 0; i < m; i++) {
		cout << badchar[(int)image[i]] << " ";
	}
	cout << "]" << endl;
}

void search(string str, string image)
{
	int n = str.length();
	int m = image.length();
	int badchar[numChar];
	charTable(image, m, badchar);

	int index = 0;
	while (index <= (n - m)) {

		int j = m - 1;
		while (j >= 0 && image[j] == str[index + j]) {
			j--;
		}
		if (j < 0) {
			cout << "The image starts at index: " << index << endl;
			int temp;
			if (index + m < n) {
				temp = m - badchar[str[index + m]];
			}
			else { temp = 1; }
			index = index + temp;
		}
		else {
			index = index + max(1, j - badchar[str[index + j]]);
		}
	}
}

int main()
{
	string str;
	string image;
	cout << "Enter a string: ";
	getline(cin, str);
	cout << "Enter an image: ";
	getline(cin, image);
	if (str.length() < image.length()) {
		cout << "The image is bigger than the string";
		return 0;
	}

	search(str, image);
	return 0;
}