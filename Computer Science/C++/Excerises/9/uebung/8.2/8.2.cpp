#include <cassert>
#include "transcript.h"

using namespace std;
using namespace module;
using namespace achievement;
using namespace transcript;

int main()
{
	Module m1("PG1", 8);
	Module m2("MA1", 7);
	Module m3("PH", 5);
	Achievement a1(&m1, 2.0);
	Achievement a2(&m2, 2.3);
	Achievement a3(&m3, 1.7);
	Transcript t;
	t.add_achievement(a1);
	t.add_achievement(a2);
	t.add_achievement(a3);
	assert(t.grade_point_average() >= 2.029 && t.grade_point_average() <= 2.031);
	cout << t << endl;
	/*
		PG1 (8 ECTS): 2.0
		MA1 (7 ECTS): 2.3
		PH (5 ECTS): 2.7
		---
		GPA: 2.03
	*/
	return 0;
}
