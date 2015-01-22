#include <stdio.h>
#include <string.h>

int T, t, n, d, p, q, isConnected[51][51];
double DP[51][101], prob[51];

// �޸������̼��� ���� ����Ž��
double solution(int here, int day) {
	// ���� ������ʸ� < d��° �Ǵ� �� q�� �ִ°�? > �� ����ְ� �ȴٸ�
	// q�� �޶��� ������ ���Ӱ� �������̺��� �ۼ��� ����ϴ� ���ŷο��� ����� �ȴ�
	// �ֳĸ� �츮�� ���� ���� day���� ������ �� q�� ������ Ȯ���� ���� ���̹Ƿ�...
	// ���ذ� �Ȱ��ٸ� �ٽ��Ѹ� ���þ� ������ ���ٸ� ���ذ� �� ���̴�
	// ���� �츮�� ���ϴ� ���� day���� ������ �� here�� �ִ� Ȯ���� �ٲ㼭 ����� �� �� �ʿ䰡 �ִ�
	// ������ʸ� < 0��° �Ǵ³� p, �� �����ҿ� �ִ°�? > ��� ����ָ� 
	// �츮�� ���Ϸ��� ���� ����� �� ���� ������?
	if(day==0) {
		if(here==p) return 1.0;
		return 0.0;
	}

	// ���� ���°� �޸������̼��� �ƴ��� Ȯ���Ѵ�
	double& ret=DP[here][day];
	if(ret!=-1.0) return ret;

	// ret�� -1.0�̱� ������ ret�� 0.0���� �ٲ� �� �ʿ䰡 �ִ�
	// �ֳ��ϸ� Ȯ���� ����ؼ� ������ ���� ���ε� -1.0���� ������ ������ �ȵǱ� ����
	ret=0.0;

	// here��ġ�� �� �� �ִ� there�鿡 ���� Ȯ���� ����Ѵ�
	// here��ġ�� �� �� �ִ� there�鿡 ���� Ȯ���̱� ������ ���ϴ� ���� prob[here]�� �ƴ϶�
	// prob[there]�� �Ǵ°����� ����Ѵ�
	// here�� �� �� �ִ°��� �Ѱ����� �ƴϱ� ������ += �����ڸ� �̿��� Ȯ���� �����Ѵ�
	for(int there=0 ; there<n ; there++)
		if(isConnected[here][there]) 
			ret+=solution(there, day-1)*prob[there];

	return ret;
}

int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &T);
	while(T--) {
		// �ʱ�ȭ�� �ϴ� �κ�
		// �޸������̼��� �ʱⰪ�� -1.0���� ������ �ش�.(0.0�� �ΰ��� �ǹ̸� �����ϱ� ����)
		for(int i=0 ; i<51 ; i++) for(int j=0 ; j<101 ; j++) DP[i][j]=-1.0;
		memset(isConnected, 0, sizeof(isConnected));

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

		// �츮�� ������ʸ� �ٲ㼭 �����߱� ������ ���ο� ���ǰ� ���� ������
		// DP���̺��� ���Ӱ� ���Ž����� �ʿ䰡 ��������
		scanf("%d", &t);
		while(t--) {
			scanf("%d", &q);
			double sol=solution(q, d);
			printf("%.10lf ", sol);
		}
		puts("");
	}
}