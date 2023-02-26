// - name:- Harshil Patel ,
// - Seneca student ID:- 148847213,
// - Seneca email:- hpatel292@myseneca.ca
// - date of completion:- 25 Jan, 2023.

#ifndef SDDS_TIMEDTASK_H
#define SDDS_TIMEDTASK_H
#include<chrono>
#include<string>
namespace sdds
{
	struct task
	{
		std::string taskName;
		std::string unitsOfTime;
		std::chrono::steady_clock::duration duration;
	};
	class TimedTask
	{
		int m_numOfRecords{};
		std::chrono::steady_clock::time_point m_startTime{};
		std::chrono::steady_clock::time_point m_endTime{};
		task tasks[10]{};
	public:
		TimedTask();
		void startClock();
		void stopClock();
		void addTask(const char* name);
		friend std::ostream& operator<<(std::ostream& ostr, const TimedTask&);
	};
}
#endif

