#include <iostream>
using namespace std;

typedef struct ClassLeader
{
	int score[3];
	int sum;
};

ClassLeader leader[3];
ClassLeader maximum;
int main()
{
	int i, j, k, n, maxIndex;
	
	cin >> n;

	for (i = 0; i < 3; i++)
	{
		leader[i].sum = 0;
		for (j = 0; j < 3; j++)
		{
			leader[i].score[j] = 0;
		}
	}

	for (i = 0; i < n; i++)
	{
		int input;
		for (j = 0; j < 3; j++)
		{
			cin >> input;
			leader[j].score[input - 1]++;
		}
	}

	maximum.sum = -1;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			leader[i].sum += leader[i].score[j] * (j + 1);
		}

		if (maximum.sum < leader[i].sum)
		{
			maximum = leader[i];
			maxIndex = i;
		}
		else if (maximum.sum == leader[i].sum)
		{
			for (k = 0; k < 3; k++)
			{
				if (maximum.score[k] < leader[i].score[k])
				{
					maximum = leader[i];
					maxIndex = i;
					break;
				}
				else if (maximum.score[k] > leader[i].score[k])
					break;
				if (k == 2)
					maxIndex = -1;
			}
		}
	}

	cout << maxIndex + 1 << ' ' << maximum.sum;

	return 0;
}