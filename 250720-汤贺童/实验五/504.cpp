/*
 * LabWork#504
 * 建立一个对象数组,存放5个学生的学号,成绩,
 * 设立一个函数max,用指向对象的指针作函数参数,
 * 在max函数中找出5个学生的最高成绩者,并输出其学号.
 * 2026.01.07
 */
#include <iostream>

class Student
{
private:
	int id;
	double score;
public:
	Student(int i, double s) : id(i), score(s) {}
	~Student() {}
	void setInfo(int i, double s)
	{
		id = i;
		score = s;
	}
	int getId() const
	{
		return id;
	}
	double getScore() const
	{
		return score;
	}
	static void max(Student* arrS, int size);
};
void Student::max(Student* arrS, int size)
{
	if (size <= 0) return;
	Student* ptrMaxS = &arrS[0];
	for (int i = 1; i < size; ++i)
	{
		if (arrS[i].getScore() > ptrMaxS->getScore())
		{
			ptrMaxS = &arrS[i];
		}
	}
	std::cout << "最高成绩者学号: " << ptrMaxS->getId() << std::endl;
}

int main()
{
	const int SIZE = 5;
	Student students[SIZE] = {
		Student(1, 85.5),
		Student(2, 92.0),
		Student(3, 78.5),
		Student(4, 88.0),
		Student(5, 91.5)
	};
	Student::max(students, SIZE);
	return 0;
}