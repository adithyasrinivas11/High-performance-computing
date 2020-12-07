#include <iostream>
#include<stdlib.h>
#include <complex>
#define MAX 65536

using namespace std;

#define M_PI 3.1415926535897932384



int check(int n)    //Function to check if the number is a power of 2
{
  return ( (n > 0) && ((n & (n - 1)) == 0) ) ;
}



int log2(int N)    //Function to calculate the log2 of int numbers
{
  int k = N, i = 0;
  while(k) 
  {
	k >>= 1;
	i++;
  }
  return i - 1;
}



void ordering(complex<double>* f1, int N) //To get the FFT order of elements
{
	complex<double> f2[MAX];

	int NoOfBits = log2(N);
	int num, temp, reverse_num;

//Loop through all the bits of an integer. 
//If a bit at ith position is set in the i/p no. then set the bit at (NoOfBits – 1) – i in o/p. 
//Where NoOfBits is number of bits present in the given number.

	for(int j=0;j<N;j++)   
	{
		num = j;
		reverse_num = 0;
		for (int i = 0; i < NoOfBits; i++) 
		{ 
			temp = (num & (1 << i));
			if(temp)
				reverse_num |= 1 << ((NoOfBits - 1) - i);
		}
		f2[j]= f1[reverse_num];
	}

	for(int j = 0; j < N; j++)
		f1[j] = f2[j];	
}


void FFT(complex<double>* f, int N) //
{
	ordering(f, N);    //To get the FFT order of elements


	complex<double> *W;
	W = (complex<double> *)malloc(N / 2 * sizeof(complex<double>)); //Declaring array to hold W values
	W[1] = polar(1., -2. * M_PI / N); 
	W[0] = 1;
	for(int i = 2; i < N / 2; i++)
		W[i] = pow(W[1], i); //Initialising necessary powers of W




	int n = 1;
	int a = N / 2;

	for(int j = 0; j < log2(N); j++) //This loop will run for each stage of the fft. Ex: For 8 points - 3 stages, For 16 - 4 stages., etc 
	{
		for(int i = 0; i < N; i++) //Run through all the points 
		{
			if(!(i & n)) //Only the first edge of each butterfly will satisfy this if condition. Therefore, this condition is satisfied for each butterfly once.
			{
				complex<double> temp = f[i];
				//cout<<"W is "<<(i * a) % (n * a)<<endl<<"i "<<i<<" and n "<<n<<" and a"<<a<<endl;
				complex<double> Temp = W[(i * a) % (n * a)] * f[i + n];
				f[i] = temp + Temp; //Computing first edge of the butterfly
				f[i + n] = temp - Temp; //Computing second edge of the butterfly
			}
		}

		n *= 2;
		a = a / 2;
  }
  free(W);
}




int main()
{
	int n;
	do 
	{
		cout<<"Specify the array dimension (Power of 2)"<<endl;
		cin>>n;
  	} while(!check(n)); //Function to check whether the input size is a power of 2

 	complex<double> vec[MAX]; //Declaration of the complex vector to hold the values

 	cout << "specify the array" << endl;
 	for(int i = 0; i < n; i++)  //Initialisation
 	{
		cout << "specify element number: " << i << endl;
		vec[i]=rand()%10;
	}

	FFT(vec, n); //FFT algo


	cout << "Printing the FFT of the array specified" << endl; //Printing
	for(int j = 0; j < n; j++)
		cout << "vec["<<j<<"] is :"<<vec[j] << endl;
  return 0;
}
