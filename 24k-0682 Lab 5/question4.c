/*
 * Name: Mustafa Bukhari
 * Roll#: 24k-0682
 * Desc: Question 4 Lab 5
*/
#include <stdio.h>
int main () {
	float attendance,assignmentScores,examresults;
	printf("What is the Attendance score\n");
	scanf("%f",&attendance);
	printf("What is the total Assignment Score\n");
	scanf("%f",&assignmentScores);
	printf("What is the total Exam result\n");
	scanf("%f",&examresults);
	float FinalGrade;
	attendance=attendance*0.20;
	assignmentScores=assignmentScores*0.20;
	examresults=examresults*0.60;
	FinalGrade=attendance+assignmentScores+examresults;
	if (FinalGrade>=60){
		if (FinalGrade<70){
		printf("Your Grade is C\n");
		printf("Your Total score is %f",FinalGrade);
		}
	}
	if (FinalGrade>=70){
		if (FinalGrade<80){
		printf("Your Grade is B\n");
		printf("Your Total score is %f",FinalGrade);
		}
	}
	if (FinalGrade>=80){
		if (FinalGrade<90){
		printf("Your Grade is A\n");
		printf("Your Total score is %f",FinalGrade);
		}
	}
	if (FinalGrade>=90){
		printf("Your Grade is A*\n");
		printf("Your Total score is %f",FinalGrade);
	}
	return 0;
}
		