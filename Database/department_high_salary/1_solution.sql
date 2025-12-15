select Department, Employee, Salary
from (
        select
            d.name as Department, e.name as Employee, e.salary as Salary, dense_rank() over (
                partition by
                    d.id
                order by e.salary desc
            ) as d_rank
        from department d
            join employee e on d.id = e.departmentId
    ) temp_table
where
    d_rank = 1