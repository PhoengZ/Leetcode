select
    d.name as Department,
    e.name as Employee,
    e.salary as Salary
from department d
    join employee e on d.id = e.departmentId
where (d.name, e.salary) in (
        select distinct
            d.name as Department,
            max(e.salary) as Salary
        from department d
            join employee e on d.id = e.departmentId
        group by
            d.name
    )