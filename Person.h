#pragma once

class Person {

private:
	static int GLOBAL_ID;
	int points;
    int solved;
	double time;
	int tries;
	int localid;

public:
	Person() : solved(0), time(0), points(0), tries(0), localid(0) {}
	Person(int p, int s, double t, int tr) : solved(s), time(t), points(p), tries(tr), localid(GLOBAL_ID++) {}

	int GetId(){ return localid; }
	int GetSolved(){ return solved; }
	double GetTime(){ return time; }
	int GetPoints(){ return points; }
	int GetTries(){ return tries; }

	bool operator> (Person& temp) {
		if (points > temp.points) return true;
		else if (points == temp.points) {
			if (solved > temp.solved) return true;
			else if (solved == temp.solved) {
				if (time < temp.time) return true;
				else if (time == temp.time) {
					if (tries < temp.tries) return true;
					else if (tries == temp.tries) {
						if (localid > temp.localid) return true;
						else return false;
					}
					else return false;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}

	bool operator< (Person& temp) {
		if (points < temp.points) return true;
		else if (points == temp.points) {
			if (solved < temp.solved) return true;
			else if (solved == temp.solved) {
				if (time > temp.time) return true;
				else if (time == temp.time) {
					if (tries > temp.tries) return true;
					else if (tries == temp.tries) {
						if (localid < temp.localid) return true;
						else return false;
					}
					else return false;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}

	bool operator<= (Person& temp) {
		return *this < temp;
	}
};
int Person::GLOBAL_ID = 0;