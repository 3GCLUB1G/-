#include <stdio.h>

	int main()
{
	int i, n = 10;
	
	double a, b, dx, s1, s2, difference = 1;
	double c, d, e, f, g;
	
	printf("�����Լ� ���� ����\n\n");
	printf("������ �����Լ��� ��� �Է�\n(����: x^4+4x^3+x^2+3x+2 = 1 4 1 3 2)\n");
	scanf("%lf %lf %lf %lf %lf", &c, &d, &e, &f, &g);
	printf("\nf(x)=(%.2lf)x^4+(%.2lf)x^3+(%.2lf)x^2+(%.2lf)x+(%.2lf)�Էµ�\n", c, d, e, f, g);
	printf("�׽�Ʈ: f(2)=%lf\n\n", c*2*2*2*2+d*2*2*2+e*2*2+f*2+g);
	printf("\n���� �Է� (����: [1,2]->1 2)\n");
	scanf("%lf %lf", &a, &b);
	
	s1 = (c*b*b*b*b+d*b*b*b+e*b*b+f*b+g)+(c*a*a*a*a+d*a*a*a+e*a*a+f*a+g)*(b-a)/2;
	s2 = s1;
	
	printf("\n[%.2lf,%.2lf]���� f(x)=(%.2lf)x^4+(%.2lf)x^3+(%.2lf)x^2+(%.2lf)x+(%.2lf) ������ ���\n\n", a, b, c, d, e, f, g);
	while(difference>0.000001)
	{
		s1 = s2;
		dx = (b-a)/n;
		
		double v[n+1];
		for(i=0;i<n+1;i++)
		{
			v[i] = c*(a+i*dx)*(a+i*dx)*(a+i*dx)*(a+i*dx)+d*(a+i*dx)*(a+i*dx)*(a+i*dx)+e*(a+i*dx)*(a+i*dx)+f*(a+i*dx)+g;
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
