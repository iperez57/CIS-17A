/*
 * File:   GradeActivity.h
 * Author: Isaac Perez
 * Created: 05/22/2026
 * Purpose:  use Grade activity class from this chapter
 */

#ifndef GRADEACTIVITY_H
#define GRADEACTIVITY_H

//GradeActivity class declaration
class GradeActivity
{
protected:
	double score; // To hold the numeric score
public:
	//Default constructor
	GradeActivity()
	{
		score = 0.0;
	}

	//Constructor
	GradeActivity(double s)
	{
		score = s;
	}

	//Mutator function
	void setScore(double s)
	{
		score = s;
	}

	//Accessor functions
	double getScore() const
	{
		return score;
	}

	virtual char getLetterGrade() const
	{
		if (score >= 90)
			return 'A';
		else if (score >= 80)
			return 'B';
		else if (score >= 70)
			return 'C';
		else if (score >= 60)
			return 'D';
		else
			return 'F';
	}
};
#endif