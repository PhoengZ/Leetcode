select
    d.name as Department,
    t.name as Employee,
    t.salary as Salary
from (
        select
            id, name, salary, departmentId, dense_rank() over (
                partition by
                    departmentId
                order by salary desc
            ) as d_rank
        from employee
    ) t
    join department d on d.id = t.departmentId
where
    t.d_rank <= 3