#include <stdio.h>
#include <math.h>

	int main()
{
	int i, n = 10;
	
	double a, b, dx, s1, s2, difference = 1;
	double c, d, e, f;
	
	printf("�����Լ��� x�� ������ ���� ����\n\n");
	printf("������ �����Լ��� ��� �Է�\n(����: 4x^3+x^2+3^x+2 = 4 1 3 2)\n");
	scanf("%lf %lf %lf %lf", &c, &d, &e, &f);
	printf("\nf(x)=(%.2lf)x^3+(%.2lf)x^2+(%.2lf)x+(%.2lf)�Էµ�\n", c, d, e, f);
	printf("�׽�Ʈ: f(2)=%lf\n\n", c*2*2*2+d*2*2+e*2+f);
	printf("\n���� �Է� (����: [1,2]->1 2)\n");
	scanf("%lf %lf", &a, &b);
	
	s1 = (c*b*b*b+d*b*b+e*b+f)+(c*a*a*a+d*a*a+e*a+f)*(b-a)/2;
	s2 = s1;
	
	printf("\n[%.2lf,%.2lf]���� f(x)=(%.2lf)x^3+(%.2lf)x^2+(%.2lf)x+(%.2lf) �� x�� ������ ���� ���\n\n", a, b, c, d, e, f);
	while(difference>0.000001)
	{
		s1 = s2;
		dx = (b-a)/n;
		
		double v[n+1];
		for(i=0;i<n+1;i++)
		{
			v[i] = fabs(c*(a+i*dx)*(a+i*dx)*(a+i*dx)+d*(a+i*dx)*(a+i*dx)+e*(a+i*dx)+f);
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
	printf("���� ���а��: %.6lf\n", s2);
	
	
	return 0;
	

}
