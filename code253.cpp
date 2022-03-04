#include <bits/stdc++.h>
using namespace std;

class Event
{
public:
    int time;
    bool isEnd;
    Event(int t, bool e) : time(t), isEnd(e)
    {
    }
};

class EventCompare
{
public:
    bool operator()(const Event &e1, const Event &e2)
    {
        if (e1.time == e2.time)
        {
            return e1.isEnd;
        }
        else
            return e1.time < e2.time;
    }
};

class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        vector<Event> events;
        for (int i = 0; i < intervals.size(); i++)
        {
            events.push_back(Event(intervals[i][0], false));
            events.push_back(Event(intervals[i][1], true));
        }
        sort(events.begin(), events.end(), EventCompare());
        int roomCnt = 0;
        int currentRoomCnt = 0;
        for (int i = 0; i < events.size(); i++)
        {
            if (events[i].isEnd)
                currentRoomCnt--;
            else
                currentRoomCnt++;
            roomCnt = max(roomCnt, currentRoomCnt);
        }
        return roomCnt;
    }
};