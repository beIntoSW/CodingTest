#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int PACKAGE = 6;

/*
	비교하는 함수
	
	**** 중요 ****
	sort에 들어가는 비교 함수에는 같으면 false를 취해줘야 오류가 안남.
	https://en.cppreference.com/w/cpp/named_req/Compare 참고
*/
bool comp(int a, int b) {
	if (a >= b)
		return false;
	else
		return true;
}

/*
	최소값 구하는 함수

	pack_min	:	package 최소 가격
	each_min	:	각각 최소 가격
	lines		:	줄 개수
*/
int getMinPrice(int pack_min, int each_min, int lines) 
{
	int div, mod;
	div = lines / PACKAGE;
	mod = lines % PACKAGE;

	// ex) 14개 가격 > 18개 가격 -> 18개 가격이 최소
	if ((div + 1)*pack_min < div * pack_min + mod * each_min)
		return (div + 1)*pack_min;
	else
		return div * pack_min + mod * each_min;
}

// sorting 후 최소가격 return
int process(vector<int> package_table, vector<int> each_table, int lines)
{
	sort(package_table.begin(), package_table.end(), comp);
	sort(each_table.begin(), each_table.end(), comp);

	int pack_min = package_table[0];
	int each_min = each_table[0];

	return getMinPrice(pack_min, each_min, lines);
}

int main() {

	int lines, brands;

	scanf("%d %d", &lines, &brands);
	
	vector<int> each_table, package_table;

	for (int i = 0; i < brands; i++) {
		int p_price, e_price;
		scanf("%d %d", &p_price, &e_price);

		each_table.push_back(e_price);
		if (p_price > e_price*PACKAGE)
		{
			package_table.push_back(e_price*PACKAGE);
		}
		else 
		{
			package_table.push_back(p_price);
		}
	}

	int min_price = process(package_table, each_table, lines);

	printf("%d\n", min_price);

	return 0;
}
