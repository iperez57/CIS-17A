/*
 * File:   Essay.h
 * Author: Isaac Perez
 * Created: 05/22/2026
 * Purpose:  use Grade activity class from this chapter
 */

#ifndef ESSAY_H
#define ESSAY_H

#include"GradeActivity.h"

 //GradeActivity class declaration
class Essay : public GradeActivity
{
private:
	int grammar;
	int spelling;
	int length;
	int content;

public:
	Essay();
	Essay(int g, int s, int l, int c);

};

Essay::Essay()
{
	grammar = 0;
	spelling = 0;
	length = 0;
	content = 0;

	score = 0;
}

Essay::Essay(int g, int s, int l, int c)
{
	grammar = g;
	spelling = s;
	length = l;
	content = c;

	score = grammar + spelling + length + content;

}
#endif