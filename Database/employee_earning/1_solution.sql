select e.name as Employee
from Employee e
where
    e.managerId is not null
    and e.salary > (
        select t.salary
        from Employee t
        where
            e.managerId = t.id
    )