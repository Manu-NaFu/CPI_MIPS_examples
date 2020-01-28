#include <stdio.h>
#include <stdlib.h>
//#include "macros.h"    //Colour definition

int main ()
{
	int i = 0;
	
	//Gathering of the number of instructions
	
	int ninst = 0; // ninst -> Number of instructions
	do //Error control
	{
		printf("\nIntroduce the number of instructions: ");
		scanf("%d",&ninst);
	}while (ninst < 0);
	
	
	int cpi_base_inst[ninst];  //CPI vector of each instruction for the base machine
	double f_base_inst[ninst];  //Frequency of occurrence vector of each instruction for the base machine
	
	int cpi_opt_inst[ninst];  //CPI vector of each instruction for the optimized machine
	double f_opt_inst[ninst];  //Frequency of occurrence vector of each instruction for the optimized machine
	
	double f_total_base = 0; //Total accumulated frecuency of each instruction for the base machine
	double f_total_opt = 0; //Total accumulated frecuency of each instruction for the optimized machine
	
	//Gathering of the CPI of each instruction and the frecuency of occurrency for both machines
	printf("\n\nBase machine ---->");
	do{
		f_total_base = 0;
		for (i = 0; i < ninst; i++)
		{
			do //Error control
			{
				printf("\n\tIntroduce the CPI of the instruction %c of the base machine: ", i+65);
				scanf("%d", &cpi_base_inst[i]);
				if (cpi_base_inst[i] < 0)
					printf("\n\t\tThe value was lower than 0, introduce an acceptable value\n");
			}while (cpi_base_inst[i] < 0);
			
			do //Error control
			{
				printf("\n\tIntroduce the frecuency of occurrency of the instruction %c (expressed in times one) of the base machine: ", i+65);
				scanf("%lf", &f_base_inst[i]);
				f_total_base += f_base_inst[i];

				if (f_base_inst[i] < 0 || f_base_inst[i] > 1)
					printf("\n\t\tThe value of frecuency of occurrency for the instrucion %c was higher than 1 or lower than 0, introduce an acceptable value.\n");
			}while (f_base_inst[i] < 0 || f_base_inst[i] > 1);

			if (f_total_base > 1)
			{
				printf("\nTHE TOTAL ACCUMULATED FRECUENCY IS HIGHER THAN 1, REVISE THE VALUES AND INTRODUCE THEM AGAIN.\n");
				break;
			}
		}
	}while (f_total_base > 1);
	
	printf("\n\nMaquina optimizada ---->");
	do{
		f_total_opt = 0;
		for (i = 0; i < ninst; i++)
		{
			do //Control de errores
			{
				printf("\n\tIntroduce the CPI of the instruction %c of the optimized machine: ", i+65);
				scanf("%d", &cpi_opt_inst[i]);
				if (cpi_opt_inst[i] < 0)
					printf("\n\t\tThe value was lower than 0, introduce an acceptable value\n");
			}while (cpi_opt_inst[i] < 0);

			do
			{
				printf("\n\tIntroduce the frecuency of occurrency of the instruction %c (expressed in times one) of the optimized machine: ", i+65);
				scanf("%lf", &f_opt_inst[i]);
				f_total_opt += f_opt_inst[i];
				
				if (f_opt_inst[i] < 0 || f_opt_inst[i] > 1)
					printf("\n\t\tThe value of frecuency of occurrency for the instrucion %c was higher than 1 or lower than 0, introduce an acceptable value.\n");
			}while (f_opt_inst[i] < 0 || f_opt_inst[i] > 1);

		if (f_total_opt > 1)
			{
				printf("\nTHE TOTAL ACCUMULATED FRECUENCY IS HIGHER THAN 1, REVISE THE VALUES AND INTRODUCE THEM AGAIN.\n");
				break;
			}
		}
	}while (f_total_opt > 1);

	
/*	
	//////////////Testing
	
	cpi_base_inst[0]=2;
	cpi_base_inst[1]=3;
	cpi_base_inst[2]=3;
	cpi_base_inst[3]=5;
	cpi_base_inst[4]=6;
	
	cpi_opt_inst[0]=2;
	cpi_opt_inst[1]=2;
	cpi_opt_inst[2]=3;
	cpi_opt_inst[3]=4;
	cpi_opt_inst[4]=10;
	
	f_base_inst[0]=0.2;
	f_base_inst[1]=0.15;
	f_base_inst[2]=0.1;
	f_base_inst[3]=0.1;
	f_base_inst[4]=0.45;
	
	f_opt_inst[0]=0.4;
	f_opt_inst[1]=0.15;
	f_opt_inst[2]=0.1;
	f_opt_inst[3]=0.1;
	f_opt_inst[4]=0.25;

*/
	
	
	
	/////////////Example 1 (improvement of the hardware)

	//printf(BGREEN "\n\n\n\nExample 1\n" RESET);  //Colour printing with macros
	printf("\n\n\n\nExample 1\n");	

	/////////////Example 1 a) Calculation of the CPI for each machine
	double cpimbase = 0;  //Initialization to the subsecuent calculation of the CPI of the base machine
	double cpimopt = 0;  //Initialization to the subsecuent calculation of the CPI of the optimized machine

	//Calculation of the CPI of both machine using the CPI of each instruction and its frecuency of occurrency
	for (i = 0; i < ninst; i++)
	{
		cpimbase += (cpi_base_inst[i] * f_base_inst[i]);
		cpimopt += (cpi_opt_inst[i] * f_opt_inst[i]);
	}
	
	//Results printing
	printf("\n\ta)\n\t\tCPIMbase = %.3f \n\t\tCPIMopt = %.3f\n\n",cpimbase,cpimopt);



	/////////////Example 1 b) Calculation of the MIPS for each machine
	double fbase = 50; //Clock frecuency of the base machine (MHz)
	double fopt = 60; //Clock frecuency of the optimized machine (MHz)
	
	//MIPS calculation for each machine
	double mipsbase = (fbase) / (cpimbase); 
	double mipsopt = (fopt) / (cpimopt);

	//Results printing
	printf("\n\tb)\n\t\tMIPSbase = %.3f \n\t\tMIPSopt = %.3f\n\n",mipsbase,mipsopt);



	///////////// Example 1 c) Calculation of the improvement
	//Results printing (implicit calculation of the improvement obtained)
	printf("\n\tc)\n\t\tMIPSMopt/MIPSMbase = %.3f/%.3f = %.3f\n\t\tMopt is a %.2f%% faster than Mbase.\n\n",mipsopt,mipsbase,mipsopt/mipsbase,((mipsopt/mipsbase)-1)*100);
	
	
	
	/////////////Example 1 d) Calculation of the frecuency to make both machines achieve the same performance.
	//base Solved equation to obtain the new frecuency for the base machine
	double fbasemod = (fopt*cpimbase) / (cpimopt); 
	
	//Results printing
	printf("\n\td)\n\t\tWe would need to modify the frecuency of the base machine so it achieves the same performance as the optimized machine. The value would be: %.3f MHz\n", fbasemod);
	
	
	



	
	
	/////////////Example 2 (improvement of the compiler)
	//printf(BGREEN "\nExample 2\n" RESET);	//Colour printing with macros
	printf("\n\n\n\nExample 2\n");
	
	
	double f_mej[ninst]; //Vector to store the improvement of the frecuency of each instruction (each position represents an instruction)
	double f_mej_base[ninst]; //Improvement obtained for the base machine
	double f_mej_opt[ninst]; //Improvement obtained for the optimized machine
	double n_inst_base_t = 0; //Total number of instructions run in the base machine after the improvement
	double n_inst_opt_t = 0; //Total number of instructions run in the optimized machine after the improvement
	
/*
	//////////////Testing

	f_mej[0]=0.9;
	f_mej[1]=0.9;
	f_mej[2]=0.85;
	f_mej[3]=0.95;
	f_mej[4]=0.1;

*/
	
	/* 
		Gathering of the improvement on the frecuency of occurrency of the intructions after improving the compiler and 
		calculation of the improved frecuencies and the total number of instructions for 
		both the base machine and optimized machine
	*/

	for (i = 0; i < ninst; i++)
	{
		do{ //Error control
			printf("\n\tIntroduce the improvement in the frecuency for the instruction %c: ", i+65);
			scanf("%lf", &f_mej[i]);
			if (f_mej[i] < 0 || f_mej[i] > 1)
				printf("\n\t\tThe improvement of the value of frecuency of occurrency for the instrucion %c was higher than 1 or lower than 0, introduce an acceptable value.\n");
		while (f_mej[i] < 0 || f_mej[i] > 1)
		
		f_mej_base[i] = f_mej[i] * f_base_inst[i];
		n_inst_base_t += f_mej_base[i];
		
		f_mej_opt[i] = f_mej[i] * f_opt_inst[i];
		n_inst_opt_t += f_mej_opt[i];
		
	}
	
	
	/////////////Example 2 a) Calculation of the CPI for the base machine after the improvement of the compiler (new machine will be called Mcomp)
	double cpimcomp = 0; //Initialization for the subsecuent calculation of the CPI of the base machine with the improved compiler
	
	//Calculation of the new CPI
	for (i = 0; i < ninst; i++)
		cpimcomp += (cpi_base_inst[i] * f_mej_base[i]);
		
	cpimcomp /= n_inst_base_t;

	printf("\n\ta)\n\t\tCPIMcomp = %.3f \n\n",cpimcomp);
	
	
	
	/////////////Example 2 b) Calculation of the improvement of Mcomp compared to Mbase
	double mipsmcomp = (fbase) / (cpimcomp);
	
	printf("\n\tb)\n\t\tMIPSMcomp/MIPSMbase = %.3f/%.3f = %.3f\n\t\tMcomp is a %.2f%% faster than Mbase.\n\n",mipsmcomp,mipsbase,mipsmcomp/mipsbase,((mipsmcomp/mipsbase)-1)*100);
	
	
	
	/////////////Example 2 c) Calculation of the improvement obtained for the optimized machine after the improvement of the compiler (the new machine will be called Mamb)
	//Inicializacion para calculo posterior de los CPI de la maquina con las mejoras de compilador y hardware
	double cpimamb =  0;
	
	//Calculation of the CPI for Mamb
	for (i = 0; i < ninst; i++)
		cpimamb += (cpi_opt_inst[i] * f_mej_opt[i]);
		
	cpimamb /= n_inst_opt_t;

	//MIPS
	double mipsmamb = (fopt) / (cpimamb);
	
	//Results printing
	printf("\n\tc)\n\t\tMIPSMamb/MIPSMbase = %.3f/%.3f = %.3f\n\t\tMamb is a %.2f%% faster than Mbase.\n\n",mipsmamb,mipsbase,mipsmamb/mipsbase,((mipsmamb/mipsbase)-1)*100);


	return 0;
}
