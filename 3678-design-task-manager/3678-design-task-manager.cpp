#include <bits/stdc++.h>
using namespace std;

class TaskManager {
private:
    map<int,int> task_priority;        // taskId -> priority
    map<int,int> user_task;            // userId -> taskId
    map<int,int> task_user;            // taskId -> userId
    set<pair<int,int>> priority_task;  // {priority, taskId}, auto-sorted ascending

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            add(t[0], t[1], t[2]);  // userId, taskId, priority
        }
    }
    
    void add(int userId, int taskId, int priority) {
        user_task[userId] = taskId;
        task_user[taskId] = userId;
        task_priority[taskId] = priority;
        priority_task.insert({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int oldPr = task_priority[taskId];
        priority_task.erase({oldPr, taskId});
        task_priority[taskId] = newPriority;
        priority_task.insert({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        int pr = task_priority[taskId];
        int user = task_user[taskId];

        priority_task.erase({pr, taskId});
        task_priority.erase(taskId);
        task_user.erase(taskId);
        user_task.erase(user);
    }
    
    int execTop() {
        if (priority_task.empty()) return -1;
        auto it = priority_task.rbegin(); // highest (priority, taskId)
        int taskId = it->second;
        int userId = task_user[taskId];
        rmv(taskId);                     // remove after execution
        return userId;
    }
};
