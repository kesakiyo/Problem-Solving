#include <stdio.h>
#include <string.h>

int T, t, n, d, p, q, isConnected[51][51];
double DP[101][51], prob[51];

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &T);
	while(T--) {
		// �ʱ�ȭ�� �ϴ� �κ�
		memset(DP, 0, sizeof(DP));
		memset(isConnected, 0, sizeof(isConnected));
		memset(prob, 0, sizeof(prob));

		scanf("%d%d%d", &n, &d, &p);
		for(int i=0 ; i<n ; i++) 
			for(int j=0 ; j<n ; j++) 
				scanf("%d", &isConnected[i][j]);

		// ���� ��ġ���� �ٸ� ��ġ�� �� �� �ִ� Ȯ���� ����Ѵ�
		// �� �� ( ���� / ���� ) �� ���·� ����ϴ� ���� ������ �Ѵ�
		for(int i=0 ; i<n ; i++) {
			int cnt=0;
			for(int j=0 ; j<n ; j++)
				if(isConnected[i][j]) cnt++;
			prob[i]=1.0/cnt;
		}

		// DP[day][here] => day���� ������ �� here�� ���� Ȯ��
		// DP[day][here] = sigma(1, n) DP[day-1][there.i] * prob[there.i] : (there�� here�� �� �� �ִ� ������)
		// ���Ͱ��� ��ȭ���� �� �� �ִ�.
		// ������ʴ� 0���� �� �����ҿ� ���� Ȯ���� 100% �̹Ƿ� 1.0���� ������ �� �ش�
		DP[0][p]=1.0;
		for(int day=1 ; day<=d ; day++)
			for(int here=0 ; here<n ; here++)
				for(int there=0 ; there<n ; there++)
					if(isConnected[here][there]) DP[day][here]+=DP[day-1][there]*prob[there];

		scanf("%d", &t);
		while(t--) {
			scanf("%d", &q);
			printf("%.10lf ", DP[d][q]);
		}
		puts("");
	}
}