#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<string>words;
	for(string temp; cin>> temp;)
		words.push_back(temp);
	cout << "Number of words: " << words.size() << endl;

	sort(words);

	for (int i = 0; i < words.size(); ++i)
		cout << words[i] << endl;

	return 0;
}

