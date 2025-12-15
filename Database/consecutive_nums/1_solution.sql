select distinct
    l.num as ConsecutiveNums
from logs l
where (l.id + 1) in (
        select d.id
        from logs d
        where
            d.num = l.num
    )
    and (l.id + 2) in (
        select d.id
        from logs d
        where
            d.num = l.num
    )