#include <stdio.h>
#include <math.h>

	int main()
{
	int i, n = 10;
	
	double a, b, dx, s1, s2, difference = 1;
	
	printf("cos(x) 적분 계산기\n\n");
	printf("구간 입력 (예시: [1,2]->1 2)\n");
	scanf("%lf %lf", &a, &b);
	
	s1 = (cos(a)+cos(b))*(b-a)/2;
	s2 = s1;
	
	printf("[%.2lf,%.2lf]에서 cos(x) 정적분 계산\n\n", a, b);
	while(difference>0.000001)
	{
		s1 = s2;
		dx = (b-a)/n;
		
		double v[n+1];
		for(i=0;i<n+1;i++)
		{
			v[i] = cos(a+i*dx);
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
	printf("최종 적분결과: %.6lf", s2);
	
	return 0;
}
