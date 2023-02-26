// - name:- Harshil Patel ,
// - Seneca student ID:- 148847213,
// - Seneca email:- hpatel292@myseneca.ca
// - date of completion:- 25 Jan, 2023.

#include <iostream>
#include "TimedTask.h"
using namespace std;
namespace sdds
{
    sdds::TimedTask::TimedTask()
    {
        m_numOfRecords = 0;
    }

    void sdds::TimedTask::startClock()
    {
        m_startTime = std::chrono::steady_clock::now();
    }

    void sdds::TimedTask::stopClock()
    {
        m_endTime = std::chrono::steady_clock::now();
    }

    void sdds::TimedTask::addTask(const char* name)
    {
        tasks[m_numOfRecords].unitsOfTime = "nanoseconds";
        tasks[m_numOfRecords].taskName = name;
        tasks[m_numOfRecords].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
        m_numOfRecords++;
    }

    std::ostream& operator<<(std::ostream& ostr, const TimedTask& task)
    {
        ostr << "--------------------------" << endl;
        ostr << "Execution Times:" << endl;
        ostr << "--------------------------"<<endl;
        for (int i = 0; i < task.m_numOfRecords; i++) {
            ostr << " ";
            ostr.width(21);
            ostr.setf(ios::left);
            ostr.unsetf(ios::right);
            ostr << task.tasks[i].taskName;
            ostr.width(13);
            ostr.setf(ios::right);
            ostr.unsetf(ios::left);
            ostr << task.tasks[i].duration.count();
            ostr << " nanoseconds";
            ostr << endl;
        }
 ostr << "--------------------------"<<endl;

        return ostr;
    }
}
