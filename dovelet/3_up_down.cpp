#include <iostream>
using namespace std;

#define UP		0
#define DOWN	1

class Student
{
private:
	int state;
	int fowardSteps;
	int backwardSteps;
	int stateSteps;
	int currenPosition;
public:
	Student() {}
	~Student() {}
	Student(int fowardSteps, int backwardSteps);
	int move();
	void updateState();
};

Student::Student(int fowardSteps, int backwardSteps)
{
	state = UP;
	this->fowardSteps = fowardSteps;
	this->backwardSteps = backwardSteps;
	stateSteps = 0;
	currenPosition = 0;
}

int Student::move()
{
	if (state == UP) {
		currenPosition++;
		stateSteps++;
	}
	else if (state == DOWN) {
		currenPosition--;
		stateSteps++;
	}
	return currenPosition;
}

void Student::updateState()
{
	if (state == UP) {
		if (stateSteps == fowardSteps) {
			state = DOWN;
			stateSteps = 0;
		}
	}
	else if (this->state == DOWN) {
		if (stateSteps == backwardSteps) {
			state = UP;
			stateSteps = 0;
		}
	}
}

int main()
{
	int a, b, c, d, s, stepsNikky, stepsByron;
	cin >> a >> b >> c >> d >> s;
	Student nikky(a, b), byron(c, d);

	for (int i = 0; i < s; i++) {
		nikky.updateState();
		stepsNikky = nikky.move();
		byron.updateState();
		stepsByron = byron.move();
	}

	if (stepsNikky > stepsByron) cout << "Nikky";
	else if (stepsNikky < stepsByron) cout << "Byron";
	else cout << "Tied";
	return 0;
}