/*


A Constatn-Time Method

int capacity(const vector<int>& arr){
	return arr.size();
}


Revisiting the Method for Finding the Maximum in an Array

int findMax(const vector<int>& arr) {
	int max = arr[0];
	for (int i=1; i<arr.size(); i++){
		if (max<arr[i]; max = arr[i];
	}
	return max;
}


Three-Way Set Disjointness

bood areDisjoint(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
	for(int i=0; i<a.size(); i++)
		for(int j=0; j<b.size(); j++)
			for(k=0; k<c.size(); k++)
				if((a[i] == b[j])&&(b[j]==c[k])) return false;
	return true;
}

