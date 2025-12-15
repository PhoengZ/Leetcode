select distinct
    num as ConsecutiveNums
from (
        select num, lead(num, 1) over (
                order by id
            ) as num1, lead(num, 2) over (
                order by id
            ) as num2
        from logs
    ) temp_table
where
    num = num1
    and num = num2