#include <stdio.h>
#include <math.h>

	int main() 
{
	int i, n = 10; //정수 변수 선언 
	
	double a, b, dx, s1, s2, difference = 1; //사다리꼴 근사에 이용되는 실수 변수들 선언  
	double c, d, e; //이차함수의 계수에 해당하는 실수 변수들 선언 
	
	printf("이차함수 적분 계산기\n\n");
	printf("적분할 이차함수의 계수 입력\n(예시: x^2+3^x+2 = 1 3 2)\n"); 
	scanf("%lf %lf %lf", &c, &d, &e); // 이차함수의 계수를 차례로 입력받아 변수 c,d,e에 저장 
	printf("\nf(x)=(%.2lf)x^2+(%.2lf)x+(%.2lf) 입력됨\n", c, d, e);
	printf("테스트: f(2)=%lf\n\n", c*2*2+d*2+e); // 입력한 이차함수식 확인 및 f(2) 대입으로 함숫값 확인 
	printf("\n구간 입력 (예시: [1,2]->1 2)\n"); 
	scanf("%lf %lf", &a, &b); // 적분구간을 입력받아 변수 a,b에 저장 
	
	s1 = (c*b*b+d*b+e)+(c*a*a+d*a+e)*(b-a)/2; //s1은 적분구간을 나누지 않은 사다리꼴의 넓이, 즉 (f(b)+f(a))*(b-a)/2 에 해당한다.  
	s2 = s1;
	
	printf("\n[%.2lf,%.2lf]에서 f(x)=(%.2lf)x^2+(%.2lf)x+(%.2lf) 정적분 계산\n\n", a, b, c, d, e);
	while(difference>0.000001) // 극한을 취하는 과정. n이 무한대에 가까워지는 것을 구현하기 위해, 이전에 구한 넓이의 합과 차이가 10^-6 이하가 될 때까지 n의 값을 10배씩 증가시켜, 차가 10^-6 이하의 근소한 값이 되면 수렴하였다고 간주하였다.                   
	{
		s1 = s2; // s2의 값을 변수 s1에 저장 
		dx = (b-a)/n; // 적분구간을 n개의 부분으로 나눈 한 부분의 길이 dx를 정의 
		
		double v[n+1]; // v[n+1] 이라는 배열 정의, 배열의 항 수는 n+1개(v[0], v[1]....v[n])이다.
		for(i=0;i<n+1;i++) // i=0부터 i<n+1 까지, 즉 이하를 n+1번 반복 
		{
			v[i] = c*(a+i*dx)*(a+i*dx)+d*(a+i*dx)+e; // v[i] 에 f(a+i*dx)를 저장한다. 이는 사다리꼴의 윗변/아랫변의 길이가 된다. 
		}
		
		for(i=0;i<n+1;i++) // 역시 이하를 n+1번 반복 
		{
			if(i==0)  
			{
				s2 = v[i]; // i=0 일 때, v[0]은 한 번만 더한다.
			}
			else if(i==n)
			{
				s2 = s2+v[i]; // 마찬가지로 i=n 일 때, v[n]은 한 번만 더한다.
			}
			else
			{
				s2 = s2+2*v[i]; // 나머지 항은 2번씩 더한다. 
			} // 이 과정을 통해 s2 = v[0]+v[n]+2(v[1]+v[2]+....+v[n-1]) 형태가 되었다. 
			}
		s2 = s2*dx/2; // 이 값에 dx를 곱하고 2로 나눔으로써 s2는 적분구간을 n개로 나눈 사다리꼴의 넓이의 합이 되었다. 
		printf("\nn=%d 일때 넓이 = %lf\n", n, s2);
		n = n*10; // n에 10을 곱하고 위 과정을 반복한다. 
		
	
		difference = fabs(s1-s2); // difference는 이전에 계산했던 값과의 편차 
		printf("difference = %lf\n\n", difference);
		}

	
	printf("\ndifference = %lf\n", difference);
	printf("최종 적분결과: %.6lf\n", s2); // difference가 10^-6 이하가 될 때, 최종 결과 출력 
	
	
	return 0;
	

}
