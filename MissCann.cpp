#include <iostream>
#include <vector>
#include <string>

using namespace std;
/***************************************************************************************************************
		CREATOR:	RICHARD CHAIDEZ
		ASSIGNMENT: PROJECT1
		DATE:	2/16/16


		THIS PROJECT IS MISSIONARY AND CANNIBAL CROSSING THE RIVER PROBLEM. IT USES ITERATIVE DEEPENING 
		SEARCH ALGORITHM TO FIND THE GOAL STATE WHICH IS <000> FROM THE BEGINNING STATE <133>. THERE CANNOT
		BE MORE CANNIBALS THAN MISSIONARIES AS ALL TIME. ALSO, ONLY TWO CAN CROSS THE RIVER AT A TIME.THIS
		PROJECT SOLVED THE PROBLEM.
*****************************************************************************************************************/
//CHANGE THE STATES 
vector <pair < int, pair<int, int> > > newStateSet(pair<int, pair<int, int> > states){
	vector <pair <int, pair<int, int > > > newStateSet;
	int c = states.second.first;
	int m = states.second.second;
	int b = states.first;
	//IF BOAT IS ON THE LEFT SIDE, CHECH CONDITIONS
	if (b == 1){
		if (c >= 2 && m >=3)
			newStateSet.push_back(make_pair(0, make_pair(c - 2, m)));
		else if (m > c && c <=1)
			newStateSet.push_back(make_pair(0, make_pair(c, m - 2)));
		else if (c >= 2 && m >=2)
			newStateSet.push_back(make_pair(0, make_pair(c , m-2)));
		else if (c >= 3 && m ==0)
			newStateSet.push_back(make_pair(0, make_pair(c-2, m)));
		else
			newStateSet.push_back(make_pair(0, make_pair(c-2, m )));
	}
	//IF BOAT IS ON THE RIGHT SID, CHECK CONDITIONS
	if (b == 0){
		if (m >=3 && m > c)
			newStateSet.push_back(make_pair(1, make_pair(c +1 , m)));
		else if (c >= 1 && m >= c)
			newStateSet.push_back(make_pair(1, make_pair(c+1, m+1)));
		else if (c >= 2 && m == 0)
			newStateSet.push_back(make_pair(1, make_pair(c + 1, m)));
		else if (c >= 1 && m == 0)
			newStateSet.push_back(make_pair(1, make_pair(c + 1, m)));
		else
			newStateSet.push_back(make_pair(0, make_pair(c, m)));

	}


	//RETURN NEW STATE
	return newStateSet;
}
//DISPLAT STATES METHOD
void displaystate(pair<int,pair<int, int>> state){
	int B = state.first;
	int C = state.second.first;
	int M = state.second.second;
	
	cout << B << " " << C << " " << M;
	cout << endl;
} 
//CHECK IF THERE ARE NOR MORE CANNIBALS THAN MISSIONARY
bool validState(pair<int, pair<int, int> > state){
	int C = state.second.first, M = state.second.second;
	

	if (M >= C && M != 0 || M == 0)
		return true;
	else 
		return false;
	
}
//DEPHT LIMITED SEARCH CHECKS IF THE GOAL IS MET OR IS A VECTOR IS VALID, THEN IT STORES IT IN THE LEAF NODE AND THEN INSERTS IT TO
//THE ORIGINAL VECTOR FROM THE IDS METHOD
bool DLS(pair<int, pair <int, int> > source, pair<int, pair<int, int>>goal, int depth, vector<pair<int, pair<int, int>>> &ans){
	
	if (depth == 0 && source == goal)
		return false;
	if (source == goal){
		cout << "goal is found at depth " << depth << "\n";
		return true;
	}
		
	
	vector<pair<int, pair<int, int>>> leafs = newStateSet(source);
	for (int i = 0; i < leafs.size(); i++){
		if (validState(leafs[i])){
			if (DLS(leafs[i], goal, depth +1, ans)){
				ans.push_back(leafs[i]);
				return true;
			}
		}
		
	}

}
//ITERATIVE DEEPENING SEARCH SEARCHES THROUGH ALL NODES AND THEN DISPLAYS THEM
void IDS(pair<int, pair<int, int> > source, pair<int, pair< int, int> > goal){
	vector<pair<int, pair<int, int >>> ans;
	for (int i = 1; i <= 25; i++){
		vector<pair<int, pair<int, int>>>vec;
		DLS(source, goal, i, vec);
		if (vec.size() > 0){
			ans = vec;
			break;
		}
		
	}
	cout << "Boat starts out on the left side 1 then goes to the right side 0\n";
	cout << "B C M\n";
	displaystate(source);
	for (int i = ans.size()-1; i >= 0; i--)
		displaystate(ans[i]);
	
	

	
}

int main(){
	//they are all on the left side
	pair<int, pair<int, int> > source = make_pair(1, make_pair(3, 3));
	//goal is to have them all cross the river to the right side
	pair<int, pair<int, int> > goal = make_pair(0, make_pair(0, 0));
	//CALLING ITERATIVE DEEPENING FUNCTION
	IDS(source, goal);

	system("pause");
	return 0;
}