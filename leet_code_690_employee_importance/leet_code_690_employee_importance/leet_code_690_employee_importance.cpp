/*
The following is a solution to prompt 690. Employee Importance 
from leetcode.com. The prompt can be found here:
https://leetcode.com/problems/employee-importance/description/
The code requires leetcode.com to operate. No non-default 
assignment operator overload or constructor are provided, and prevents 
assignment from copying the subordinates.
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    std::vector<int> subordinates;
	//no non-default assignment opertor preventing assignment operations.
};

class Solution {
public:
    int getImportance(std::vector<Employee*> employees, int id) {
        if(employees.empty())
            return 0;
		std::unordered_map<int, Employee*> directory;
        for(Employee* employee : employees)
            directory.emplace(employee->id, employee);
        if(directory.find(id) == directory.end())	//we can also substitute with if(!directory.count(id))...
            return 0;
        Employee* root = directory[id];
        int importanceSum = root->importance;
		std::stack<Employee*> nodes;
        nodes.push(root);
        while(!nodes.empty()) {
            Employee* top = nodes.top();
            nodes.pop();
            for(int i = 0; i < top->subordinates.size(); i++) {
                Employee* child = directory[top->subordinates[i]];
                importanceSum += child->importance;
                if(child->subordinates.size() > 0)
                    nodes.push(child);
            }
        }
        return importanceSum;
    }
};


int main()
{
	Solution prompt;
	std::vector<int> eids = { 2, 3 };
	Employee* e1;
	e1->id = 1;
	e1->importance = 5;
	e1->subordinates = eids;
	Employee* e2;
	e2->id = 2;
	e2->importance = 3;
	Employee* e3;
	e3->id = 3;
	e3->importance = 3;
	std::vector<Employee*> employees = { e1, e2, e3 };
	std::cout << prompt.getImportance(employees, 1) << std::endl;
    return 0;
}

