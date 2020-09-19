
#include <program.h>
int main() {

	char studentNames[3][20];
	char studentMatricNo[3][20];
	//First semeter course
	int CHEMISTRY[3];
	int MATHS1[3];
	int ENGLISH[3];
	int CIVIL[3];
	int C_PROGRAMMING[3];

	//second semeter course Array
	int MECHANICAL[3];
	int PHYSICS[3];
	int WORKSHOP[3];
	int MATHS2[3];
	int JAVA[3];
	int totalPoint[3];
	float gpa[3];
	float cgpa[3];

	char name[20];
	char matricNo[20];
	//first semester
	int cHEMISTRY;
	int mATHS1;
	int eNGLISH;
	int cIVIL;
	int c_PROGRAMMING;

	//second semeter course
	int mECHANICAL;
	int pHYSICS;
	int wORKSHOP;
	int mATHS2;
	int jAVA;


	char ch;

	int courseUnit = 3;
	int totalCourseUnit = 30;
	int i = 0;


	setbuf(stdout,NULL);

	printf("Starting.......\n");
	//Start
	//read from file
	FILE *studentRecord = fopen("StudentRecord.txt","r");

	if(studentRecord == NULL){
		printf("Ooop, StudentRecord.txt NOT FOUND");
		return EXIT_SUCCESS;
	}


	while(fscanf(studentRecord,"%20s %20s %3d %3d %3d %3d %3d %3d %3d %3d %3d %3d ",name,matricNo,&cHEMISTRY,&mATHS1,&eNGLISH,&cIVIL,&c_PROGRAMMING,&mECHANICAL,&pHYSICS,&wORKSHOP,&mATHS2,&jAVA) != EOF){


		strcpy(studentNames[i],name);
		strcpy(studentMatricNo[i],matricNo);
		CHEMISTRY[i] = cHEMISTRY;
		MATHS1[i] = mATHS1;
		ENGLISH[i] = eNGLISH;
		CIVIL[i] = cIVIL;
		C_PROGRAMMING[i] = c_PROGRAMMING;

		MECHANICAL[i] = mECHANICAL;
		PHYSICS[i] = pHYSICS;
		WORKSHOP[i] = wORKSHOP;
		MATHS2[i] = mATHS2;
		JAVA[i] = jAVA;

		totalPoint[i] = ( (getGradePoint(cHEMISTRY) * courseUnit) +
                   (getGradePoint(mATHS1) * courseUnit) +
				(getGradePoint(eNGLISH) * courseUnit) +
                   (getGradePoint(cIVIL) * courseUnit)
				+ (getGradePoint(c_PROGRAMMING) * courseUnit) +
                   (getGradePoint(mECHANICAL) * courseUnit) +
                   (getGradePoint(pHYSICS) * courseUnit) +
				(getGradePoint(wORKSHOP) * courseUnit) +
                   (getGradePoint(mATHS2) * courseUnit)
				+ (getGradePoint(jAVA) * courseUnit));
		 gpa[i] = (totalPoint[i] / totalCourseUnit);
		 cgpa[i] = (totalPoint[i] / totalCourseUnit);
		 i++;


	}

	fclose(studentRecord);

	FILE *StudentCalculatedRecord = fopen("StudentCalculatedRecord.txt","w+");

	fprintf(StudentCalculatedRecord,"S/N \tNAME \tRoll. NO. \CHEMISTRY \MATHS1 \ENGLISH \CIVIL \C_PROGRAMMING \MECHANICAL \PHYSICS \WORKSHOP \MATHS2 \JAVA \tTOTALPOINT \tGPA \tCGPA \n");

	int j;
	for(j = 0; j < 3; j++){

		fprintf(StudentCalculatedRecord,"%d \t%s \t%s \t%3d \t%3d \t%3d \t%3d \t%3d \t%3d \t%3d \t%3d \t%3d \t%3d \t%3d \t\t%.2f \t%.2f\n",
				j+1, studentNames[j],studentMatricNo[j],CHEMISTRY[j],MATHS1[j],ENGLISH[j],CIVIL[j],C_PROGRAMMING[j],
				MECHANICAL[j],PHYSICS[j],WORKSHOP[j],MATHS2[j],JAVA[j],totalPoint[j],gpa[j],cgpa[j]);

	}

	fclose(StudentCalculatedRecord);


	FILE *studentSecondResult2 = fopen("StudentCalculatedRecord.txt","r");

	while((ch = fgetc(studentSecondResult2)) != EOF){
		printf("%c",ch);
	}

	fclose(studentSecondResult2);

	return EXIT_SUCCESS;
}

int getGradePoint(int score){

	if(score >= 70){
		return 5;
	}

	if (score >=60 && score <70){

		return 4;
	}

	 if (score >=50 && score <60){

			return 3;
		}

	 if (score >=45 && score <50){

			return 2;
		}

	 if (score >=39 && score <45){

			return 1;
		}

	 if (score < 39){

			return 0;
		}
	 return 0;
}

