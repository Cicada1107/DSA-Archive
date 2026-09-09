# Write your MySQL query statement below

SELECT d.name as DEPARTMENT, e.name as Employee, e.salary as Salary
FROM employee e INNER JOIN department d ON e.departmentId = d.id
WHERE (e.departmentId, salary) IN 
(
    SELECT departmentId, MAX(salary)
    FROM employee
    GROUP BY departmentId
);

