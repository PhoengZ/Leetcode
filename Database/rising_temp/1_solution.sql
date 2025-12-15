select id
from (
        select
            id, recordDate, temperature - lag(temperature, 1) over (
                order by recordDate
            ) as diff, lag(recordDate, 1) over (
                order by recordDate
            ) as prev
        from weather
    ) temp_table
where
    diff > 0
    and recordDate = prev + 1