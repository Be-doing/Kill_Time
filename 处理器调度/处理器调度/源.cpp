#include"choose.h"

#define NUM 4
int main()
{
	PCB pcb[NUM];
	 Create(pcb, NUM);
	 mune();
	 Print(pcb, NUM);
	 Sort(pcb, NUM);
	 mune();
	 Print(pcb, NUM);

	 cout << endl;
	 Run(pcb,NUM);

	system("pause");
	return 0;
}