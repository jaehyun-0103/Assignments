#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void charges(double, double*, double*);
void round_money(double*);

int main() {
	int month, year;
	int customer_no;
	double time_usage;
	double monthly_charge;
	double avg_charge;
	FILE* inptr;
	FILE* outptr;

	inptr = fopen("indata.txt", "r"); // 입력 파일 indata.txt 오픈
	outptr = fopen("charges.txt", "w"); // 출력 파일 charges.txt 오픈

	if (inptr == NULL || outptr == NULL) {
		printf("Failed to open files.\n");
		return 1;
	}

	// 파일의 첫번째 라인의 달(month)와 해(year)를 읽어 month와 year에 입력
	fscanf(inptr, "%d %d", &month, &year);
	fprintf(outptr, "Charges for %d/%d\n", month, year);
	fprintf(outptr, "Customer Hours used charge/hour Avg cost\n");

	while (fscanf(inptr, "%d %lf", &customer_no, &time_usage) != EOF) {
		charges(time_usage, &monthly_charge, &avg_charge);
		round_money(&avg_charge);

		fprintf(outptr, "%d %.1lf %.2lf %.2lf\n", customer_no, time_usage, monthly_charge, avg_charge);
	}

	fclose(inptr);
	fclose(outptr);

	return 0;
}

void charges(double time_usage, double* monthly_charge, double* avg_charge) {
	double base_rate = 7.99;
	double per_hour_rate = 1.99;
	double per_minute_rate = 1.99;

	if (time_usage <= 10.0) {
		*monthly_charge = base_rate;
		*avg_charge = base_rate / time_usage;
	}
	else {
		double excess_hours = time_usage - 10.0;
		int rounded_excess_hours = (int)excess_hours + 1;  // 정수로 반올림
		double rounded_excess_charge = rounded_excess_hours * per_minute_rate;

		*monthly_charge = base_rate + rounded_excess_charge;
		*avg_charge = *monthly_charge / time_usage;
	}
}

void round_money(double* avg_charge) {
	*avg_charge = ((int)(*avg_charge * 100 + 0.5)) / 100.0;
}