#include <stdio.h>
#include <math.h>

	int main()
{
	int i, n = 10;
	
	double a, b, dx, s1, s2, difference = 1;
	double c;
	
	printf("지수함수 적분 계산기\n\n");
	printf("적분할 지수함수의 밑 입력\n(예시: 3^x -> 3\n");
	scanf("%lf", &c);
	printf("\nf(x)=(%.2lf)^x 입력됨\n", c);
	printf("테스트: f(2)=%lf\n\n", pow(c, 2));
	printf("\n구간 입력 (예시: [1,2]->1 2)\n");
	scanf("%lf %lf", &a, &b);
	
	s1 = (pow(c, b)+pow(c, a))*(b-a)/2;
	s2 = s1;
	
	printf("\n[%.2lf,%.2lf]에서 f(x)=(%.2lf)^x 정적분 계산\n\n", a, b, c);
	while(difference>0.000001)
	{
		s1 = s2;
		dx = (b-a)/n;
		
		double v[n+1];
		for(i=0;i<n+1;i++)
		{
			v[i] = pow(c, a+i*dx);
		}
		
		for(i=0;i<n+1;i++)
		{
			if(i==0)
			{
				s2 = v[i];
			}
			else if(i==n)
			{
				s2 = s2+v[i];
			}
			else
			{
				s2 = s2+2*v[i];
			}
			}
		s2 = s2*dx/2;
	
		n = n*10;
		
	
		difference = fabs(s1-s2);
	
		}

	
	printf("\ndifference = %lf\n", difference);
	printf("최종 적분결과: %.6lf\n", s2);
	
	
	return 0;
	

}
